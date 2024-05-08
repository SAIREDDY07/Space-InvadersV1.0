#pragma once

#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../header/Bullet/BulletModel.h"
#include "../../header/Bullet/BulletView.h"
#include "../../header/Time/TimeService.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Enemy/EnemyController.h"

namespace Bullet {
    class BulletView;
    class BulletModel;
    class PlayerController;
    class EnemyController;
    class BulletController : public Collision::ICollider{
    private:
        std::vector<BulletModel> bullets;
        BulletView* bulletView;
        BulletModel* bulletModel;
        sf::Vector2f spawn_position;
        Time::TimeService* timeService;


    public:
       // BulletController();
        void BulletCollision(ICollider* other_collider);

        void setSpawnPosition(const sf::Vector2f position);
        sf::Vector2f getSpawnPosition()const;
        bool isBulletOutOfBounds(const BulletModel* bullet);
        bool isBulletActive();
        void destroy();
        sf::Vector2f getBulletPosition();

        BulletController(sf::Vector2f SpawnPositon, sf::Vector2f intitialVelocity);
        void initialize();
        void createBullet(const sf::Vector2f& position, const sf::Vector2f& velocity);
        void update();
        void render();
        virtual const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}
