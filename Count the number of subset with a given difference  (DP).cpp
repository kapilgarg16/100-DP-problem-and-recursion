
		/* Given a array, your task is to divide the array into 2 parts  a1  and a2..and count pair of a1 and a2 
		which absolute diff. is equal to given difference 
		 
		i/p -> 		n=  4
			 	a[] = {1, 1, 2, 3}
			 	diff = 1
			 	
		o/p ->           3
		
		
		explain ->          a1       a2
			    (a).  (1, 1, 2) , (3)
			    (b).  (1, 3)   , (1, 2)
			    (c).  (1, 3)   , (1, 2)*/
			    
//-------------------------------------------------------------------------
		
#include<iostream>
using namespace std;
int main()
{
	int w[1000],n,diff,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>w[i];
	sum+=w[i];
	}
	cin>>diff;
	int W=(diff+sum)/2;
	int dp[n+1][W+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(i==0&&j==0)
			dp[i][j]=1;
			else if(i==0)
			dp[i][j]=0;
			else if(j==0)
			dp[i][j]=1;
			else if(w[i-1]<=j)
			dp[i][j]=dp[i-1][j-w[i-1]] +dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j];	
		}
	}
	cout<<dp[n][W];
}
