#include <iostream>
#include <string>
using namespace std;

struct File {
    string name;
    string content;
};

File files[100];
int fileCount = 0;

// Create File
void createFile() {
    string name;

    cout << "Enter file name: ";
    cin >> name;

    // Check duplicate file
    for (int i = 0; i < fileCount; i++) {
        if (files[i].name == name) {
            cout << "Error: File already exists!" << endl;
            return;
        }
    }

    files[fileCount].name = name;

    cout << "Enter file content: ";
    cin.ignore();
    getline(cin, files[fileCount].content);

    fileCount++;

    cout << "File created successfully." << endl;
}

// Read File
void readFile() {
    string name;

    cout << "Enter file name: ";
    cin >> name;

    for (int i = 0; i < fileCount; i++) {
        if (files[i].name == name) {
            cout << "\nFile Name: " << files[i].name << endl;
            cout << "Content: " << files[i].content << endl;
            return;
        }
    }

    cout << "Error: File not found!" << endl;
}

// Delete File
void deleteFile() {
    string name;

    cout << "Enter file name: ";
    cin >> name;

    for (int i = 0; i < fileCount; i++) {
        if (files[i].name == name) {

            for (int j = i; j < fileCount - 1; j++) {
                files[j] = files[j + 1];
            }

            fileCount--;

            cout << "File deleted successfully." << endl;
            return;
        }
    }

    cout << "Error: File not found!" << endl;
}

// Display Files
void displayFiles() {
    if (fileCount == 0) {
        cout << "No files available." << endl;
        return;
    }

    cout << "\nAvailable Files:" << endl;

    for (int i = 0; i < fileCount; i++) {
        cout << i + 1 << ". " << files[i].name << endl;
    }
}

int main() {
    int choice;

    cout << "===== SIMPLE FILE SYSTEM =====" << endl;

    while (true) {

        cout << "\n===== MENU =====" << endl;
        cout << "1. Create File" << endl;
        cout << "2. Read File" << endl;
        cout << "3. Delete File" << endl;
        cout << "4. Display Files" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                createFile();
                break;

            case 2:
                readFile();
                break;

            case 3:
                deleteFile();
                break;

            case 4:
                displayFiles();
                break;

            case 5:
                cout << "Program finished." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}