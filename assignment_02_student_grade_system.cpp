// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// =============================================================================
//
// TASK: Student Grade System
//
// Write a C++ program that reads a student's score and outputs the
// corresponding letter grade based on the scale below.
//
// Grading Scale:
//   Score 80 – 100  →  Grade A
//   Score 70 – 79   →  Grade B
//   Score 60 – 69   →  Grade C
//   Score 50 – 59   →  Grade D
//   Score below 50  →  Grade F
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter student score (0-100): 85
//   Grade: A
//
//   Enter student score (0-100): 73
//   Grade: B
//
//   Enter student score (0-100): 45
//   Grade: F
//
//   Enter student score (0-100): 110
//   Error: Score must be between 0 and 100.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST use functions (see scaffold below).
// - Validate the score inside getGrade(). If it is out of range, return '\0'
//   (null character) and let main() print the error message.
// - Use if / else if / else to determine the grade.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>

const char* getGrade(int score){
    if (score < 0 || score > 100){
        return '\0';
    }
    // only numbers between 0 and 100 are checked.
    if (score >= 80) return "A";
    if (score >= 70) return "B";
    if (score >= 60) return "C";
    if (score >= 50) return "D";
    return "F";
}

int main(){
    int user_score;
    std::cout<< "Enter your score(0-100): " << std::endl;
    std::cin>>user_score;
 
    const char* grade = getGrade(user_score);
    // checks if grade contain a 0 memory address
    if (!grade){
        std::cout<<"Error: Score must be between 0 and 100. "<<std::endl; 
    } else {
        //grade is return is memory address is not zero.
        std::cout<< "Grade: "<<grade<<std::endl;
    }
    return 0;
}

