#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int secretNumber;
    int guess;

    // Random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    secretNumber = rand() % 100 + 1;

    cout << "===== Number Guessing Game =====" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    // Multiple attempts
    while (true) {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too High! Try again." << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too Low! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed the correct number!" << endl;
            break;
        }
    }

    return 0;
}