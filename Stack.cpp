#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        stack[top] = value;
        cout << "Element pushed successfully." << endl;
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
    } else {
        cout << "Deleted element: " << stack[top] << endl;
        top--;
    }
}

// Display operation
void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements: ";

        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }

        cout << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program finished." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}