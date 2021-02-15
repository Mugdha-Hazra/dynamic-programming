// knapsack problem
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int knapsack(int val[],int wt[],int w,int n)
{ 
   int t[n+1][w+1],i,j;
   for(i=0;i<n+1;i++)
   {
   	for(j=0;j<w+1;j++)
   	{
   		if(i==0||j==0)
   		t[i][j]=0;
	   }
   }
/* memset(t,-1,sizeof(t));
	if(w==0||n==0)
	return 0;
	if(t[n][w]!=-1)
	return t[n][w];*/
  for(i=1;i<n+1;i++)
  {
  	for(j=1;j<w+1;j++)
  	{
  		if(wt[i-1]<=j)
  			t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
		else
		    t[i][j]=t[i-1][j];
	  }
  }
  /* else
	{   if(wt[n-1]<=w)
	    {
	    	return t[n][w]=max(val[n-1] + knapsack(val,wt,w-wt[n-1],n-1),knapsack(val,wt,w,n-1));
		}
		else if(wt[n-1] > w)
		{
			return t[n][w]=knapsack(val,wt,w,n-1);
		}
	}*/
	return t[n][w];
}
int main()
{ int n,val[10000],wt[10000],w,i;
	cout<<"\nenter the size of kanpsack\n";
	cin>>w;
	cout<<"\nenter the no of things:\n";
	cin>>n;
	cout<<"\nenter the profit and wt of each element\n";
	for(i=0;i<n;i++)
	{
		cin>>val[i]>>wt[i];
	} cout<<"\ncapacity is:"<<w<<"\nprofit array:\n";
	for(i=0;i<n;i++)
	{
		cout<<val[i]<<"\t";
	} cout<<"\nweight array :\n";
		for(i=0;i<n;i++)
	{
		cout<<wt[i]<<"\t";
	}
	 
	cout<<"\nmax profit!! :"<<knapsack(val,wt,w,n);
	
	return 0;
}



/* output :
enter the size of kanpsack
50
enter the no of things:
3
enter the profit and wt of each element
60 10
100 20
120 30
capacity is:50
profit array:
60      100     120
weight array :
10      20      30
max profit!! :220
--------------------------------
Process exited after 32.53 seconds with return value 0
Press any key to continue . . .
*/
