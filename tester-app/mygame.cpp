#include "../src/TGEengine.hpp"
#include "../src/TGEgame.hpp"
#include "../src/TGEobject.hpp"

int main() {
    TGE::Game game = TGE::CreateGame();
    TGE::Object object = TGE::Object();
    game.AddObject(object);
    game.Play();
    game.Destroy();

    TGE::TearDown();
}