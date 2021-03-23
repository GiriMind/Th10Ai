#include "Th10Hook/Scene.h"

#include <cmath>

namespace th
{
	//todo ����������
	bool Scene::IsInScene(const vec2& pos)
	{
		return pos.x >= -192 && pos.x <= 192 && pos.y >= 0 && pos.y <= 448;
	}

	bool Scene::IsInPlayerRegion(const vec2& pos)
	{
		return pos.x >= -184 && pos.x <= 184 && pos.y >= 32 && pos.y <= 432;
	}

	vec2 Scene::FixPlayerPos(const vec2& pos)
	{
		vec2 ret = pos;
		if (ret.x < -184)
			ret.x = -184;
		if (ret.x > 184)
			ret.x = 184;
		if (ret.y < 32)
			ret.y = 32;
		if (ret.y > 432)
			ret.y = 432;
		return ret;
	}

	vec2 Scene::ToWindowPos(const vec2& scenePos)
	{
		return vec2(std::round(scenePos.x + ORIGIN_POINT_OFFSET.x + OFFSET.x),
			std::round(scenePos.y + ORIGIN_POINT_OFFSET.y + OFFSET.y));
	}

	vec2 Scene::ToScenePos(const vec2& windowPos)
	{
		return vec2(windowPos.x - OFFSET.x - ORIGIN_POINT_OFFSET.x,
			windowPos.y - OFFSET.y - ORIGIN_POINT_OFFSET.y);
	}

	Scene::Scene() :
		m_region(0, 224, 384, 448)
	{
	}

	void Scene::split(int_t times)
	{
		m_region.split(times);
	}

	void Scene::clearAll()
	{
		m_region.clearAll();
	}

	void Scene::splitEnemies(const std::vector<Enemy>& enemies)
	{
		m_region.splitEnemies(enemies);
	}

	void Scene::splitBullets(const std::vector<Bullet>& bullets)
	{
		m_region.splitBullets(bullets);
	}

	void Scene::splitLasers(const std::vector<Laser>& lasers)
	{
		m_region.splitLasers(lasers);
	}

	RegionCollideResult Scene::collideAll(const Player& player, float_t frame) const
	{
		return m_region.collideAll(player, frame);
	}
}