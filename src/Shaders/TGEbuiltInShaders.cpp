#include "TGEbuiltInShaders.hpp"
#include "TGEloadShaders.hpp"

#include <boost/optional.hpp>
#include <iostream>

using namespace TGE::Shaders;

boost::optional<Shader> TGE::Shaders::SimpleShader(){
    boost::optional<const unsigned int> programId = LoadShaders("../src/Shaders/ShaderFiles/Simple.vertexshader", "../src/Shaders/ShaderFiles/Simple.fragmentshader");
    if(!programId){
        std::cout << "Failed to load shaders" << std::endl;
        return boost::none;
    }
    return Shader(*programId);
}