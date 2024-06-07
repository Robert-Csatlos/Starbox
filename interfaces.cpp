#include <iostream>
#include <fstream>
#include <string>
#include "interfaces.h"
#include "global.h"

void fetchName()
{
    std::string currentUsername;
    std::fstream currentUser;
    currentUser.open("CurrentUser.csv");
    if (isGuest) std::cout << "Current Profile: Guest" << "\n";
    currentUser.close();
}

void Menu(std::string filename, int j) {
    std::fstream _FILE;
    std::string drink_Name;
    int price = 0;

    int i = 0;
    std::string tempWord;
    _FILE.open(filename);
    while (!_FILE.eof()){
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
            price = std::stoi(tempWord);
            std::cout << j << " - " << drink_Name << " (" << price << "B$) \n";
            j++;
        }
        tempWord.clear();
        i++;
    }
}


void interfaceWelcome()
{
    system("CLS");
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||            WELCOME TO            ||\n"
        "||             STARBOX++            ||\n"
        "||                                  ||\n"
        "||----------------------------------||\n"
        "||                                  ||\n"
        "||   Choose an option:              ||\n"
        "||   1) LOGIN                       ||\n"
        "||   2) SIGN UP                     ||\n"
        "||   3) CONTINUE AS GUEST           ||\n"
        "||                                  ||\n"
        "======================================\n";
}

void interfaceLogin()
{
    system("CLS");
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||              LOGIN               ||\n"
        "||                                  ||\n"
        "======================================\n";
}

void interfaceSignUp()
{
    system("CLS");
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||             SIGN UP              ||\n"
        "||                                  ||\n"
        "======================================\n";
}

void interfaceGuest()
{
    system("CLS");
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||              GUEST               ||\n"
        "||                                  ||\n"
        "======================================\n";
}

void interfaceMainMenu()
{
    system("CLS");
    fetchName();
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||   Choose what you                ||\n"
        "||   are looking for:               ||\n"
        "||                                  ||\n"
        "||   1) FOOD                        ||\n"
        "||   2) DRINKS                      ||\n"
        "||   3) Log off                     ||\n";
    
    if (boughtSomething) std::cout <<
        "||   4) Confirm Order               ||\n";

    std::cout <<
        "||                                  ||\n"
        "======================================\n";
}

void interfaceSignUpSuccess()
{
    system("CLS");
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||   ACCOUNT CREATED SUCCESSFULLY   ||\n"
        "||                                  ||\n"
        "======================================\n";
}

void interfaceLogInSuccess()
{
    system("CLS");
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||      LOGGED IN SUCCESSFULLY      ||\n"
        "||                                  ||\n"
        "======================================\n";
}

void interfaceFoodMenu()
{
    system("CLS");
    fetchName();
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||            FOOD MENU             ||\n"
        "||                                  ||\n"
        "======================================\n";
    std::cout << "0 - Return\n\n";
    Menu("Foods.csv", 1);
}

void interfaceDrinkMenu()
{
    system("CLS");
    fetchName();
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||           DRINK MENU             ||\n"
        "||                                  ||\n"
        "======================================\n";
}

void interfaceSoftDrinks()
{
    system("CLS");
    fetchName();
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||           SOFT DRINKS            ||\n"
        "||                                  ||\n"
        "======================================\n";
    std::cout << "0 - Return\n\n";
    Menu("SoftDrinks.csv", 1);
}

void interfacePreMadeDrinks()
{
    system("CLS");
    fetchName();
    std::cout << 
        "======================================\n"
        "||                                  ||\n"
        "||         PRE-MADE DRINKS          ||\n"
        "||                                  ||\n"
        "======================================\n";
    std::cout << "0 - Return\n\n";
    Menu("preMadeDrinks.csv", 1);
}

void interfaceCustomDrink()
{
    system("CLS");
    fetchName();
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||         MAKE YOUR DRINK          ||\n"
        "||                                  ||\n"
        "======================================\n";
    std::cout << "0 - Cancel\n";

    switch (index_custom)
    {
    case 1:
        std::cout << "\n";
        Menu("CustomSizes.csv", 1);
        break;
    case 2:
        std::cout << "\n";
        Menu("CustomBase.csv", 1);
        break;
    case 3:
        std::cout << "1 - Next\n\n";
        std::cout << "Choose the type of flavors for the Coffee\n";
        Menu("CustomCoffee.csv", 2);
        break;
    case 4:
        std::cout << "1 - Next\n\n";
        std::cout << "Choose the type of flavors for the Tea\n";
        Menu("CustomTea.csv", 2);
        break;
    case 5:
        std::cout << "1 - Next\n\n";
        std::cout << "Choose the type of flavors for the Milkshake\n";
        Menu("CustomMilkshake.csv", 2);
        break;
    default:
        break;
    }
}

void FetchReceipt(std::string filename) {
    std::fstream _FILE;
    int sum = 0, price = 0, quant = 0;

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

        if (i % 3 == 0) {//numele
            std::cout << "    " << tempWord << "\n";
            sum += (price * quant);
            price = 0;
        }
        if (i % 3 == 1) {//price
            std::cout << "        " << tempWord << "B$  x  ";
            price += std::stoi(tempWord);
        } 
        if (i % 3 == 2) {//quantity
            std::cout << tempWord << "\n\n";
            quant = std::stoi(tempWord);
        }
        tempWord.clear();
        i++;
    }
    std::cout << "            Total: " << sum << "B$\n";
}

void interfaceReceipt()
{
    int a;
    system("CLS");
    fetchName();
    std::cout <<
        "======================================\n"
        "||                                  ||\n"
        "||             RECEIPT              ||\n"
        "||                                  ||\n"
        "======================================\n";

    FetchReceipt("Receipt.csv");
    std::cout << "\n======================================\n";
    std::cin >> a;
    if (a == 0) index = 1;
}