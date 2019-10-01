#include "libTH10AI/Common.h"
#include "libTH10AI/Data.h"

#include "libTH10AI/Scene.h"

namespace th
{
	Data::Data(Api& api) :
		m_api(api)
	{
		m_items.reserve(200);
		m_enemies.reserve(200);
		m_bullets.reserve(2000);
		m_lasers.reserve(200);
	}

	void Data::update()
	{
		m_api.readPlayer(m_player);
		m_api.readItems(m_items);
		m_api.readEnemies(m_enemies);
		m_api.readBullets(m_bullets);
		m_api.readLasers(m_lasers);
	}

	void Data::print()
	{
	}

	void Data::checkPrevMove(Direction prevDir, bool prevSlow)
	{
		m_player.checkPrevMove(prevDir, prevSlow);
	}

	bool Data::isRebirthStatus() const
	{
		return m_player.isRebirthStatus();
	}

	bool Data::isNormalStatus() const
	{
		return m_player.isNormalStatus();
	}

	bool Data::isColliding() const
	{
		return m_player.isColliding();
	}

	bool Data::isInvincible() const
	{
		return m_player.isInvincible();
	}

	// ���ҵ���
	ItemTarget Data::findItem()
	{
		ItemTarget target;
		target.valid = false;
		target.item = Item();

		if (m_items.empty())
			return target;

		// ʰȡ��ȴ��
		if (std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::steady_clock::now() - m_findItemTime).count() < 3000)
			return target;

		// �Ի�����1/4��
		if (m_player.y < SCENE_SIZE.height / 4.0f)
		{
			// ������ȴ
			m_findItemTime = std::chrono::steady_clock::now();
			return target;
		}

		// �Ի�����1/2������������10�������˶���5��
		if (m_player.y < SCENE_SIZE.height / 2.0f && m_items.size() < 10 && m_enemies.size() > 5)
		{
			// ������ȴ
			m_findItemTime = std::chrono::steady_clock::now();
			return target;
		}

		float_t minDist = std::numeric_limits<float_t>::max();
		//float_t maxY = std::numeric_limits<float_t>::lowest();
		for (const Item& item : m_items)
		{
			// ���߸���1/5��
			if (item.y < SCENE_SIZE.height / 5.0f)
				continue;

			// ���߲����Ի�1/3����
			float_t dy = std::abs(item.y - m_player.y);
			if (dy > SCENE_SIZE.height / 3.0f)
				continue;

			// ����̫�����л�
			bool tooClose = false;
			for (const Enemy& enemy : m_enemies)
			{
				if (item.calcDistance(enemy.getPosition()) < 100.0f)
				{
					tooClose = true;
					break;
				}
			}
			if (tooClose)
				continue;

			// �������Ի��������
			float_t dist = item.calcDistance(m_player.getPosition());
			if (dist < minDist)
			{
				minDist = dist;
				target.valid = true;
				target.item = item;
			}

			//if (item.y > maxY)
			//{
			//	maxY = item.y;
			//	target.valid = true;
			//	target.item = item;
			//}
		}

		return target;
	}

	bool Data::hasEnemy() const
	{
		return !m_enemies.empty();
	}

	bool Data::isBoss() const
	{
		return m_enemies.size() == 1 && m_enemies[0].isBoss();
	}

	bool Data::isTalking() const
	{
		return (m_enemies.empty() || isBoss()) && m_bullets.empty() && m_lasers.empty();
	}

	bool Data::isUnderEnemy() const
	{
		bool underEnemy = false;

		for (const Enemy& enemy : m_enemies)
		{
			if (std::abs(m_player.x - enemy.x) < 16.0f && m_player.y > enemy.y)
			{
				underEnemy = true;
				break;
			}
		}

		return underEnemy;
	}

	// ���ҵ���
	EnemyTarget Data::findEnemy()
	{
		EnemyTarget target;
		target.valid = false;
		target.enemy = Enemy();

		if (m_enemies.empty())
			return target;

		// �Ի�����1/4��
		if (m_player.y < SCENE_SIZE.height / 4.0f)
			return target;

		float_t minDist = std::numeric_limits<float_t>::max();
		for (const Enemy& enemy : m_enemies)
		{
			if (enemy.y > m_player.y)
				continue;

			// ���Ի�X��������
			float_t dx = std::abs(enemy.x - m_player.x);
			if (dx < minDist)
			{
				minDist = dx;
				target.valid = true;
				target.enemy = enemy;
			}
		}

		return target;
	}

	const Player& Data::getPlayer() const
	{
		return m_player;
	}

	const std::vector<Item>& Data::getItems() const
	{
		return m_items;
	}

	const std::vector<Enemy>& Data::getEnemies() const
	{
		return m_enemies;
	}

	const std::vector<Bullet>& Data::getBullets() const
	{
		return m_bullets;
	}

	const std::vector<Laser>& Data::getLasers() const
	{
		return m_lasers;
	}
}