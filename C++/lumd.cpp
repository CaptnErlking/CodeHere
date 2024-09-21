#include<iostream>
using namespace std;
class Dexuality {
public:
    string dex;
    void printname()
    {
        cout<<"Your Dexuality is : "<<dex;
    }
};
int main()
{
    Dexuality DEX;
    cout<< "What is your Dexuality: ";
    cin >> DEX.dex;
    DEX.printname();
    return 0;
}