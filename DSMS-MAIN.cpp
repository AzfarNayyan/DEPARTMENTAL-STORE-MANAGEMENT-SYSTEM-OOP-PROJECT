#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<string>
#include"DSMS.h"

using namespace std;
using namespace sf;

int main() 
{
	RenderWindow Window(VideoMode(1000, 600), "Departmental Store Management System.");

	DisplayLoadingScreen(Window);      // Loading Screen.

	SoundBuffer buffer;
	Sound sound;
	buffer.loadFromFile("supermario.wav");
	sound.setBuffer(buffer);
	sound.play();
	sound.setVolume(25);
	sound.setLoop(true);
	
BackToMainMenu: int choice = DisplayMainMenu(Window);

	if (choice == 1) // INVENTORY MENU
	{
		int category = 0;
		int choice_3;

	BackToInventoryMenu:	int choice_2 = InventoryMenu(Window, category);

		if (choice_2 == 1) //ADD ITEM
		{
			choice_3 = AddItem(Window, category);
			if (choice_3 == -1) goto BackToInventoryMenu;
		}
		if (choice_2 == 3) //DELETE ITEM
		{
			choice_3 = DeleteItem(Window, category);
			if (choice_3 == -1)  goto BackToInventoryMenu;
		}
		if (choice_2 == 4) //DISPLAY ITEM
		{
			choice_3 = DisplayItems(Window, category);
			if (choice_3 == -1)  goto BackToInventoryMenu;
		}
		if (choice_2 == -1) goto BackToMainMenu;
	}
	if (choice == 2) //CUSTOMER MENU
	{
		Customer* customer = new Customer;
		int choice_3, choice_2, category = 0, choice_4, choice_5;

	BackToCustomerMenu: choice_2 = CustomerMenu(Window, category,*customer);
		if (choice_2 >= 1 && choice_2 <= 7)
		{
			int choice_3 = CustomerDisplay(Window, category,*customer);
			
			if (choice_3 == -1) goto BackToCustomerMenu;
		}
		if (choice_2 == -2)
		{
			choice_4 = confirmCart(Window, *customer);
			if (choice_4 == 69)
			{
				choice_5 = customerBill(Window, *customer);
				if (choice_5 == -1)
				{
					delete customer;
					goto BackToMainMenu;
				}
			}

			if (choice_4 == -1)
			{
				delete customer;
				goto BackToCustomerMenu;
			}
		}
		if (choice_2 == -1)
		{
			goto BackToMainMenu;
		}
	}
	if (choice == 3) //EMPLOYEE MENU
	{
		int choice_3;

	BackToEmployeeMenu: int choice_2 = EmployeeMenu(Window);

		if (choice_2 == 1)
		{
			choice_3 = AddEmployee(Window);
			if (choice_3 == -1) goto BackToEmployeeMenu;
		}
		if (choice_2 == 2)
		{
			choice_3 = DisplayEmployee(Window);
			if (choice_3 == -1) goto BackToEmployeeMenu;
		}
		if (choice_2 == 3)
		{
			choice_3 = DeleteEmployee(Window);
			if (choice_3 == -1)goto BackToEmployeeMenu;
		}
		if (choice_2 == -1)goto BackToMainMenu;
	}

	return 69;
}
