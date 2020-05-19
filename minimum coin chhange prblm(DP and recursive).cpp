//prblm

/*	You are given coins of different denominations and a total amount of money amount. 
	Write a function to compute the fewest number of coins that you need to make up that amount. 
	If that amount of money cannot be made up by any combination of the coins, return -1.
	
		Example 1:
	
		Input: coins = [1, 2, 5], amount = 11
		Output: 3 
	
		Explanation: 11 = 5 + 5 + 1
	
		Example 2:
	
		Input: coins = [2], amount = 3
		Output: -1
	Note:
	You may assume that you have an infinite number of each kind of coin.
*/
//-----------------------------------------------------------------------------------------------

//recursive
#include<iostream>
using namespace std;
#include<math.h>
#define ll long long
#include<vector>
#include<algorithm>
#define mod 99999
//recursive code


int coinchange(int *a,int n,int sum)
{
	if(sum==0)
	return 0;              //base condition
	
	else if(sum<0||(n<=0&&sum>0))
	return 9999;
	
	//recursive function
	
	if(a[n-1]<=sum)
	return min(1+coinchange(a,n,sum-a[n-1]),coinchange(a,n-1,sum));
	else
	return coinchange(a,n-1,sum);
}
int main()
{
	
	int n,sum;
	cin>>n>>sum;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int p=coinchange(a,n,sum);
	if(p==9999)
	cout<<"-1"<<endl;
	else
	cout<<p<<endl;
}
//---------------------------------------------------------------------
//Dynamaic approach
int main()
{
	int n,sum;
	
	cin>>n>>sum;
	
	int *a=new int[n];
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	int dp[n+1][sum+1];
	
	for(int i=1;i<=n;i++)    //intial cond
	dp[i][0]=0;
	
	for(int i=0;i<=sum;i++)  //intial cond
	dp[0][i]=mod;
	
	for(int i=1;i<=sum;i++)
	{
		if(i%a[0]==0)
		dp[1][i]=i/a[0];
		else
		dp[1][i]=0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
		if(a[i-1]<=j)
		dp[i][j]=min(1+dp[i][j-a[i-1]],dp[i-1][j]);
         	else
             	dp[i][j]=dp[i-1][j];
	     	}
	}
	cout<<dp[n][sum];
	return 0;
}
