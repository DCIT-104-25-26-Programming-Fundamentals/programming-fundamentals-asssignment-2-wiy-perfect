// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>

// using boolean for prime checker function
bool isPrime(int number){
    if (number < 2){
       return false;
    }
    // separate check for even numbers greater than 2 since they can never be primes
    if (number> 2 && number %2 ==0){
        return false;
    }
    // check for only odd numbers
    for (int i=3, i * i <= number, i+=2){
        if (number % i == 0 ){
            return false;
        }
    return true
    }
}

int main(){
    int userNumber;
    std::cout<<"Enter a number: "<<std::endl;
    std::cin>> userNumber;

    if (isPrime(userNumber)){
        std::cout<<userNumber<<" is a prime number."<< std::endl;
    } else{
        std::cout<<userNumber<<" is NOT a prime number."<< std::endl;
    }
    
    return 0
}
