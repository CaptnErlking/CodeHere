#include<stdio.h>
int getLargest(int x, int y, int z) {
    return x > y ? (x > z ? x : z ): (y > z ? y : z) ; 
}
int main() {
    int x, y, z; 
    printf("Enter the 3 number : ") ;
    scanf("%d%d%d", &x, &y, &z); 
    printf("The Largest of the three number is : %d\n", getLargest(x,y,z) ); 
}
