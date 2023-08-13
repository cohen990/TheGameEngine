#include "../src/TGEengine.hpp"
#include "../src/TGEgame.hpp"
#include "../src/Objects/TGEobject.hpp"
#include "../src/Objects/TGEmesh.hpp"
#include "../src/Shaders/TGEbuiltInShaders.hpp"

#include <iostream>
#include <memory>

int main()
{
    boost::optional<TGE::Game> game = TGE::CreateGame();
    if (!game)
    {
        std::cout << "Game failed to initialize. Exiting." << std::endl;
        return -1;
    }
    TGE::Objects::Object object = TGE::Objects::Object();
    game->AddObject(std::make_shared<Object>(object));

    float rightSideUpTriangleVertices[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };
    float upsideDownTriangleVertices [] = {
        1.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
    };


    boost::optional<TGE::Shaders::Shader> redShader = TGE::Shaders::SimpleRedShader();
    if (!redShader)
    {
        std::cout << "failed to load the simple shader. Exiting." << std::endl;
        return -1;
    }
    TGE::Objects::Mesh redTriangle = TGE::Objects::Mesh(rightSideUpTriangleVertices, sizeof(rightSideUpTriangleVertices), &*redShader);
    boost::optional<TGE::Shaders::Shader> blueShader = TGE::Shaders::SimpleBlueShader();
    if (!blueShader)
    {
        std::cout << "failed to load the simple shader. Exiting." << std::endl;
        return -1;
    }
    TGE::Objects::Mesh blueTriangle = TGE::Objects::Mesh(upsideDownTriangleVertices, sizeof(upsideDownTriangleVertices), &*blueShader);
    game->AddObject(std::make_shared<Mesh>(redTriangle));
    game->AddObject(std::make_shared<Mesh>(blueTriangle));
    game->Play();
    game->Destroy();

    TGE::TearDown();
}