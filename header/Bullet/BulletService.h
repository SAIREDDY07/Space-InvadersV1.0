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

		BulletController* getBulletController();
		void initialize();
		void update();
		void render();


		void reset();
	};
}