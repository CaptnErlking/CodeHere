#include<stdio.h>
#include<stdlib.h> // For exit(0)
void disp_matrix(int n,int m,int arr[n][m]);
void row_swap(int n,int m,int arr[n][m],int a,int b);
void coloumn_swap(int n,int m,int arr[n][m],int a,int b);
void matrix_rotator(int n,int m,int arr[n][m],int arrr[m][n]);
int main()
{
    int n,m; // Dimensions
    int a,b; // Operation command
    int z=0; // Ask which operation
    int rot=0; // To count rotations
    printf("Enter the dimension of Matrix: \n");
    scanf("%d%d",&n,&m);
    //n and m are the Row and Coloumn of Matrix Respectively :)
    int arr[n][m],orig[n][m];
    int arrr[m][n]; //declaration of rotated matrix
    printf("Enter the Elements of the Matrix:\n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            printf("Enter A%d%d: ",i+1,j+1);
            scanf("%d",&arr[i][j]);
            orig[i][j]=arr[i][j];
        }
    }
    disp_matrix(n,m,arr);
    while (1) // Wait for exit 0;
    { 
        printf("What Operation you want to perform:\n");
        printf("1. Row Interchange.\n");
        printf("2. Coloumn Interchange.\n");
        printf("3. Re-Enter Matrix.\n");
        printf("4. Reset Matrix.\n");
        printf("5. Rotate Matrix.\n");
        printf("6. End Program.\n\n");
        scanf("%d",&z);
        if (z==5)
            rot++;
        if (z==4 && rot%2==1)
            rot++;
        switch (z){
            case 1: 
                printf("\nEnter which Rows do you want to interchange:\n");
                scanf("%d%d",&a,&b);
                if (a>n || b>m) // Wrong case
                {
                    printf("\nDo you really think that is possible?\n");
                    break;
                }
                if (rot%2==0)
                {
                    row_swap(n,m,arr,a,b);
                    disp_matrix(n,m,arr);
                }
                if (rot%2==1)
                {
                    row_swap(m,n,arrr,a,b);
                    disp_matrix(m,n,arrr);
                }
                break;
            case 2:
                printf("\nEnter which Coloumn do you want to interchange:\n");
                scanf("%d%d",&a,&b); //Wrong case
                if (a>n || b>m)
                {
                    printf("\nDo you really think that is possible?\n");
                    break;
                }
                if (rot%2==0)
                {
                    coloumn_swap(n,m,arr,a,b);
                    disp_matrix(n,m,arr);
                }
                if (rot%2==1)
                {
                    coloumn_swap(m,n,arrr,a,b);
                    disp_matrix(m,n,arrr);
                }
                break;
            case 3:
                main();
                break;
            case 4:
                for (int i=0;i<n;i++)
                {
                    for (int j=0;j<m;j++)
                    {
                        arr[i][j]=orig[i][j]; // Set to last entered Matrix :)
                    }
                }
                disp_matrix(n,m,arr);
                break;
            case 5:
                if (rot%2==1)
                {
                    matrix_rotator(n,m,arr,arrr);
                    disp_matrix(m,n,arrr);
                }
                if (rot%2==0)
                {
                    matrix_rotator(m,n,arrr,arr);
                    disp_matrix(n,m,arr);
                }
                break;
            case 6:
                exit(0); // Needs Explanation?
            default:
                printf("\nEnter a number from '1' - '6'\n");
        }
    }
    return 0;
}
void disp_matrix(int n,int m,int arr[n][m])
{
    printf("\nThe Matrix is :\n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void row_swap(int n,int m,int arr[n][m],int a,int b)
{
    printf("Hi :)\n");
    for (int i=0;i<m;i++)
    {
        int temp=arr[a-1][i];
        arr[a-1][i]=arr[b-1][i];
        arr[b-1][i]=temp;
    }  
}
void coloumn_swap(int n,int m,int arr[n][m],int a,int b)
{
    printf("Hi :)\n");
    for (int i=0;i<n;i++)
    {
        int temp=arr[i][a-1];
        arr[i][a-1]=arr[i][b-1];
        arr[i][b-1]=temp;
    }  
}
void matrix_rotator(int n,int m,int arr[n][m],int arrr[m][n])
{
    int k,l;
    for (int i=0;i<m;i++)
    {
        for (int j=0,k=n-1;j<n;j++,k--)
        {   
            arrr[i][j]=arr[k][i];
        } 
    }
}