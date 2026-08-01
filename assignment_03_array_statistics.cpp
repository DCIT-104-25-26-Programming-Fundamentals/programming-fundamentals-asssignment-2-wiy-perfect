// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>

//functions
int add(std::vector<int> numberList){
    int sum= 0;
    for (int i=0;i <= numberList.size()-1; i++ ){
        sum += numberList[i];
    }
    return sum;
}

double average(std::vector<int> numberLList){
   double mean= (double)add(numberList)/ numberList.size() //forcing double division since add() return an int
   return mean
}

int max(std::vector<int> numberList){
   int maxNum= numberList[0]
   for (i=0; i <= numberList.size()-1; i++){
    if (numberList[i]> maxNum){
        maxNum = numberList[i]
    }
   }
   return maxNum 
}

int min(std::vector <int> numberList){
    int minNumber= numberList[0]
    for (i=0; i<= numberList.size()-1; i++){
        if (numberList[i] < minNumber){
            minNumber= numberList[i]
        }
    }
    return minNUmber
}

int main(){
    int count;
    std::cout<<"how many numbers? "<<std::endl;
    std::cin>>count;

    if (count<=0){
        std::cout<<"Error: You entered an invalid number"<<std::endl;
        return
    }
    //storing user input in a temporary variable and psuhing back to the 'numbers' array
    std::vector<int> numbers= {};
    for(i=0, i<= count-1;i++){
        int temporaryNumber;
        std::cout<<"Enter number"<<i+1<<" :"<<std::endl;
        std::cin>> temporaryNumber;

        numbers.push_back(temporaryNumber);
        if (count[i]<=0){
            std::cout<<"Error: The number you entered is less than 0"<<std::endl;
            return 
        }
    }

    //displaying the results
    std::cout<<"Results: "<<std::endl;
    std::cout<<"Sum:     "<<add(numbers)<<std::endl;
    std::cout<<"Average: "<<average(numbers)<<std::endl;
    std::cout<<"Maximum: "<<max(numbers)<<std::endl;
    std::cout<<"Minimum: "<<min(numbers)<<std::endl;

}