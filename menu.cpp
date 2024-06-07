#include <iostream>
#include <fstream>
#include <string>
#include "global.h"

static int userChoice;
bool customDrink;
std::fstream _RECEIPT;

int Menu(int userInput, std::string filename, int j) {
	std::fstream _FILE;
	std::string drink_Name;
	int price = 0;

	int i = 0;
	std::string tempWord;
	_FILE.open(filename);
	while (!_FILE.eof()) {
		char ch;
		_FILE.get(ch);

		while (ch != ',' && !_FILE.eof()) {
			if (ch != ',') tempWord += ch;
			else {
				_FILE.get(ch);
				break;
			}
			_FILE.get(ch);
		}
		if (i % 2 == 0) drink_Name = tempWord;
		else {
			if (userInput == j)
			{
				price = std::stoi(tempWord);
				std::cout << j << " - " << drink_Name << " (" << price << "B$) \n";
				_RECEIPT.open("Receipt.csv", std::fstream::app | std::fstream::out);
				_RECEIPT << drink_Name << "," << price << ",";
				_RECEIPT.close();
			}
			j++;
		}
		tempWord.clear();
		i++;
	}
	return j-1;
}

void insertQuantity(int quant)
{
	_RECEIPT.open("Receipt.csv", std::fstream::app | std::fstream::out);
	_RECEIPT << quant << ",";
	_RECEIPT.close();
}

void quantityChecker()
{
	int quantity;
	std::cout << "How many drinks of this type do you want?\n";
	std::cin >> quantity;
	_RECEIPT.open("Receipt.csv", std::fstream::app | std::fstream::out);
	_RECEIPT << quantity << ",";
	_RECEIPT.close();
	index = 5;
	boughtSomething = true;
}

void backendWelcome()
{
	userChoice = NULL;
	std::cin >> userChoice;
	switch (userChoice)
	{
	case 1: // Log In
		isGuest = false;
		index = 2;
		break;
	case 2: // Sign Up
		index = 3;
		break;
	case 3: // Log in as guest
		isGuest = true;
		index = 4;
		break;
	default:
		index = 0;
		break;
	}
}

void backendMainMenu()
{
	userChoice = NULL;
	std::cin >> userChoice;
	switch (userChoice)
	{
	case 1: // Food Menu
		index = 8;
		break;
	case 2: // Drinks Drinks
		index = 9;
		break;
	case 3: //Return
		index = 1;
		break;
	case 4:
		if (boughtSomething)
		{
			index = 13;
		}
		break;

	default:
		index = 0;
		break;
	}
}

void backendFoodMenu()
{
	int maxFoods;
	userChoice = NULL;
	std::cin >> userChoice;
	maxFoods = Menu(userChoice, "Foods.csv", 1);
	switch (userChoice)
	{
	case 0: // Return
		index = 5;
		break;

	default:
		if (userChoice > maxFoods) index = 0;
		else quantityChecker();

		break;
	}
}

void backendDrinkMenu()
{
	userChoice = NULL;
	std::cout <<
		"1 - Soft Drinks\n"
		"2 - Pre-Made Drinks\n"
		"3 - Custom Drinks\n"
		"4 - Return\n";
	std::cin >> userChoice;
	switch (userChoice)
	{
	case 1: // Soft Drinks
		index = 10;
		break;
	case 2: // Pre-Made Drinks
		index = 11;
		break;

	case 3: // Custom Drink
		customDrink = true;
		index = 12;
		break;

	case 4: // Return
		index = 5;
		break;

	default:
		index = 0;
		break;
	}
}

void backendSoftDrinksMenu()
{
	int maxSoftDrinks;
	userChoice = NULL;
	std::cin >> userChoice;
	maxSoftDrinks = Menu(userChoice, "SoftDrinks.csv", 1);
	switch (userChoice)
	{
	case 0: // Return
		index = 5;
		break;

	default:
		if (userChoice > maxSoftDrinks) index = 0;
		else quantityChecker();

		break;
	}
}

void backendPreMadeDrinks()
{
	int maxDrinks;
	userChoice = NULL;
	std::cin >> userChoice;
	maxDrinks = Menu(userChoice,"preMadeDrinks.csv", 1);
	switch (userChoice)
	{
	case 0: // Return
		index = 9;
		break;

	default:
		if (userChoice > maxDrinks) index = 0;
		else quantityChecker();

		break;
	}
}

void backendCustomDrinks()
{
	int maxDrinks;
	bool isChoosing = true;
	userChoice = NULL;
	switch (index_custom)
	{
	case 1:
		std::cin >> userChoice;
		maxDrinks = Menu(userChoice, "CustomSizes.csv", 1);
		insertQuantity(1);
		index_custom = 2;
		break;

	case 2:
		std::cin >> userChoice;
		maxDrinks = Menu(userChoice, "CustomBase.csv", 1);
		insertQuantity(1);
		if (userChoice == 1 || userChoice == 2) index_custom = 3;
		else if (userChoice == 3 || userChoice == 4) index_custom = 4;
		else if (userChoice == 5) index_custom = 5;
		break;
	
	case 3:
		while (isChoosing)
		{
			std::cin >> userChoice;
			maxDrinks = Menu(userChoice, "CustomCoffee.csv", 2);
			if (userChoice > 1)insertQuantity(1);
			if (userChoice == 1)
			{
				index_custom = 0;
				isChoosing = false;
			}
		}
		break;
	case 4:
		while (isChoosing)
		{
			std::cin >> userChoice;
			maxDrinks = Menu(userChoice, "CustomTea.csv", 2);
			if (userChoice > 1)insertQuantity(1);
			if (userChoice == 1)
			{
				index_custom = 0;
				isChoosing = false;
			}
		}
		break;
	case 5:
		while (isChoosing)
		{
			std::cin >> userChoice;
			maxDrinks = Menu(userChoice, "CustomMilkshake.csv", 2);
			if (userChoice > 1)insertQuantity(1);
			if (userChoice == 1)
			{
				index_custom = 0;
				isChoosing = false;
			}
		}
		break;
	default:
		index = 5;
		index_custom = 1;
		isChoosing = true;
		boughtSomething = true;
		break;
	}
	switch (userChoice)
	{
	case 0: // Return
		index = 9;
		break;

	default:
		if (userChoice > maxDrinks) index = 0;

		break;
	}
}