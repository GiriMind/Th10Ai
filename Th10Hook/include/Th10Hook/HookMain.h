#pragma once

#include "Th10Hook/Common.h"

#include <memory>
#include <boost/interprocess/managed_windows_shared_memory.hpp>

#include "Th10Hook/SharedData.h"
#include "Th10Hook/WindowHook.h"
#include "Th10Hook/DirectX/D3D9Hook.h"
#include "Th10Hook/DirectX/DI8Hook.h"
#include "Th10Hook/Th10Hook.h"

namespace th
{
	namespace interprocess = boost::interprocess;

	class HookMain :
		public WindowListener,
		public D3D9Listener,
		public DI8Listener,
		public Th10Listener
	{
	public:
		HookMain();
		~HookMain();

		void run();

	private:
		virtual void onHook() override;
		virtual void onUnhook() override;
		virtual void onDestroy() override;
		virtual void onPresent(IDirect3DDevice9* device, const RECT* sourceRect, const RECT* destRect,
			HWND destWindowOverride, const RGNDATA* dirtyRegion) override;
		virtual void onGetDeviceStateA(IDirectInputDevice8A* device, DWORD size, LPVOID data) override;

		interprocess::managed_windows_shared_memory m_sharedMemory;
		SharedData* m_sharedData;
		std::unique_ptr<D3D9Hook> m_d3d9Hook;
		std::unique_ptr<DI8Hook> m_di8Hook;
		std::unique_ptr<Th10Hook> m_th10Hook;
	};
}
