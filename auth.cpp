#include <iostream>
#include <fstream>
#include <string>
#include "global.h"

bool checkUsername(std::string name) {
	std::fstream USERS;
	std::string username;
	
	bool itExists = true;
	int i = 0;

	USERS.open("users.csv");
	while (!USERS.eof()){
		char ch;
		USERS.get(ch);

		while (ch != ',' && !USERS.eof()){
			if (ch != ' ' && ch != ',') username += ch;
			else {
				USERS.get(ch);
				break;
			}
			USERS.get(ch);
		}
		if (i % 2 == 0) {
			if (name.compare(username) == 0){
				itExists = true;
				break;
			}
			else itExists = false;
		}
		username.clear();
		i++;
	}
	USERS.close();
	return itExists;
}

bool checkPassword(std::string name, std::string inputPassword) {
	std::fstream USERS;
	std::string username;

	std::string user;
	std::string password;

	bool fetchedUser = false;

	int i = 0;

	USERS.open("users.csv");
	while (!USERS.eof()) {
		char ch;
		USERS.get(ch);

		while (ch != ',' && !USERS.eof()) {
			if (ch != ' ' && ch != ',') username += ch;
			else {
				USERS.get(ch);
				break;
			}
			USERS.get(ch);
		}
		if (i % 2 == 0)  
			if (name.compare(username) == 0){
				user = username;
				fetchedUser = true;
			}

		if (i % 2 == 1)
			if (inputPassword.compare(username) == 0 && fetchedUser == true){
				password = username;
				break;
			}
			else if (fetchedUser == true) break;
		username.clear();
		password.clear();
		i++;
	}
	USERS.close();
	if (user.compare(name) == 0 && password.compare(inputPassword) == 0)
		return 1;
	else return 0;
}

void backendLogin(){
	
	std::string username;
	std::string password;

	bool loggedin = false;

	while (!loggedin){
		std::cout << "\n\nUsername: ";
		std::cin >> username;	
		if (checkUsername(username)){
			std::cout << "\nPassword: ";
			std::cin >> password;
			if (checkPassword(username, password)) {
				loggedin = true;
				break;
			}
			else std::cout << "Wrong Password!\n";
		}
		else std::cout << "Username is not valid";
	}
	if (loggedin)
	{
		std::fstream currentUser;
		remove("CurrentUser.csv");
		currentUser.open("CurrentUser.csv");
		currentUser << username << ",";
		currentUser.close();
		index = 7;
	}
}

void backendSignUp() {
	std::string userInput;
	std::string password;
	std::string confirmPassword;

	bool registered = false;
	bool validUsername = false;

	//Username
	while (!registered)
	{
		if (!validUsername) userInput.clear();
		password.clear();
		confirmPassword.clear();
		if (!validUsername){
			std::cout << "Username\n";
			std::cin >> userInput;
		}
		if (checkUsername(userInput) == 0) {
			validUsername = true;
			std::cout << "Username is Valid\n" << "\nInsert Password:\n";
			std::cin >> password;
			std::cout << "\nConfirm Password:\n";
			std::cin >> confirmPassword;
			if (password.compare(confirmPassword) == 0){
				registered = true;
				break;
			}
			else std::cout << "Password does not match\n\n";
		}
		else std::cout << "Username is Taken\n\n";
	}
	if (registered){	
		std::fstream USERS;
		USERS.open("users.csv", std::fstream::app | std::fstream::out);
		USERS << userInput << "," << password << ",";
		index = 6;
	}
}