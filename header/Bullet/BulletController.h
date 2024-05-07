#pragma once

#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../header/Bullet/BulletModel.h"
#include "../../header/Bullet/BulletView.h"
#include "../../header/Time/TimeService.h"
#include "../../header/Global/ServiceLocator.h"

namespace Bullet {
    class BulletView;
    class BulletModel;
    class BulletController {
    private:
        std::vector<BulletModel> bullets;
        BulletView* bulletView;
        sf::Vector2f spawn_position;
        Time::TimeService* timeService;

    public:
        BulletController();
        //getBullentController();
        void setSpawnPosition(const sf::Vector2f position);
        sf::Vector2f getSpawnPosition()const;
        void initialize();
        void createBullet(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Sprite& sprite);
        void update();
        void render();
    };
}
