#include <iostream>
using namespace std;

#define MAX 20
int board[MAX][MAX];

// Print the solution
void printBoard(int n) {
    static int count = 1;
    cout << "Solution " << count++ << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

// Check if we can place a queen at board[row][col]
bool isSafe(int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Solve the N-Queens problem using backtracking
void solveNQueens(int row, int n) {
    if (row == n) {
        printBoard(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;     // Place queen
            solveNQueens(row + 1, n);
            board[row][col] = 0;     // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Enter N between 1 and " << MAX << endl;
        return 1;
    }

    solveNQueens(0, n);
    return 0;
}
