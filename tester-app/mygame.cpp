#include "../src/TGEengine.hpp"
#include "../src/TGEgame.hpp"
#include "../src/Objects/TGEobject.hpp"
#include "../src/Objects/TGEmesh.hpp"
#include "../src/Shaders/TGEbuiltInShaders.hpp"

#include <iostream>

int main()
{
    boost::optional<TGE::Game> game = TGE::CreateGame();
    if (!game)
    {
        std::cout << "Game failed to initialize. Exiting." << std::endl;
        return -1;
    }
    TGE::Objects::Object object = TGE::Objects::Object();
    game->AddObject(object);

    float vertices[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };

    boost::optional<TGE::Shaders::Shader> shader = TGE::Shaders::SimpleShader();
    if (!shader)
    {
        std::cout << "failed to load the simple shader. Exiting." << std::endl;
        return -1;
    }
    TGE::Objects::Mesh mesh = TGE::Objects::Mesh(vertices, sizeof(vertices), &*shader);
    std::cout << "about to play" << std::endl;
    game->AddObject(mesh);
    game->Play();
    game->Destroy();

    TGE::TearDown();
}