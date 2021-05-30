#pragma once

#include "Th10Ai/Common.h"

namespace th
{
	struct PlayerRaw
	{
		byte_t unknown0[0x3C0];
		float32_t x;				// 0x3C0
		float32_t y;				// 0x3C4
		byte_t unknown1[0x28];
		int32_t dx;					// 0x3F0
		int32_t dy;					// 0x3F4
		byte_t unknown2[0x24];
		float32_t width;			// 0x41C
		float32_t height;			// 0x420
		byte_t unknown3[0x34];
		int32_t status;				// 0x458
		byte_t unknown4[0x3EB4];
		int32_t invincibleTime;		// 0x4310
		byte_t unknown5[0x160];
		int32_t slow;				// 0x4474
	};

	static_assert(sizeof(PlayerRaw) == 0x4478, "Size is not correct.");
}
