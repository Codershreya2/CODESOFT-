#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 10+1;

    int guess;
    int attempts = 0;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 10." << endl;

    do {
        cout << "Enter your guess:";
        cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            cout << "Too low!" << endl;
        } else if (guess > randomNumber) {
            cout << "Too high!" << endl;
        } else {
            cout << "Congratulations! You guessed the number in" << attempts << " attempts!" << endl;
        }
        } while (guess != randomNumber);
        return 0;
       }
