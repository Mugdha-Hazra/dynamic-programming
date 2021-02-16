// Equal Sum Partition Problem(subset sum problem ( 0-1 knapsack problem ) )
/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sumSubset(int a[],int n, int sum)
{
	int t[n+1][sum+1],i,j;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<sum+1;j++)
		{
			if(i==0)
			t[i][j]=0;
			//return 0;
			if(j==0)
			t[i][j]=1;
			//return 1;
		}
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<sum+1;j++)
		{
			if(a[i-1]<=j)
			t[i][j]=max((t[i-1][j-a[i-1]]),(t[i-1][j]));
			else
			t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
}
int main()
{
	int sum=0,n,a[100],i,z=0;
	//cout<<"enter sum value:\n";
	//cin>>sum;
	cout<<"enter the no of element of the array:\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		z+=a[i];
	}
	if(z%2==0)
	(sumSubset(a,n,z/2)?cout<<"Found":cout<<"Not Possible");
	else
	cout<<"not possible!!\n";
	return 0;
}
*/
// subset sum problem
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sumSubset(int a[],int n, int sum)
{
	int t[n+1][sum+1],i,j;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<sum+1;j++)
		{
			if(i==0)  //when sum is some non zero value but we dont have any element in an array.
			t[i][j]=0;
			//return 0;
			if(j==0) // when sum is zero but we have some non zero array.
			t[i][j]=1;
			//return 1;
		}
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<sum+1;j++)
		{
			if(a[i-1]<=j)
			t[i][j]=max((t[i-1][j-a[i-1]]),(t[i-1][j])); // here we have the option either to include the element or to discard it.
			else
			t[i][j]=t[i-1][j]; // when we have an element greater than sum.
		}
	}
	return t[n][sum];
}
int main()
{
	int sum=0,n,a[100],i,z=0;
	//cout<<"enter sum value:\n";
	//cin>>sum;
	cout<<"enter the no of element of the array:\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		z+=a[i];
	}
	if(z%2==0)
	(sumSubset(a,n,z/2)?cout<<"Found":cout<<"Not Possible");
	else
	cout<<"not possible!!\n";
	return 0;
}
