#include "../../header/Bullet/BulletService.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Collision/ICollider.h"

namespace Bullet
{
	using namespace Global;
	using namespace Collision;
	
	
	BulletService::BulletService()
	{
		bullet_controller = new BulletController();
	}

	BulletService::~BulletService()
	{
		//ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(bullet_controller));
		delete (bullet_controller);
	}

	void BulletService::initialize()
	{

		bullet_controller->initialize();
		//ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(bullet_controller));
	}

	void BulletService::update()
	{
		bullet_controller->update();
	}

	void BulletService::render()
	{
		bullet_controller->render();
	}
	BulletController* BulletService::getBulletController() {
		return bullet_controller;
	}

	/*void PlayerService::increaseScore(int val)
	{
		player_controller->increaseScore(val);
	}

	void PlayerService::decreaseScore(int val)
	{
		player_controller->decreaseScore(val);
	}

	void PlayerService::increaseEnemiesKilled(int val)
	{
		player_controller->increaseEnemiesKilled(val);
	}

	void PlayerService::enableShield()
	{
		player_controller->enableShield();
	}

	void PlayerService::enableRapidFire()
	{
		player_controller->enableRapidFire();
	}

	void PlayerService::enableTrippleLaser()
	{
		player_controller->enableTrippleLaser();
	}*/

	void BulletService::reset()
	{
		//bullet_controller->reset();
	}
}