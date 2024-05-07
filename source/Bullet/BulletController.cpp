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
        timeService = ServiceLocator::getInstance()->getTimeService();
    }

    void BulletController::initialize() {
        
        bulletView->initialize(this);
        
    }
    void BulletController::createBullet(const sf::Vector2f& position, const sf::Vector2f& velocity) {
        BulletModel newBullet(velocity);
        newBullet.setPosition(position);
        bullets.push_back(newBullet);
    }

    void BulletController::update() {
        float deltaTime = timeService->getDeltaTime();
        std::cout << deltaTime << std::endl;
        for (auto& bullet : bullets) {
            bullet.setPosition(bullet.getBulletVelocity()* deltaTime);
            bullet.update(deltaTime);
        }

        // Optionally remove inactive bullets
        bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](BulletModel& bullet) {
            return !bullet.isActive();
            }), bullets.end());
    }

    void BulletController::render() {
        for (const auto& bullet : bullets) {

            bulletView->render(bullet);
        }
    }

    void BulletController::setSpawnPosition(const sf::Vector2f position)
    {
        spawn_position = position;
    }
    sf::Vector2f BulletController::getSpawnPosition() const {
        return spawn_position;
    }
    
}
