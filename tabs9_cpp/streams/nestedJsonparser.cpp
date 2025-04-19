#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string trim(const std::string& str, const std::string& whitespace = "\t\n\r\""){
	const auto strBegin = str.find_first_not_of(whitespace);
	const auto strEnd = str.find_last_not_of(whitespace);
	return (strBegin == std::string::npos) ? "" : str.substr(strBegin, strEnd- strBegin + 1);
}

int main(){
	std::string json = R"({
		"name": "Alice",
		"age":30,
		"isStudent": false,
		"address": {
			"street": "123 Maple Street:,
			"city": "wonderland"
		},
		"hobbies":n ["reading", "cycling"]
	})";
	
	auto name_pos = json.find("\"name\"");
	auto name_start = json.find(":", name_pos) + 1;
	auto name_end = json.find(",", name_start);
	std::string name = trim(json.substr(name_start, name_end - name_start));
	
	auto age_pos = json.find("\"age\"");
	auto age_start = json.find(":", age_pos) + 1;
	auto age_end = json.find("," , age_start);
	int age = std::stoi(trim(json.substr(age_start, age_end - age_start)));
	
	auto student_pos = json.find("\"isStudent\"");
	auto studen_start = json.find(":", student_pos) + 1;
	auto studen_end = json.find("," , student_start);
	std::string isStudent = trim(json.substr(student_start, student_end - student_start));

	
