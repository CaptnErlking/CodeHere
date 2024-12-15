//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.size();
        if (str[n-1]==0) return str; 
        else if (str[n-1]<5 && str[n-1]>0){
            str[n-1]=0; 
            int it = n-2; 
            while (str[it]==0 && it>=0)
                str[it--]=9;
            str[it]--;
        }
        else {
            str[n-1]=0; 
            int it = n-2; 
            while (str[it]==9 && it>=0)
                str[it--]=0;
            str[it]++;
        }
        return str; 
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends