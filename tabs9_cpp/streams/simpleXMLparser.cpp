#include <iostream>
#include <sstream>
#include <string>

int main(){
	std::string xml = "<person name =\"Alice\" age=\"30\"/>";
	std::istringstream iss(xml);
	
	char c;
	std::string tag, attrName, attrValue;

	iss >>c; // '<'
	std::getline(iss, tag, ' '); // reads "person"

	std::cout << "Tag: " << tag << std::endl;

	while (iss >> attrName){
		if (attrName.back() == '/' || attrName.back() == '>') break;

	iss >> c; // '='
	iss >> c; // first '"'
	std::getline(iss, attrValue,'"');

	std::cout << "Attribute: " << attrName << " = " << attrValue << std::endl;
	}
}
