#ifndef TGELOADSHADERS_HPP
#define TGELOADSHADERS_HPP

#include <boost/optional.hpp>

namespace TGE::Shaders
{
    boost::optional<const unsigned int> LoadShaders(const char *vertexFilePath, const char *fragmentFilePath);
}

#endif
