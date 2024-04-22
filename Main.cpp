#include <iostream>
#include <fstream>
#include <string>
#include<vector>

void Write(std::string& text, std::ostream& ostream) {
	ostream << text;
}

void Write(std::string& text, std::ofstream& ostream) {

	ostream << "file\n";
	ostream << text;
}


void Read(std::string& text, std::ifstream& istream) {

	istream >> text;

}

int main() {
	std::string text = "Hello World!\n";

	std::cout << text;
	Write(text, std::cout);

	std::ofstream output("data.txt", std::ios::app);
	output << text;
	Write(text, output);
	output.close();

	text = "";

	std::ifstream input;
	input.open("data.txt");
	//input >> text;
	std::getline(input, text);
	Read(text, input);
	input.close();
	 
	std::cout << text;

	std::vector

}