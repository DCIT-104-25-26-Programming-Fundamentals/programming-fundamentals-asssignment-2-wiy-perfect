// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Operation Functions
double addValues(double num1, double num2) {
    return num1 + num2;
}

double subtractValues(double num1, double num2) {
    return num1 - num2;
}

double multiplyValues(double num1, double num2) {
    return num1 * num2;
}

double divideValues(double num1, double num2) {
    return num1 / num2;
}

int calculateModulus(int num1, int num2) {
    return num1 % num2;
}

double calculatePower(double base, double exponent) {
    return pow(base, exponent);
}

// Helper function to collect input variables
void getTwoInputs(double& first, double& second) {
    cout << "Enter first number : ";
    cin >> first;
    cout << "Enter second number: ";
    cin >> second;
}

int main() {
    int selection = 0;
    double val1 = 0, val2 = 0;

    while (selection != 7) {
        cout << "\n============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> selection;

        // Quit right away without prompting for coordinates
        if (selection == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        cout << fixed << setprecision(2);

        switch (selection) {
            case 1:
                getTwoInputs(val1, val2);
                cout << "Result: " << val1 << " + " << val2 << " = " << addValues(val1, val2) << endl;
                break;
                
            case 2:
                getTwoInputs(val1, val2);
                cout << "Result: " << val1 << " - " << val2 << " = " << subtractValues(val1, val2) << endl;
                break;
                
            case 3:
                getTwoInputs(val1, val2);
                cout << "Result: " << val1 << " * " << val2 << " = " << multiplyValues(val1, val2) << endl;
                break;
                
            case 4:
                getTwoInputs(val1, val2);
                if (val2 == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    cout << "Result: " << val1 << " / " << val2 << " = " << divideValues(val1, val2) << endl;
                }
                break;
                
            case 5:
                getTwoInputs(val1, val2);
                // Modulus rules require integers in C++
                if (static_cast<int>(val2) == 0) {
                    cout << "Error: Cannot divide by zero in modulus." << endl;
                } else {
                    cout << "Result: " << static_cast<int>(val1) << " % " << static_cast<int>(val2) << " = " 
                         << calculateModulus(static_cast<int>(val1), static_cast<int>(val2)) << endl;
                }
                break;
                
            case 6:
                getTwoInputs(val1, val2);
                cout << "Result: " << val1 << " ^ " << val2 << " = " << calculatePower(val1, val2) << endl;
                break;
                
            default:
                cout << "Invalid selection! Please enter a number between 1 and 7." << endl;
                break;
        }
    }

    return 0;
}


