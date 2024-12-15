#include<iostream>
using namespace std;

int dectobin(int x);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int b = dectobin(n);
    cout << "Here is the Binary representation of that number: " << b << endl;
    return 0;
}

int dectobin(int x) {
    int ans = 0, p = 1; // Initialize p as 1 to handle place value directly
    while (x != 0) {
        int bit = x & 1;
        ans += bit * p;
        p *= 10; // Move to the next place value
        x = x >> 1;
    }
    return ans;
}
