//minimum subset sum difference
		
		
		/* Given a array, your task is to divide the array into 2 parts  a1  and a2...and the absolute diff. b/w array should be minimum
		
		i/p-   n = 5
		       a[] = {1,2,3,4,5}
		       
		o/p-   1
		 
		explain:;  {1 + 2 + 5}   -  {3 + 4 }   = 1  which is minimum  */
//----------------------------------------------------------------------------------------------------------


//Dynamic Approach
#include<iostream>
using namespace std;
int main()
{
	int n,w[1000],sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>w[i];
	sum+=w[i];
	}
	bool dp[n+1][sum+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0&&j==0)
			dp[i][j]=true;
			else if(i==0)
			dp[i][j]=false;
			else if(j==0)
			dp[i][j]=true;
			else if(w[i-1]<=j)
			dp[i][j]=dp[i-1][j-w[i-1]] || dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	int k;
	for(int i=0;i<=sum/2;i++)
	if(dp[n][i]==true)
	k=i;
	
	cout<<sum-2*k<<endl;
	return 0;
}
