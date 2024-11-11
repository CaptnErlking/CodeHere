#include<iostream>
using namespace std; 
void TrafficLight(int size, char color, string str){
    
}
int main() {
    int n; 
    string str; 
    int size; 
    char color; 
    cin >> n ; // Input for testcases 
    for (int i=0; i<n; i++){
        cin >> size >> color; 
        cin >> str; 
        TrafficLight(size,color,str); 
    }
}