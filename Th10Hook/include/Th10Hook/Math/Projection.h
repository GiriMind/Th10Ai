#pragma once

#include "Th10Hook/Common.h"

#include "Th10Hook/Math/BB.h"

namespace th
{
	class Projection
	{
	public:
		Projection();
		Projection(float_t min, float_t max);
		Projection(const BB& bb, const vec2& axis);

		bool overlap(const Projection& other) const;

	private:
		float_t m_min;
		float_t m_max;
	};
}
