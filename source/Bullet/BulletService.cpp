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
			
	}

	BulletService::~BulletService()
	{
		for (auto& bullet_controller : bullet_list) {
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(bullet_controller));
			delete (bullet_controller);
		}
		
	}

	void  BulletService::CreateBullet(const sf::Vector2f& position, const sf::Vector2f& velocity)
	{
		BulletController* new_bullet_controller = new BulletController(position,velocity);
		new_bullet_controller->initialize();
		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(new_bullet_controller));
		bullet_list.push_back(new_bullet_controller);
		
	}

	void BulletService::initialize()
	{

	}

	void BulletService::update()
	{
		for (auto& bullet_controller : bullet_list) {
			bullet_controller->update();
		}
		bullet_list.erase(std::remove_if(bullet_list.begin(), bullet_list.end(),
			[](BulletController* bulletcontroller) {
		  return !bulletcontroller->isBulletActive();
			}), bullet_list.end());
		
	}

	void BulletService::render()
	{
		for (auto& bullet_controller : bullet_list) {
			bullet_controller->render();
		}
	}
	
	void BulletService::destroyBullet(BulletController* bullet_controller) {
		dynamic_cast<ICollider*>(bullet_controller)->disableCollision();
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
	}

	void BulletService::reset()
	{
		//bullet_controller->reset();
	}
}