#pragma once

#include "Th10Hook/Common.h"

namespace th
{
	class MyDetours
	{
	public:
		void transactionBegin();
		void transactionAbort();
		void transactionCommit();

		void updateThread(HANDLE thread);

		void attach(PVOID* pointer, PVOID detour);
		void detach(PVOID* pointer, PVOID detour);
	};
}
