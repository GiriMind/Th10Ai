#pragma once

#include "Th10Ai/Common.h"

#include <boost/interprocess/managed_windows_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>

#include "Th10Ai/Th10Data.h"

namespace th
{
	namespace interprocess = boost::interprocess;

	struct SharedData
	{
		HWND window;

		interprocess::interprocess_mutex hookMutex;
		interprocess::interprocess_condition hookCond;
		bool hooked;

		interprocess::interprocess_mutex unhookMutex;
		interprocess::interprocess_condition unhookCond;
		bool unhooked;

		interprocess::interprocess_mutex updateMutex;
		interprocess::interprocess_condition updateCond;
		bool updated;
		bool exited;

		int64_t updateTime;
		StatusData status;
		ActionData action;
		bool actionUpdated;
	};

	class SharedMemory
	{
	public:
		SharedMemory();
		~SharedMemory();

		void activate();

		bool timedWaitHook(int64_t ms);
		void notifyUnhook();
		bool waitUpdate();

		const StatusData& getStatus() const;
		ActionData& getAction();
		void commit();

	private:
		interprocess::managed_windows_shared_memory m_memory;
		SharedData* m_data;
	};
}