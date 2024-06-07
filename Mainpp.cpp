#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>  
#include "global.h"
#include "interfaces.h"
#include "backend.h"

void WaitForSeconds(int seconds) { Sleep(seconds * 1000); }

void interfaceChanger()
{
    std::fstream currentUser;
    switch (index)
    {
#pragma region 0_ErrorScreen
    case 0:
        system("CLS");
        std::cout << "Error, invalid input";

        currentUser.open("CurrentUser.csv");
        currentUser.clear();
        currentUser.close();
        WaitForSeconds(3);
        index = 1;
        break;
#pragma endregion
#pragma region 1_Welcome
    case 1:
        boughtSomething = false;
        remove("Receipt.csv");
        interfaceWelcome();
        backendWelcome();
        break;
#pragma endregion
#pragma region 2_Login
    case 2: // Login page
        interfaceLogin();
        backendLogin();
        break;
#pragma endregion
#pragma region 3_Sign_Up
    case 3: // Sign Up page
        interfaceSignUp();
        backendSignUp();
        break;
#pragma endregion
#pragma region 4_Guest_Page
    case 4: // Guest page
        interfaceGuest();
        WaitForSeconds(3);
        index = 5;
        break;
#pragma endregion
#pragma region 5_MainMenu
    case 5: // Main Menu Page
        interfaceMainMenu();
        backendMainMenu();
        break;
#pragma endregion
#pragma region 6_SignSuccess
    case 6:
        interfaceSignUpSuccess();
        WaitForSeconds(3);
        index = 1;
        break;
#pragma endregion
#pragma region 7_Log_Success
    case 7:
        interfaceLogInSuccess();
        WaitForSeconds(3);
        index = 5;
        break;
#pragma endregion
#pragma region 8_Food_Menu
    case 8:
        interfaceFoodMenu();
        backendFoodMenu();
        break;
#pragma endregion
#pragma region 9_Drinks_Menu
    case 9:
        interfaceDrinkMenu();
        backendDrinkMenu();
        break;
#pragma endregion
#pragma region 10_Soft_Drink
    case 10:
        interfaceSoftDrinks();
        backendSoftDrinksMenu();
        break;
#pragma endregion
#pragma region 11_Pre-Made
    case 11:
        interfacePreMadeDrinks();
        backendPreMadeDrinks();
        break;
#pragma endregion
#pragma region 12_Custom-Drink
    case 12:
        interfaceCustomDrink();
        backendCustomDrinks();
        break;
#pragma endregion
#pragma region 13_Receipt
    case 13:
        interfaceReceipt();
        break;
#pragma endregion

    default:
        std::cout << "a";
        break;
    }
}

int main()
{
    boughtSomething = false;
    index = 1;
    system("Color 70");
    while (true)
    {
        interfaceChanger();
    }
}