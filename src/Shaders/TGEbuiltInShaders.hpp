#ifndef TGEBUILTINSHADERS_HPP
#define TGEBUILTINSHADERS_HPP

#include "TGEshader.hpp"
#include <boost/optional.hpp>

namespace TGE::Shaders
{
    boost::optional<Shader> SimpleRedShader();
    boost::optional<Shader> SimpleBlueShader();
}

#endif