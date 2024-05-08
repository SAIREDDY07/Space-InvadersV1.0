#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

namespace Bullet {
    class BulletModel {
    private:
        sf::Sprite sprite; // Sprite representing the bullet
        sf::Vector2f velocity; // Velocity of the bullet
        sf::Vector2f bullet_position;
        bool active; // Status of the bullet: true if active, false if inactive

    public:
        // Constructor
        //BulletModel(const sf::Sprite& bulletSprite, const sf::Vector2f& initialVelocity);

        BulletModel(const sf:: Vector2f& bulletposition,const sf::Vector2f& initialVelocity);

        
        void update(float deltaTime);
        void deactivate();
        bool isActive() const;        
        const sf::Sprite& getSprite() const;
        sf::Vector2f getPosition() const;
        void setPosition(const sf::Vector2f& position);
        sf::Vector2f getBulletVelocity();
    };
}
