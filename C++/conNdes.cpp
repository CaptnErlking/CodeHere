#include<iostream>
using namespace std;
class ConDes{
    public:
    ConDes()
    {
        cout<<"(I am constructed :3)"<<endl;
    }
    ~ConDes()
    {
        cout<<"(I Destructed >_<)";
    }

};
int main()
{
    ConDes meow;
    string name;
    cout<<"What is your name :)"<<endl;
    cin>>name;
    cout<<"I hope you recalled this concept "<<name<<" XD"<<endl;
    return 0;
}   