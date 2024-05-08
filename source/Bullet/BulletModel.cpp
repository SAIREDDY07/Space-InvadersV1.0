#include "../../header/Bullet/BulletModel.h"
#include <SFML/Graphics.hpp>
#include "../../header/Entity/EntityConfig.h"
#include "../../header/UI/GameplayUI/GameplayUIController.h"

namespace Bullet {

    BulletModel::BulletModel(const sf::Vector2f& bulletposition,const sf::Vector2f& initialVelocity)
        : bullet_position(bulletposition),velocity(initialVelocity), active(true) {}

    void BulletModel::update(float deltaTime) {
        if (active) {
            bullet_position += velocity * deltaTime;
        }
        
    }

    void BulletModel::deactivate() {
        active = false;
    }

    bool BulletModel::isActive() const {
        return active;
    }

    const sf::Sprite& BulletModel::getSprite() const {
        return sprite;
    }

    // Getter for bullet position
    sf::Vector2f BulletModel::getPosition() const {
        return bullet_position;
    }
    sf::Vector2f BulletModel::getBulletVelocity() {
        return velocity;
    }
    // Setter for bullet position
    void BulletModel::setPosition(const sf::Vector2f& position) {
        bullet_position = position;
    }
}
