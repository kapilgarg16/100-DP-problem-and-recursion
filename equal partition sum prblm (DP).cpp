//equal partition



		/*	
			you are given n  and a array.find this array is equal partition or not
			
			
			i/p:-  n=5
			      arr[] = {1, 2, 3, 4, 4}
			
			Output: true 
			
			Explain:- The array can be partitioned  {1, 2, 4} and {3,4}
			
		*/
		

//-------------------------------------------------------------------------------------------------------
//Dynamic APPROACH			
#include<iostream>
using namespace std;

bool subsetsum(int w[],int n,int sum)
{
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
	return dp[n][sum];
}
int main()
{
	int n,sum=0;
	int a[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	sum+=a[i];
	}
	if(sum%2==1)
	cout<<"No partition\n";
	else
	{
		if(subsetsum(a,n,sum/2))
		cout<<"Equal partition";
		else
		cout<<"No partition";
	}
}
