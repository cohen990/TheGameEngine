#include <string>
#include <ios>
#include <fstream>
#include <sstream>
#include "TGEfiles.hpp"
#include <boost/optional.hpp>

boost::optional<std::string> TGE::IO::ReadFile(const char* filePath){
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);
	if(fileStream.is_open()){
		std::stringstream stringStream;
		stringStream << fileStream.rdbuf();
		content = stringStream.str();
		fileStream.close();
	}else{
		printf("File not found at %s\n", filePath);
		return boost::none;
	}

    return content;
}