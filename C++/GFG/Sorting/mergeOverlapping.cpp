#include<iostream>
#include <algorithm>
using namespace std;
typedef struct interval {
    int start;
    int end; 
} interval ;
bool isInterval(interval x, interval y){
    if (x.start < y.start) return isInterval(y,x);
    if (x.start <= y.end) return true; 
    return false; 
}
bool myComp (interval x, interval y){
    return x.start < y.start ; 
}
int main () {
    int n; 
    cin >> n; 
    interval intrvls[n];
    for (int i=0; i<n; i++){
        cin >> intrvls[i].start;
        cin >> intrvls[i].end;
    }
    int sz = sizeof(intrvls)/sizeof(intrvls[0]);
    sort(intrvls,intrvls+sz,myComp);    
    int result = 0;
    for (int i=1; i<n; i++){
        if (intrvls[result].end >= intrvls[i].start) {
            intrvls[result].start = min(intrvls[result].start,intrvls[i].start);
            intrvls[result].end = max(intrvls[result].end,intrvls[i].end);
        }
        else {
            result++;
            intrvls[result] = intrvls[i];
        }
    }
    cout << "\nThe Merged intervals are : " << endl ;
    for (int i=0; i<=result; i++){
        cout << intrvls[i].start << " " << intrvls[i].end << endl ;
    }
    return 0; 
}
