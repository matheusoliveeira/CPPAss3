#include <iostream>
#include <regex>

#include "Rational.h"

int main() {

    // Regex for validation
    regex validInputRegex(R"((-?\d+)|(-?\d+\/-?\d+))"); // Fraction or whole number
    regex validFractionRegex(R"((-?\d+\/-?\d+))"); // Fraction
    regex validWholeNumRegex(R"((-?\d+))"); // Whole number

    bool isRunning = true;
    bool anotherFractionRun = true;

    do {
        string oneArgument;
        bool oneArgumentRun = true;

        // Default constructor
        Rational r1;
        cout << "r1: " << r1 << endl;

        do {
            cout << "\nPlease insert a whole number or press 'Q' to quit: " << endl;
            getline(cin, oneArgument);

            // Check if the user typed 'Q' to quit entering courses
            if (oneArgument == "Q") {
                cout << "Quitting..\n" << endl;
                break;
            }

            if (regex_match(oneArgument, validWholeNumRegex)) {

                int intOneArgument = stoi(oneArgument);

                // One Argument constructor
                Rational r2(intOneArgument);
                cout << "r2: " << r2 << endl;

                oneArgumentRun = false;
            }
        } while(oneArgumentRun);

        string firstInput;
        string secondInput;
        bool twoArgumentRun = true;

        do {
            cout << "\nPlease insert a whole number or press 'Q' to quit: " << endl;
            getline(cin, firstInput);

            // Check if the user typed 'Q' to quit entering courses
            if (firstInput == "Q") {
                cout << "Quitting..\n" << endl;
                break;
            }

            if (regex_match(firstInput, validWholeNumRegex)) {

                cout << "\nPlease insert another whole number: " << endl;
                getline(cin, secondInput);

                if (regex_match(secondInput, validWholeNumRegex)) {

                    // Convert both inputs to integer
                    int fInput = stoi(firstInput);
                    int sInput = stoi(secondInput);

                    // Two Argument constructor
                    Rational r3(fInput, sInput);
                    cout << "r3: " << r3 << endl;

                    twoArgumentRun = false;
                }
            }
        } while(twoArgumentRun);

        string fraction;
        bool stringConstRun = true;

        do {
            cout << "\nPlease insert a fraction or press 'Q' to quit: " << endl;
            getline(cin, fraction);

            // Check if the user typed 'Q' to quit entering courses
            if (fraction == "Q") {
                cout << "Quitting..\n" << endl;
                break;
            }

            if (regex_match(fraction, validFractionRegex)) {

                stringConstRun = false;
            }
        } while(stringConstRun);

        string anotherFraction;
        bool anotherFractionRun = true;

        do {
            // String constructor
            Rational r4(fraction);
            cout << "r4: " << r4 << endl;

            cout << "\nPlease insert another fraction: " << endl;
            getline(cin, anotherFraction);

            if (regex_match(anotherFraction, validFractionRegex)) {

                // String constructor
                Rational r5(anotherFraction);
                cout << "r5: " << r5 << endl;

                 // Overloaded operators
                Rational result1 = r4 + r5;
                cout << "r4 + r5: " << result1 << endl;

                Rational result2 = r4 - r5;
                cout << "r4 - r5: " << result2 << endl;

                Rational result3 = r4 * r5;
                cout << "r4 * r5: " << result3 << endl;

                Rational result4 = r4 / r5;
                cout << "r4 / r5: " << result4 << endl;

                // Comparison operators
                cout << "\nr4 > r5: " << (r4 > r5) << endl;
                cout << "r4 < r5: " << (r4 < r5) << endl;
                cout << "r4 == r5: " << (r4 == r5) << endl;

                anotherFractionRun = false;
            }

        } while(anotherFractionRun);

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
