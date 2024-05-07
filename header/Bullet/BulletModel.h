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
        BulletModel(const sf::Sprite& bulletSprite, const sf::Vector2f& initialVelocity);

        // Method to update the bullet's position based on velocity and delta time
        void update(float deltaTime);

        // Method to deactivate the bullet
        void deactivate();

        // Getter for active status
        bool isActive() const;

        // Getter for bullet sprite
        const sf::Sprite& getSprite() const;

        // Getter for bullet position
        sf::Vector2f getPosition() const;

        // Setter for bullet position
        void setPosition(const sf::Vector2f& position);
    };
}
