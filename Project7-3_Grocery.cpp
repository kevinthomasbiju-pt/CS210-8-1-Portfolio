/*
 * Name: Kevin Thomas Biju
 * Course: CS 210
 * Project: Corner Grocer Tracking
 * Date: 23-04-26
 */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// class to handle grocery tracking
class GroceryTracker {
private:
    map<string, int> itemFrequency; // stores item and count

public:

    // read file and count items
    void loadFile() {
        ifstream inFile("CS210_Project_Three_Input_File.txt");
        string item;

        // read each word from file
        while (inFile >> item) {
            itemFrequency[item]++; // count frequency
        }

        inFile.close();

        // create backup file
        ofstream outFile("frequency.dat");

        for (auto it = itemFrequency.begin(); it != itemFrequency.end(); it++) {
            outFile << it->first << " " << it->second << endl;
        }

        outFile.close();
    }

    // search for a specific item
    void searchItem() {
        string item;
        cout << "Enter item to search: ";
        cin >> item;

        if (itemFrequency.find(item) != itemFrequency.end()) {
            cout << item << " was purchased " << itemFrequency[item] << " times\n";
        }
        else {
            cout << item << " was not found\n";
        }
    }

    // print all items with frequency
    void printAll() {
        for (auto it = itemFrequency.begin(); it != itemFrequency.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
    }

    // print histogram
    void printHistogram() {
        for (auto it = itemFrequency.begin(); it != itemFrequency.end(); it++) {
            cout << it->first << " ";

            // print stars
            for (int i = 0; i < it->second; i++) {
                cout << "*";
            }

            cout << endl;
        }
    }
};

// main function
int main() {
    GroceryTracker app;
    int choice = 0;

    app.loadFile(); // load data at start

    // menu loop
    while (choice != 4) {
        cout << "\n===== Corner Grocer Menu =====\n";
        cout << "1. Search Item\n";
        cout << "2. Print All Items\n";
        cout << "3. Print Histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            app.searchItem();
        }
        else if (choice == 2) {
            app.printAll();
        }
        else if (choice == 3) {
            app.printHistogram();
        }
        else if (choice == 4) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice, try again\n";
        }
    }

    return 0;
}
