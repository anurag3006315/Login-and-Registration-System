#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file;
    file.open(username + ".txt");
    file << username << endl << password;
    file.close();

    cout << "Registration successful!" << endl;
}

bool loginUser() {
    string username, password, un, pw;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file;
    file.open(username + ".txt");
    getline(file, un);
    getline(file, pw);

    if (un == username && pw == password) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Login failed. Incorrect username or password." << endl;
        return false;
    }
}

void forgotPassword() {
    string username, un, pw;
    cout << "Enter username: ";
    cin >> username;

    ifstream file;
    file.open(username + ".txt");
    if (file.is_open()) {
        getline(file, un);
        getline(file, pw);
        cout << "Your password is: " << pw << endl;
    } else {
        cout << "Username not found!" << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Register\n2. Login\n3. Forgot Password\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                forgotPassword();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
