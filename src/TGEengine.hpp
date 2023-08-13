#ifndef TGEENGINE_HPP
#define TGEENGINE_HPP

#include "TGEgame.hpp"
#include <boost/optional.hpp>

namespace TGE
{
    boost::optional<Game> CreateGame();
    void TearDown();
}

#endif
