#include "Th10Ai/Entity/Player.h"

namespace th
{
	Player::Player() :
		status(),
		invincibleTime(),
		slow(),
		powers(),
		type(),
		lives(),
		itemObtainRange()
	{
	}

	void Player::setPosition(const vec2& pos0)
	{
		pos = pos0;
		updateAABB();
	}

	void Player::advance(DIR dir, bool slow)
	{
		if (slow)
		{
			vec2 offset = MOVE_SPEED_LOW[to_underlying(dir)];
			pos += offset;
			translate(offset);
		}
		else
		{
			if (isMarisa())
			{
				vec2 offset = MOVE_SPEED_MARISA[to_underlying(dir)];
				pos += offset;
				translate(offset);
			}
			else
			{
				vec2 offset = MOVE_SPEED_HIGH[to_underlying(dir)];
				pos += offset;
				translate(offset);
			}
		}
	}

	bool Player::isRebirthStatus() const
	{
		return status == 0;
	}

	bool Player::isNormalStatus() const
	{
		return status == 1;
	}

	bool Player::isColliding() const
	{
		return status == 4;
	}

	bool Player::isInvincible() const
	{
		return invincibleTime != 0;
	}

	bool Player::isSlow() const
	{
		return slow != 0;
	}

	bool Player::isReimu() const
	{
		return type == 0;
	}

	bool Player::isMarisa() const
	{
		return type == 1;
	}
}