#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<int> queens(n, -1);  // queens[i] = column of queen in row i
        backtrack(0, n, queens, results);
        return results;
    }

private:
    void backtrack(int row, int n, vector<int>& queens, vector<vector<string>>& results) {
        if (row == n) {
            results.push_back(generateBoard(queens, n));
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(row, col, queens)) {
                queens[row] = col;
                backtrack(row + 1, n, queens, results);
                queens[row] = -1; // backtrack
            }
        }
    }

    bool isSafe(int row, int col, const vector<int>& queens) {
        for (int i = 0; i < row; ++i) {
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    vector<string> generateBoard(const vector<int>& queens, int n) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            board[i][queens[i]] = 'Q';
        }
        return board;
    }
};

int main() {
    int n;
    cout << "Enter value of n (number of queens): ";
    cin >> n;

    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "{" ; 
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "{ " ; 
        for (int j = 0; j < n; j++) {
            if (j == n - 1) cout << "\"" << solutions[i][j] << "\" " ;
            else cout << "\"" << solutions[i][j] << "\" ," ;
            
        }
        if (i == solutions.size() - 1) cout << "} \n"; 
        else cout << "}, \n"; 
    }
    cout << "}" ; 
    return 0;
}
