#include <iostream>
#include "StorageUnit.h"
#include "Ladder.h"
#include "Scaffold.h"
//algoritm
/*
1.start the program
2.create two StorageUnit objects
	One to store Ladder Objects
	One to store Scaffold objects
3.Display the Main Menu repeatedly until the user Selects 5 which exist the program 
	option 1: Updating the storage Unit Information
		-Display a submenu:
			-  1 is Ladders
			-  2 is Scaffolds
			-Base on the user input. gather updated information for UnitID, description, dimension, rental date, auto-renewal status, and humidity control status.
			-Update the selected StorageUnit object with the new information.
	option 2: Add Equipment to a Storage Unit
	

	option 3: Remove Equipment from a Storage Unit
		-Display a submenu:
			-  1 is Ladders
			-  2 is Scaffolds
		-remove the equipment from the selected StorageUnit object based on the user input.
	option 4: Print Equipment Inventory
		-Display a submenu:
			-  1 is Ladders
			-  2 is Scaffolds
		-Print the equipment inventory of the selected StorageUnit object based on the user input.
	option 5: Exit Program
4. End the program



*/

using namespace std;
// Function to update storage unit general information
template <typename T>
void updateStorageInfo(StorageUnit<T>& unit);


int main()
{
	StorageUnit <Ladder> landderUnit;
	StorageUnit <Scaffold> ScaffoldUnit;

	int choice{ 0 };
	
	while (choice != 5)
	{
		cout << "Menu Options:" << endl;
		cout << "1. Update Storage Unit General Information" << endl;
		cout << "2. Add Equipment to a Storage Unit" << endl;
		cout << "3. Remove Equipment from a Storage Unit" << endl;
		cout << "4. Print Equipment Inventory" << endl;
		cout << "5. Exit Program" << endl<<endl;
		cout << "selection: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			int unitChoice;
			cout << "\nWhich Storage Unit would you like to update?\n";
			cout << "1. Ladders\n";
			cout << "2. Scaffolds\n";
			cout << "Enter your choice: ";
			cin >> unitChoice;
			//Im so confused with this ?
			if (unitChoice == 1) 
			{
				updateStorageInfo(landderUnit);
			}
			else if (unitChoice == 2) 
			{
				updateStorageInfo(ScaffoldUnit);
			}
			else 
			{
				cout << "Invalid choice. Returning to Main Menu.\n";
			}
			break;
		}
		case 2: {
			int unitChoice;
			cout << "\nWhich Storage Unit would you like to add equipment to?\n";
			cout << "1. Ladders\n";
			cout << "2. Scaffolds\n";
			cout << "Enter your choice: ";
			cin >> unitChoice;

			if (unitChoice == 1) {
				// Add a Ladder
				string ID_number;
				Ladder newLadder;
				Date newdate;
				float height;
				string style;
				int weightLimit;
				cout << "Enter Ladder ID: ";
				while (true) {
					cin >> ID_number;
					if (landderUnit.isDuplicateID(ID_number)) {
						cout << "Error: Duplicate ID. Please enter a different ID: ";
					}
					else {
						break;
					}
				}
				cout << "Enter Ladder Height: ";
				cin >> height;
				cout << "Enter Ladder Style: ";
				cin.ignore();
				getline(cin, style);
				cout << "Enter Ladder Weight Limit: ";
				cin >> weightLimit;
				cout << "Enter date: ";
				cin >> newdate;


				newLadder.setHeight(height);
				newLadder.setStyle(style);
				newLadder.setWeight_limit(weightLimit);
				newLadder.setDatePurched(newdate);

				landderUnit.AddEquipment(newLadder); // Assuming addEquipment is a method in StorageUnit
				cout << "Ladder added successfully!\n";
			}
			else if (unitChoice == 2) {
				// Add a Scaffold
				Scaffold newScaffold;
				float length, width, height;
				int weightLimit;

				cout << "Enter Scaffold Length: ";
				cin >> length;
				cout << "Enter Scaffold Width: ";
				cin >> width;
				cout << "Enter Scaffold Height: ";
				cin >> height;
				cout << "Enter Scaffold Weight Limit: ";
				cin >> weightLimit;

				newScaffold.setLength(length);
				newScaffold.setWidth(width);
				newScaffold.setHeight(height);
				newScaffold.setWeightLimit(weightLimit);

				ScaffoldUnit.AddEquipment(newScaffold); // Assuming addEquipment is a method in StorageUnit
				cout << "Scaffold added successfully!\n";
			}
			else {
				cout << "Invalid choice. Returning to Main Menu.\n";
			}
			break;
		}

		case 3: {
			int unitChoice;
			cout << "\nWhich Storage Unit would you like to remove equipment from?\n";
			cout << "1. Ladders\n";
			cout << "2. Scaffolds\n";
			cout << "Enter your choice: ";
			cin >> unitChoice;

			if (unitChoice == 1) {
				// Remove a Ladder
				string ID_number;
				cout << "Enter the ID of the Ladder to remove: ";
				cin >> ID_number;

				if (landderUnit.removeInventory(ID_number)) { // Assuming RemoveEquipment takes an ID and returns true if successful
					cout << "Ladder removed successfully!\n";
				}
				else {
					cout << "Error: Ladder with the given ID not found.\n";
				}
			}
			else if (unitChoice == 2) {
				// Remove a Scaffold
				string ID_number;
				cout << "Enter the ID of the Scaffold to remove: ";
				cin >> ID_number;

				if (ScaffoldUnit.removeInventory(ID_number)) { // Assuming RemoveEquipment takes an ID and returns true if successful
					cout << "Scaffold removed successfully!\n";
				}
				else {
					cout << "Error: Scaffold with the given ID not found.\n";
				}
			}
			else {
				cout << "Invalid choice. Returning to Main Menu.\n";
			}
			break;
		}
		case 4:
            {
            int unitChoice;
            cout << "\nWhich Storage Unit inventory would you like to print?\n";
            cout << "1. Ladders\n";
            cout << "2. Scaffolds\n";
            cout << "Enter your choice: ";
            cin >> unitChoice;

            if (unitChoice == 1) {
            // Print Ladder inventory
            cout << "\nLadder Inventory:\n";
			landderUnit.printGeneralInfo();
            landderUnit.printInventory();// Assuming PrintInventory is a method in StorageUnit
			
            }
            else if (unitChoice == 2) {
            // Print Scaffold inventory
            cout << "\nScaffold Inventory:\n";
            ScaffoldUnit.printInventory(); // Assuming PrintInventory is a method in StorageUnit
            }
            else {
            cout << "Invalid choice. Returning to Main Menu.\n";
            }
            break;
            }
		case 5:
			cout << "Exiting program..." << endl;
			break;
		}
		system("pause");
		system("CLS");
	}


	return 0;
	system("pause");
}

//Question about the date Object and is it ok to use a template functions 
	template <typename T>
	void updateStorageInfo(StorageUnit<T>&unit) {
		string unitID, description;
		float length, width, height;
		Date rentalDate;
		bool autoRenew, humidityControlled;
		float costperMonth{0.0};

		// Prompt user for input
		cout << "Enter Unit ID: ";
		cin >> unitID;
		cout << "Enter Description: ";
		cin.ignore();
		getline(cin, description);
		cout << "Enter Length: ";
		cin >> length;
		cout << "Enter Width: ";
		cin >> width;
		cout << "Enter Height: ";
		cin >> height;
		cout << "Enter Rental Contract Date (DD/MM/YYYY): ";
		cin >> rentalDate;
		cout << "Enter Cost per Month: ";
		cin >> costperMonth;

		//the date class doesnt work
	
		cout << "Is the contract auto-renewable? (1 for Yes, 0 for No): ";
		cin >> autoRenew;
		cout << "Is the unit humidity-controlled? (1 for Yes, 0 for No): ";
		cin >> humidityControlled;

		// Set values in the StorageUnit object
		unit.setUnitID(unitID);
		unit.setDescription(description);
		unit.setLength(length);
		unit.setWidth(width);
		unit.sethight(height);
		unit.setDate(rentalDate);
		unit.setautoRenew(autoRenew);
		unit.setHumidty(humidityControlled);
		unit.setCostperMonth(costperMonth);
	}
