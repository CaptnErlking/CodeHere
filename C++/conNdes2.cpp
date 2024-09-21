#include<iostream>
using namespace std;
static int billu=1;
class condes{
    public:
    condes()
    {
        cout << "Number of constructions: " << billu ;
        cout << endl ;
        billu++ ;
    }
    ~condes ()
{
    billu-- ;
    cout << "Number of destructions: " << billu ;
    cout << endl ;
}
};
int main()
{
    condes a,b,c,d;
    return 0;
}