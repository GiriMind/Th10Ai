#pragma once

#include "Th10Hook/Common.h"

#include <thread>
#include <atomic>
#include <Base/Singleton.h>

namespace th
{
	class DllApp :
		public Singleton<DllApp>
	{
	public:
		DllApp();
		virtual ~DllApp() = default;

		void start();
		void join();

		void setSelfExit(bool selfExit);
		bool isSelfExit() const;

	private:
		void mainProc();
		virtual void run() = 0;

		static DWORD WINAPI ExitProc(LPVOID param);

		std::thread m_mainThread;
		std::atomic_bool m_selfExit;
	};
}