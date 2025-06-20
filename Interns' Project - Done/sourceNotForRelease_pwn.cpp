#include <iostream>
#include <unistd.h>
#include <sstream>
#include <fstream>

using namespace std;

// Placeholder functions for choices
void sayHello() {
    cout << "Hi!" << endl;
}

void printFlag() {
    ifstream file("flag.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error: Could not open flag.txt" << endl;
    }
}

void login() {
    string username, password;

    cout << "Enter username: ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);
    cout << "You entered username: " << username << " and password: " << password << endl;
    cout << "However I was just hired and have not learned how to use a database yet...." << endl;
}

void handleOption(){
    int choice[256];
    int n = 0;
    string line;
    int value;

    getline(cin, line);
    istringstream iss(line);

    while (iss >> value && n < 256) {
        if (value >= 1 && value <= 3) {
            choice[n++] = value;
        } else {
            cout << "Ignoring invalid option: " << value << endl;
        }
    }

    if (choice[0] == 2 && geteuid() != 0) {
        cout << "Error: Option 2 requires root privileges HAHA" << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(choice[i] == 1) {
            sayHello();
        }else if(choice[i] == 2){
            printFlag();
        }else if(choice[i] == 3){
            login();
        }
    }
}

int main() {
    cout << "Welcome to our intern's test project!" << endl;
    while(true){
        cout << endl;
        cout << "The following are your options:" << endl;
        cout << "   1. Say hi" << endl;
        cout << "   2. Print the flag" << endl;
        cout << "   3. Create an account" << endl;
        cout << "Enter option (1-3). Press Enter to submit:" << endl;

        handleOption();
    }

    return 0;
}
