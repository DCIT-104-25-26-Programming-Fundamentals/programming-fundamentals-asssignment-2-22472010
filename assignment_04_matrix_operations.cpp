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
using namespace std;

const int MAX = 10;

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols, string name) {
    cout << "Enter elements for Matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void transposeMatrix(int src[MAX][MAX], int dest[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rA, int cA, int cB) {
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], Result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    cout << "--- PART A: Transpose Matrix ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    inputMatrix(A, rowsA, colsA, "A");

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(A, rowsA, colsA);

    transposeMatrix(A, Result, rowsA, colsA);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(Result, colsA, rowsA);

    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    cout << "Enter rows and columns for Matrix A and B (e.g. 2 3): ";
    cin >> rowsA >> colsA;

    inputMatrix(A, rowsA, colsA, "A");
    inputMatrix(B, rowsA, colsA, "B");

    addMatrices(A, B, Result, rowsA, colsA);

    cout << "\nSum Matrix (A + B):" << endl;
    printMatrix(Result, rowsA, colsA);

    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    cout << "Enter rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns for Matrix A (and rows for Matrix B): ";
    cin >> colsA;
    rowsB = colsA;
    cout << "Enter columns for Matrix B: ";
    cin >> colsB;

    inputMatrix(A, rowsA, colsA, "A");
    inputMatrix(B, rowsB, colsB, "B");

    multiplyMatrices(A, B, Result, rowsA, colsA, colsB);

    cout << "\nProduct Matrix (A x B):" << endl;
    printMatrix(Result, rowsA, colsB);

    return 0;
}
