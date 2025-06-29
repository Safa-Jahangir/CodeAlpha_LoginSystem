// user.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

bool registerUser(const string& username, const string& password) {
    ifstream infile("user_data.txt");
    string user, pass;

    // Check for duplicate username
    while (infile >> user >> pass) {
        if (user == username) {
            cout << "Username already exists. Please choose a different one.\n";
            return false;
        }
    }
    infile.close();

    ofstream outfile("user_data.txt", ios::app);
    outfile << username << " " << password << endl;
    cout << "Registration successful!\n";
    return true;
}

bool loginUser(const string& username, const string& password) {
    ifstream infile("user_data.txt");
    string user, pass;
    while (infile >> user >> pass) {
        if (user == username && pass == password) {
            cout << "\nLogin successful! Welcome, " << username << ".\n";
            return true;
        }
    }
    cout << "Login failed. Invalid username or password.\n";
    return false;
}

int main() {
    int choice;
    string username, password;

    do {
		cout << "\n-------------------- \n";
        cout << "--- Login System ---\n";
		cout << "-------------------- \n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
		if (!cin) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Please enter a number.\n";
        continue;
}

        switch (choice) {
            case 1:
                cout << "Enter a username: ";
                cin >> username;
                cout << "Enter a password: ";
                cin >> password;
                registerUser(username, password);
                break;
            case 2:
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;
                loginUser(username, password);
                break;
            case 3:
                cout << "\n:::::Exiting program:::::\n";
				Sleep(2000);
				return 0;
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

	system("pause");
    return 0;
}

