#include "Th10Hook/Math/OBB.h"

#include "Th10Hook/Laser.h"
#include "Th10Hook/Math/AABB.h"
#include "Th10Hook/Math/Projection.h"

namespace th
{
	OBB::OBB(const Laser& laser)
	{
		update(laser);
	}

	void OBB::update(const Laser& laser)
	{
		float_t radian = laser.getRadian();
		leftTop = laser.pos + (laser.getLeftTop() - laser.pos).rotate(radian);
		rightTop = laser.pos + (laser.getRightTop() - laser.pos).rotate(radian);
		leftBottom = laser.pos + (laser.getLeftBottom() - laser.pos).rotate(radian);
		rightBottom = laser.pos + (laser.getRightBottom() - laser.pos).rotate(radian);
		axisX = vec2(_F(1.0), _F(0.0)).rotate(radian);
		axisY = vec2(_F(0.0), _F(1.0)).rotate(radian);
	}

	bool OBB::collide(const AABB& other) const
	{
		// SAT�����ᶨ��
		if (!Projection(*this, other.axisX).overlap(Projection(other, other.axisX)))
			return false;
		if (!Projection(*this, other.axisY).overlap(Projection(other, other.axisY)))
			return false;
		if (!Projection(*this, axisX).overlap(Projection(other, axisX)))
			return false;
		if (!Projection(*this, axisY).overlap(Projection(other, axisY)))
			return false;
		return true;
	}
}
