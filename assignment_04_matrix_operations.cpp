// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>


void transpose(int sourceMatrix[10][10], int resultMatrix[10][10], int actualRow, int actualCol){
    for(int r=0, r < actualRow; r++){
        for (int c=0; c < actualCol; c++){
            resultMatrix[r][c]= sourceMatrix[c][r]
        }
    }
}

void add(int matrixA[10][10], int matrixB[10][10],int resultMatrix[10][10], int actualRow, int actualCol){
    for (int r= 0; r< actualRow; r++){
        for(int c=0; c< actualCol; c++){
            resultMatrix[r][c]= matrixA[r][c]+matrixB[r][c]
        }
    }
}

void multiply(int matrixA[10][10], int matrixB[10][10],int resultMatrix[10][10], int actualRow, int actualCol){
    for (int r=0; r< actualRow; r++){
        for (int c=0; c< actualCol; c++){
            resultMatrix[r][c]= matrixA[r][c] * matrixB[r][c]
        }
    }
}

int main(){
    // menu for matrix operations
    std::cout<<"===================MATRIX OPERATIONS MENU===================="<<std::endl;
    std::cout<<"What do you want to do?"<<std::endl;
    std::cout<<"1. Add matrices"<<std::endl;
    std::cout<<"2. Transpose Matrix"<<std::endl;
    std::cout<<"3. Multiply matrices"<<std::endl;
    std::cout<<"Enter your choice (1-3) "<<std::endl;
    
    int userChoice;
    std::cin>> userChoice;

    switch (userChoice){
        case 1: { 
            std::cout<<"\n-----------Matrix Addition------------"<<std::endl; 
            int rows, cols;
            do{
               std::cout<<"Enter rows and columns (1-10): "<<std::endl;
               std::cin>>rows>>cols;
               if (rows < 1 || rows > 10 || cols < 1 || cols > 10) {
                    std::cout<< "Invalid dimensions! Please try again."<< std::endl;
               }
            } while (rows < 1 || rows > 10 || cols < 1 || cols > 10);

    
            int matrixA[10][10];
            int matrixB[10][10]; 
            int resultMatrix[10][10];

            std::cout<< "\nEnter values for Matrix A:"<< std::endl;
            for (int r = 0; r < rows; r++) { 
                for (int c = 0; c < cols; c++) {
                    std::cout<< "Matrix A [" << r << "][" << c << "]: "; 
                    std::cin>> matrixA[r][c];
                }
            }

            std::cout<< "\nEnter values for Matrix B:"<< std::endl;
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    std::cout<< "Matrix B [" << r << "][" << c << "]: ";
                    std::cin>> matrixB[r][c];
                }
            }

            
            add(matrixA, matrixB, resultMatrix, rows, cols);

            std::cout << "\nMatrix Sum:"<< std::endl;
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++){
                    std::cout<< resultMatrix[r][c] <<" ";
                }
                std::cout<< std::endl;
            }
            break;
        } 

        case 2: { 
            std::cout<< "\n-------------Matrix Transpose---------------"<<std::endl;

            int rows, cols;
            do{
                std::cout<< "Enter rows and columns(1-10): ";
                std::cin >> rows >> cols;
                if (rows < 1 || rows > 10 || cols < 1 || cols > 10) { // Fixed: logical limits
                    std::cout<< "Invalid dimensions! Please try again." <<std::endl;
                }
            } while (rows < 1 || rows > 10 || cols < 1 || cols > 10 );

            int matrixA[10][10];
            int resultMatrix[10][10];

            std::cout << "\nEnter values for Matrix A:"<< std::endl;
            for (int r = 0; r < rows; r++){ 
                for (int c = 0; c < cols; c++){ 
                   std::cout << "Matrix A [" << r << "][" << c << "]: "; 
                   std::cin >> matrixA[r][c];
                }
            }

            
            transpose(matrixA, resultMatrix, rows, cols);

            std::cout << "\nResulting Transposed Matrix:" << std::endl;
            for (int r = 0; r < cols; r++){ 
               for (int c = 0; c < rows; c++) {
                    std::cout << resultMatrix[r][c] << " ";
                }
                std::cout << std::endl;
            }
            break;
        } // End of Case 2 Scope

        case 3: {
            std::cout << "\n-------------Matrix Multiplication (Coming Soon)---------------" << std::endl;
            break;
        }

        default:
            std::cout << "\nError: Invalid selection! Program terminating."<< std::endl;
            break;
    } 
    return 0;
} 





