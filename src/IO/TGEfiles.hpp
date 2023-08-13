#ifndef TGEFILES_HPP
#define TGEFILES_HPP

#include <string>
#include <boost/optional.hpp>

namespace TGE::IO
{
    boost::optional<std::string> ReadFile(const char* filePath);
}
#endif