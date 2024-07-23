// CShark.cpp
// Author: Kuvrot

#include "CShark.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include <sstream>

unsigned int programCounter = 0;

std::vector<int> data; // this stores the data from variables
std::vector<std::string> id; // this identify the address of the data
std::vector<std::string>commands;

int acumulator;

bool programRunning = false;

std::fstream script;
std::string scriptPath;
std::string line = "";

bool run = false;

int interpreter();
int find(std::string variableName);
bool isNumber(std::string arg);

int main()
{
	//Splash screen
	std::fstream initFile;

	initFile.open("initfile.txt" , std::ios::in);


	if (initFile.is_open()) {
		std::cout << initFile.rdbuf();
	}

	while (!run) {
		interpreter();
	}

	return 0;
}


int interpreter() {

		std::string command = "";

		std::string code = "";

		std::cout << std::endl << "}c_^_> ";
			
		std::getline(std::cin, code);
		
		std::istringstream iss(code);

		while (std::getline(iss, command, ' ')) {
			commands.push_back(command);
		}

		while (programCounter < commands.size()) {

			if (commands[programCounter] == "glup") {
				if (programCounter + 1 < commands.size()) {
					int position = find(commands[programCounter + 1]); //This finds the position of the variable and returns it

					// If the variable does not exist, the method will return -1
					if (position > -1) {
						std::cout << data[position];
					}
					else {
						std::cout << commands[programCounter + 1] << " ";
					}
				}
				else {
					std::cout << "glup need 1 argument";
					break;
				}
			}else if (commands[programCounter] == "bite") {
				if (programCounter + 2 < commands.size()) {
					data.push_back(std::stoi(commands[programCounter + 2]));
					id.push_back(commands[programCounter + 1]);
				}
				else {
					std::cout << "Syntax error on bite function" << std::endl;
					break;
				}
			}
			else if (commands[programCounter] == "sum") {
				if (programCounter + 2 < commands.size()) {
					if (!isNumber(commands[programCounter + 1])) {	
						
						int position = find(commands[programCounter + 1]); //This finds the position of the variable and returns it

						if (position < 0) {
							std::cout << "Syntax error on bite function: " << commands[programCounter + 1] << " symbol does not exist" << std::endl;
							break;
						}

						if (isNumber(commands[programCounter + 2])) {
							data[position] += std::stoi(commands[programCounter + 2]);
						}
						else {
							int secondArgumentPosition = find(commands[programCounter + 2]);

							if (secondArgumentPosition > 0) {
								data[position] += data[secondArgumentPosition];
							}
							else {
								std::cout << "Syntax error on bite function: " << commands[programCounter + 2] << " symbol does not exist" << std::endl;
							}
						}
					}
					else {
						std::cout << "Syntax error on bite function: First argument of sum can not be a number" << std::endl;
						break;
					}
				}
				else {
					std::cout << "Syntax error on bite function: Two arguments are required" << std::endl;
					break;
				}
			}
			else if (commands[programCounter] == "sub") {
				if (programCounter + 2 < commands.size()) {
					if (!isNumber(commands[programCounter + 1])) {

						int position = find(commands[programCounter + 1]); //This finds the position of the variable and returns it

						if (position < 0) {
							std::cout << "Syntax error on bite function: " << commands[programCounter + 1] << " symbol does not exist" << std::endl;
							break;
						}

						if (isNumber(commands[programCounter + 2])) {
							data[position] -= std::stoi(commands[programCounter + 2]);
						}
						else {
							int secondArgumentPosition = find(commands[programCounter + 2]);

							if (secondArgumentPosition > 0) {
								data[position] -= data[secondArgumentPosition];
							}
							else {
								std::cout << "Syntax error on bite function: " << commands[programCounter + 2] << " symbol does not exist" << std::endl;
							}
						}
					}
					else {
						std::cout << "Syntax error on bite function: First argument of sum can not be a number" << std::endl;
						break;
					}
				}
				else {
					std::cout << "Syntax error on bite function: Two arguments are required" << std::endl;
					break;
				}
			}
			else if (commands[programCounter] == "mul") {
				if (programCounter + 2 < commands.size()) {
					if (!isNumber(commands[programCounter + 1])) {

						int position = find(commands[programCounter + 1]); //This finds the position of the variable and returns it

						if (position < 0) {
							std::cout << "Syntax error on bite function: " << commands[programCounter + 1] << " symbol does not exist" << std::endl;
							break;
						}

						if (isNumber(commands[programCounter + 2])) {
							data[position] *= std::stoi(commands[programCounter + 2]);
						}
						else {
							int secondArgumentPosition = find(commands[programCounter + 2]);

							if (secondArgumentPosition > 0) {
								data[position] *= data[secondArgumentPosition];
							}
							else {
								std::cout << "Syntax error on bite function: " << commands[programCounter + 2] << " symbol does not exist" << std::endl;
							}
						}
					}
					else {
						std::cout << "Syntax error on bite function: First argument of sum can not be a number" << std::endl;
						break;
					}
				}
				else {
					std::cout << "Syntax error on bite function: Two arguments are required" << std::endl;
					break;
				}
			}
			else if (commands[programCounter] == "div") {
				if (programCounter + 2 < commands.size()) {
					if (!isNumber(commands[programCounter + 1])) {

						int position = find(commands[programCounter + 1]); //This finds the position of the variable and returns it

						if (position < 0) {
							std::cout << "Syntax error on bite function: " << commands[programCounter + 1] << " symbol does not exist" << std::endl;
							break;
						}

						if (isNumber(commands[programCounter + 2])) {
							data[position] /= std::stoi(commands[programCounter + 2]);
						}
						else {
							int secondArgumentPosition = find(commands[programCounter + 2]);

							if (secondArgumentPosition > 0) {
								data[position] /= data[secondArgumentPosition];
							}
							else {
								std::cout << "Syntax error on bite function: " << commands[programCounter + 2] << " symbol does not exist" << std::endl;
							}
						}
					}
					else {
						std::cout << "Syntax error on bite function: First argument of sum can not be a number" << std::endl;
						break;
					}
				}
				else {
					std::cout << "Syntax error on bite function: Two arguments are required" << std::endl;
					break;
				}
			}
			else if (commands[programCounter] == "mod") {
				if (programCounter + 2 < commands.size()) {
					if (!isNumber(commands[programCounter + 1])) {

						int position = find(commands[programCounter + 1]); //This finds the position of the variable and returns it

						if (position < 0) {
							std::cout << "Syntax error on bite function: " << commands[programCounter + 1] << " symbol does not exist" << std::endl;
							break;
						}

						if (isNumber(commands[programCounter + 2])) {
							data[position] %= std::stoi(commands[programCounter + 2]);
						}
						else {
							int secondArgumentPosition = find(commands[programCounter + 2]);

							if (secondArgumentPosition > 0) {
								data[position] %= data[secondArgumentPosition];
							}
							else {
								std::cout << "Syntax error on bite function: " << commands[programCounter + 2] << " symbol does not exist" << std::endl;
							}
						}
					}
					else {
						std::cout << "Syntax error on bite function: First argument of sum can not be a number" << std::endl;
						break;
					}
				}
				else {
					std::cout << "Syntax error on bite function: Two arguments are required" << std::endl;
					break;
				}
			}
			else if (commands[programCounter] == "splash") {
				system("cls");
			}
			else if (commands[programCounter] == "catch") { //input function
				if (programCounter + 1 >= 0) {

					int position = find(commands[programCounter + 1]); //This finds the position of the variable and returns it

					if (position < 0) {
						std::cout << "Syntax error on bite function: " << commands[programCounter + 1] << " symbol does not exist" << std::endl;
						break;
					}
					else {
						std::cin >> data[position];
					}
				}
				else {
					std::cout << "Syntax error on catch function, no variable to store it was found" << std::endl;
				}
			}
			programCounter++;
		}

	return 0;
}

//Find return the position the variable was found, if not returns -1
int find(std::string variableName) {

	if (id.size() > 0) {
		for (unsigned int i = 0; i < id.size(); i++) {

			if (id[i] == variableName) {
				return i;
			}
		}
	}
	
	return -1;
}

//Checks if the given string is a number by cheking the first character
bool isNumber(std::string arg) {
	
	for (unsigned int i = 0; i < 10; i++) {
		if (i == arg[0] - '0') {
			return true;
		}
	}

	return false;
}
