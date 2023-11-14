#include <iostream>
#include <regex>

#include "Rational.h"

int main() {

    bool isRunning = true;
    regex validInputRegex(R"((-?\d+)|(-?\d+\/-?\d+))"); // Fraction or whole number
    regex validWholeNumRegex(R"((-?\d+))"); // Whole number

    do {
        string firstInput;
        string secondInput;
        bool isFraction;

        while (true) {
            cout << "\nPlease insert a fraction or a whole number or press 'Q' to quit?:" << endl;
            getline(cin, firstInput);

            // Check if the user typed 'Q' to quit entering courses
            if (firstInput == "Q") {
                cout << "Quitting..\n" << endl;
                break;
            }

            if(regex_match(firstInput, validInputRegex)) {

                isFraction = firstInput.find('/') != string::npos;

                if (isFraction) {
                    size_t pos = firstInput.find('/');
                    int numerator = stoi(firstInput.substr(0, pos));
                    int denominator = stoi(firstInput.substr(pos + 1));

                    if (denominator == 0) {
                        cout << "Error: Denominator cannot be zero. Please enter a valid fraction." << endl;
                        continue; // Restart the input loop
                    } else {
                        // Default constructor
                        Rational r1;
                        cout << "r1: " << r1 << endl;

                        // One Argument constructor
                        Rational r2(numerator);
                        cout << "r2: " << r2 << endl;

                        // Two Argument constructor
                        Rational r3(numerator, denominator);
                        cout << "r3: " << r3 << endl;

                        // String constructor
                        Rational r4(firstInput);
                        cout << "r4: " << r4 << endl;

                        // Overloaded operators
                        Rational result1 = r2 + r3;
                        cout << "r2 + r3: " << result1 << endl;

                        Rational result2 = r2 - r3;
                        cout << "r2 - r3: " << result2 << endl;

                        Rational result3 = r2 * r3;
                        cout << "r2 * r3: " << result3 << endl;

                        Rational result4 = r2 / r3;
                        cout << "r2 / r3: " << result4 << endl;

                        // Comparison operators
                        cout << "r2 > r3: " << (r2 > r3) << endl;
                        cout << "r2 < r3: " << (r2 < r3) << endl;
                        cout << "r2 == r3: " << (r2 == r3) << endl;

                        break;
                    }
                } else {
                    while (true) {
                        cout << "Please insert another whole number or press 'Q' to quit?:" << endl;
                        getline(cin, secondInput);

                        if(regex_match(secondInput, validWholeNumRegex)) {
                            // Convert both inputs to integer
                            int fInput = stoi(firstInput);
                            int sInput = stoi(secondInput);

                            // Default constructor
                            Rational r1;
                            cout << "r1: " << r1 << endl;

                            // One Argument constructor
                            Rational r2(fInput);
                            cout << "r2: " << r2 << endl;

                            // Two Argument constructor
                            Rational r3(fInput, sInput);
                            cout << "r3: " << r3 << endl;

                            //TODO
                            // String constructor
                            Rational r4(firstInput);
                            cout << "r4: " << r4 << endl;

                            // Overloaded operators
                            Rational result1 = r2 + r3;
                            cout << "r2 + r3: " << result1 << endl;

                            Rational result2 = r2 - r3;
                            cout << "r2 - r3: " << result2 << endl;

                            Rational result3 = r2 * r3;
                            cout << "r2 * r3: " << result3 << endl;

                            Rational result4 = r2 / r3;
                            cout << "r2 / r3: " << result4 << endl;

                            // Comparison operators
                            cout << "r2 > r3: " << (r2 > r3) << endl;
                            cout << "r2 < r3: " << (r2 < r3) << endl;
                            cout << "r2 == r3: " << (r2 == r3) << endl;

                            break;

                        } else {
                            cout << "Please enter a valid whole number." << endl;
                        }
                    }
                }
            } else {
                cout << "Please enter a valid fraction or whole number." << endl;
            }
        }

        char choice;
        cout << "\nDo you want to enter more numbers? (Y/N): ";
        cin >> choice;
        cin.ignore(); // to clear the newline character from the input buffer

        // Check user's choice to continue or exit the program
        if (toupper(choice) != 'Y') {
            isRunning = false; // Exiting the program loop
        }

    } while(isRunning);

    return 0;
}
