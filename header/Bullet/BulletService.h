#pragma once

namespace Bullet
{
	class BulletController;

	class BulletService
	{
	private:
		BulletController* bullet_controller;

	public:
		BulletService();
		virtual ~BulletService();

		void initialize();
		void update();
		void render();


		void reset();
	};
}