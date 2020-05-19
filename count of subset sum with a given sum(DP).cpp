//count of subset

		/*	there is a array.find the count of subset which sum is equal to given sum...
			
			input :-	n=  5
					sum= 5
					a[]= 1 2 3 1 5
			
			
			o/p :-		3
			
			explain:-    {5},  {1,1,3},  {2,3}	*/
 
//--------------------------------------------------------------------------

//(Dynmaic Approach)
#include<iostream>
using namespace std;
int main()
{
	int n,sum;
	int w[1000];
	cin>>n>>sum;
	for(int i=0;i<n;i++)
	cin>>w[i];

	int dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(i==0&&j==0)
			dp[i][j]=1;
			else if(i==0)
			dp[i][j]=0;
			else if(j==0)
			dp[i][j]=1;
			else if(w[i-1]<=j)
			dp[i][j]=dp[i-1][j-w[i-1]] + dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j];	
		}
	}
	cout<<dp[n][sum]<<endl;
}
