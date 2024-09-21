#include<iostream>
#include<string.h>
using namespace std;
class test{
    private:
    int lol;
    string expression;
    int *luckynumber;

    public:
    test()
    {
        luckynumber=new int;
    }
    void doit(int hi,string exp,int ln){
        lol=hi;
        expression=exp;
        *luckynumber=ln;
    }
    void prinit(){
        cout << "\nlol number = " << lol 
        << "\nexpression = " << expression 
        << "\nlucky number = " << *luckynumber 
        << endl ;
    }
    test(test& lmeo)
    {
        lol=lmeo.lol;
        expression=lmeo.expression;
        luckynumber=new int;
        *luckynumber=*(lmeo.luckynumber);
    }
    void alter()
    {
        lol++;
    }
    ~test()
    {
        delete luckynumber;
    }
};
int main()
{
    test omg;
    omg.doit(69,"fuckthis",9);
    omg.prinit();

    test omg2=omg;
    omg2.prinit();

    test omg3=omg2;
    omg3.alter();
    omg3.prinit();

    omg2.prinit();
    return 0;
}