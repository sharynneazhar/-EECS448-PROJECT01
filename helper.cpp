/**
* @author Sharynne Azhar
* @file helper.cpp
* @since 05 October 2016
* @brief File containing helper methods
*/

#include "helper.h"


void printBanner() {
	std::ifstream file("banner.txt");
	std::string lines = "";
	if (file) {
		while (file.good()) {
			std::string eachLine;
			std::getline (file , eachLine);
			eachLine += "\n";
			lines += eachLine;
		}
		std::cout << lines;
	} else {
		std::cout << "Couldn't read file.";
	}
}

void printMenu() {
  std::cout << "\n=============================" << std::endl;
  std::cout << "1) Display the current day" << std::endl;
  std::cout << "2) Display the current week" << std::endl;
  std::cout << "3) Display the current month" << std::endl;
  std::cout << "4) Display the current year" << std::endl;
  std::cout << "5) Create an event" << std::endl;
  std::cout << "6) Remove an event" << std::endl;
  std::cout << "7) Quit" << std::endl;
  std::cout << "=============================" << std::endl;
}
