#include "../../header/Bullet/BulletController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Bullet/BulletView.h"
#include "../../header/Bullet/BulletModel.h"


namespace Bullet {

    BulletController::BulletController() {
        timeService = Global::ServiceLocator::getInstance()->getTimeService();

    }
    void BulletController::initialize() {
        bulletView = new BulletView();
        bulletView->initialize(this);

    }
    void BulletController::createBullet(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Sprite& sprite) {
        BulletModel newBullet(sprite, velocity);
        newBullet.setPosition(position);
        bullets.push_back(newBullet);
    }

    void BulletController::update() {
        float deltaTime = timeService->getDeltaTime();
        for (auto& bullet : bullets) {
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
