#include "Th10Hook/DllLoader.h"

#include <memory>

#include "Th10Hook/DllMain.h"
#include "Th10Hook/DllFree.h"
#include "Th10Hook/HookMain.h"
#include "Th10Hook/WindowHook.h"

namespace th
{
	DllLoader g_dllLoader;

	DllLoader::DllLoader() :
		Singleton(this)
	{
	}

	void DllLoader::start()
	{
		m_thread = boost::thread(&DllLoader::proc, this);
	}

	void DllLoader::join()
	{
		if (m_thread.joinable())
			m_thread.join();
	}

	void DllLoader::proc()
	{
		try
		{
			std::string logPath = Apis::GetModuleDir(g_dll) + "/Th10Hook_%N.log";
			Logger& logger = Logger::GetInstance();
			logger.addFileLog(logPath);

			std::unique_ptr<HookMain> hookMain = std::make_unique<HookMain>();
			hookMain->run();
		}
		catch (...)
		{
			BASE_LOG_ERROR(PrintException());
		}

		WindowHook& windowHook = WindowHook::GetInstance();
		if (!windowHook.isDestroyed())
			DllFree::SelfFree();
	}
}