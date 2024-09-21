#include <bits/stdc++.h> 
#include<vector>
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int j=0;
	for (int i=0; i<n ; i++)
	{
		for (int j=0; j<m;j++)
		{
			if (arr1[i]<arr2[j])
			{
				continue;
			}
			else if (arr1[i]==arr2[j])
			{
				cout << arr1[i] << " " ;
				i++;
			}
		}
	}
}	
int main(){
    vector<int> arr1[3]={1,4,5};
    vector<int> arr2[3]={3,4,5};
    findArrayIntersection(arr1,3,arr2,3);
}