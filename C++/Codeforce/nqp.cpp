#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct node {
    int val;
    node* next;
    node(int x) : val(x), next(nullptr) {}
};

// Binary Tree Node
struct tnode {
    int val;
    tnode* left;
    tnode* right;
    tnode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Typedefs
typedef pair<int,int> pii;
typedef pair<char,int> pci;
typedef pair<int,char> pic;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<char,int>> vpci;
typedef vector<pair<int,char>> vpic;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
typedef queue<char> qc;
typedef stack<int> si;
typedef stack<char> sc;
typedef deque<int> di;
typedef unordered_map<int,int> umii;
typedef map<int,int> mii;
typedef unordered_map<char,int> umci;
typedef map<char,int> mci;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s; 
        cin >> s; 
        int zero = 0, one = 0;
        for (char c : s) {
            if (c == '0') zero++;
            else one++;
        }
        int a = max(zero,   one);
        int b = min(zero, one);
        int forcedPairs = (a - b) / 2;
        a = a - (forcedPairs * 2); 
        if (forcedPairs > k) {
            cout << "NO" << endl;
        } else {
            int remainingPairs = a / 2 + b / 2;
            if ((k - forcedPairs) % 2 != 0) {
                cout << "NO" << endl;
                continue;
            }
            if (remainingPairs >= k - forcedPairs) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }  
    return 0;
}