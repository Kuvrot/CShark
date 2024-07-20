﻿// CShark.cpp
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

		std::cout << std::endl;
		std::cout << "cshark> ";
		std::getline(std::cin, code);
		
		std::istringstream iss(code);

		while (std::getline(iss, command, ' ')) {
			commands.push_back(command);
		}

		while (programCounter < commands.size()) {

			if (commands[programCounter] == "glup") {
				if (programCounter + 1 < commands.size()) {
					try {
						int temp = find(commands[programCounter + 1]);

						if (temp > -1) {
							std::cout << data[temp];
						}
						else {
							std::cout << commands[programCounter + 1];
						}
					}
					catch (int errorNumber) {
						std::cout << "sdsd";
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
						
						int temp = find(commands[programCounter + 1]);

						if (temp < 0) {
							std::cout << "Syntax error on bite function: " << commands[programCounter + 1] << " symbol does not exist" << std::endl;
						}

						if (isNumber(commands[programCounter + 2])) {
							data[temp] += std::stoi(commands[programCounter + 2]);
						}
						else {
							int temp2 = find(commands[programCounter + 2]);

							if (temp2 > 0) {
								data[temp] += data[temp2];
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
