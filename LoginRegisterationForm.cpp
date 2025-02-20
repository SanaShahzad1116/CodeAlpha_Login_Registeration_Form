#include <iostream>  
#include <fstream>  
#include <string>  

using namespace std;

void registerUser() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

   
    ofstream userFile(username + ".txt"); 
    if (userFile.is_open()) {
        userFile << username << endl;
        userFile << password << endl;
        userFile.close();
        cout << "Registration successful!" << endl;
    }
    else {
        cout << "Error creating user file!" << endl;
    }
}

bool loginUser() {
    string username, password, fileUser, filePass;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    
    ifstream userFile(username + ".txt");
    if (userFile.is_open()) {
        getline(userFile, fileUser);
        getline(userFile, filePass);
        userFile.close();

        if (fileUser == username && filePass == password) {
            cout << "Login successful!" << endl;
            return true;
        }
        else {
            cout << "Invalid credentials!" << endl;
            return false;
        }
    }
    else {
        cout << "User does not exist!" << endl;
        return false;
    }
}

int main() {
    int choice;

    do {
        cout << "\n             --- Login and Registration System ----" << endl;
        cout << "             |     1. Register                      |" << endl;
        cout << "             |     2. Login                         |" << endl;
        cout << "             |     3. Exit                          |" << endl;
        cout << "             |______________________________________|" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}