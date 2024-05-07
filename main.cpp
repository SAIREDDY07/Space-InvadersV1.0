#include "../../header/Main/GameService.h"
#include<iostream>

int main()
{
    using namespace Main;

    GameService* game_service = new GameService();
    
    game_service->ignite();
    std::cout << "rendering_ignite" << std::endl;
    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
        std::cout << "rendering" <<std::endl;
    }

    return 0;
}