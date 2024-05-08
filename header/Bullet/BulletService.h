#pragma once
#include<vector>
#include <SFML/System/Vector2.hpp>
namespace Bullet
{
	class BulletController;

	class BulletService
	{
	private:

		std::vector<BulletController*> bullet_list;


	public:
		BulletService();
		virtual ~BulletService();

		void CreateBullet(const sf::Vector2f& position, const sf::Vector2f& velocity);

		void initialize();
		void update();
		void render();

		void destroyBullet(BulletController* bullet_controller);

		//BulletController* getBulletController();
		void reset();
	};
}