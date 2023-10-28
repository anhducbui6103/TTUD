#include <iostream>
#include <unordered_set>
#include <string>

using namespace std; 

int main() {
    unordered_set<string> database;
    string key;

    while (true) {
        cin >> key;
        if (key == "*") {
            break;
        }
        database.insert(key);
    }

    while (true) {
        string command, query;
        cin >> command;

        if (command == "***") {
            break;
        }

        cin >> query;

        if (command == "find") {
            if (database.find(query) != database.end()) {
                cout << "1" << endl;  
            } else {
                cout << "0" << endl;  
            }
        } else if (command == "insert") {
            if (database.find(query) != database.end()) {
                cout << "0" << endl;  
            } else {
                database.insert(query);
                cout << "1" << endl;  
            }
        }
    }

    return 0;
}
