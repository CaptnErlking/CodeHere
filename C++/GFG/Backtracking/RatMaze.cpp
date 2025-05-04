#include<bits/stdc++.h>
using namespace std; 

bool isSafe(int x, int y, vector<vector<int>> &mat, int n, int m) {
    if (x >= 0 && x < m && y >= 0 && y < n) {
        if (mat[x][y] == 1) return true; 
    } 
    return false; 
}

bool solve(int x, int y, vector<vector<int>> &mat, int n, int m, vector<vector<bool>> &ans) {
    if (x == n - 1 && y == m - 1) {
        ans[x][y] = true;
        return true;
    }

    ans[x][y] = true;

    if (isSafe(x + 1, y, mat, n, m)) {
        if (solve(x + 1, y, mat, n, m, ans)) return true;
    }

    if (isSafe(x, y + 1, mat, n, m)) {
        if (solve(x, y + 1, mat, n, m, ans)) return true;
    }

    ans[x][y] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<bool>> ans(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    if (mat[0][0] == 0 || mat[n - 1][m - 1] == 0) {
        cout << "It is not possible" << endl;
        return 0;
    }

    if (solve(0, 0, mat, n, m, ans)) {
        cout << "It is Possible" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "It is not possible" << endl;
    }
}
