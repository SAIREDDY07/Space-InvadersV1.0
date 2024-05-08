#include "../../header/Bullet/BulletController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Bullet/BulletView.h"
#include "../../header/Bullet/BulletModel.h"
#include "../../header/Event/EventService.h"
#include "../../header/Entity/EntityConfig.h"
#include "../../header/Main/GameService.h"


#include <SFML/Graphics.hpp>
#include<iostream>

namespace Bullet {
    using namespace Global;
    using namespace Event;
    using namespace Time;
    using namespace Entity;
    using namespace Enemy;
    using namespace Powerup;
    using namespace Sound;
    using namespace Main;
    using namespace Gameplay;

    BulletController::BulletController() {

        bulletView = new BulletView();
        
    }

    void BulletController::initialize() {

        bulletView->initialize(this);
        timeService = ServiceLocator::getInstance()->getTimeService();

    }

    void BulletController::BulletCollision(ICollider* other_collider)
    {
        /*EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);

        if (enemy_controller)
        {
            PlayerController* player_controller = 
                ServiceLocator::
        }
        */
    }

    

    
    void BulletController::createBullet(const sf::Vector2f& position, const sf::Vector2f& velocity) {
        BulletModel newBullet(velocity);
        newBullet.setPosition(position);
        bullets.push_back(newBullet);
    }

    void BulletController::update() {
        float deltaTime = timeService->getDeltaTime();
        
        for (auto& bullet : bullets) {
   
            bullet.update(deltaTime);
            if (isBulletOutOfBounds(bullet)) bullet.deactivate();
        }

     
        bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](BulletModel& bullet) {
            return !bullet.isActive();
            }), bullets.end());
    }

    void BulletController::render() {
        for (const auto& bullet : bullets) {

            bulletView->render(bullet);
        }
    }

    const sf::Sprite& BulletController::getColliderSprite()
    {
        return bulletView->getBulletSprite();
    }

    void BulletController::onCollision(ICollider* other_collider)
    {
               
    }

    void BulletController::setSpawnPosition(const sf::Vector2f position)
    {
        spawn_position = position;
    }
    sf::Vector2f BulletController::getSpawnPosition() const {
        return spawn_position;
    }

    bool BulletController::isBulletOutOfBounds(const BulletModel& bullet) {

        const float windowWidth = 1920;
        const float windowHeight = 1080;
        const sf::Vector2f& position = bullet.getPosition();

        return (position.x < 0 || position.x > windowWidth || position.y < 0 || position.y > windowHeight);
    }
    
}
