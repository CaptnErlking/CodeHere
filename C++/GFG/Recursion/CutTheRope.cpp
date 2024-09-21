#include<iostream>
using namespace std;
int maxi(int x, int y, int z){
    if (x>=y && x>=z) return x;
    else if (y>=x && y>=z) return y;
    else return z;
}
int CutTheRope(int rope, int a, int b, int c){
    if (rope==0) return 0 ;
    if (rope<0) return -1 ;
    int res = maxi(CutTheRope(rope-a,a,b,c),CutTheRope(rope-b,a,b,c),CutTheRope(rope-c,a,b,c));
    if (res==-1) return -1;
    return res+1;

}
int main() {
    cout << "Enter the length of the rope: " ;
    int rope ; 
    cin >> rope ;
    cout << "Enter the parameters : " << endl ;
    int a,b,c ; 
    cin >> a ; 
    cin >> b ;
    cin >> c ;
    cout << "The numbers of cuts is : " << CutTheRope(rope,a,b,c) ;
}