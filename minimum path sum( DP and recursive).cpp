
//prblm
	/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the 
	sum of all numbers along its path.
	
	Note: You can only move either down or right at any point in time.
	
	Example:
	
	Input:
		[
		  [1,3,1],
		  [1,5,1],
		  [4,2,1]
		]
	
	Output:   7
	Explanation: Because the path 1->3->1->1->1 minimizes the sum.*/
//---------------------------------------------------------------------------------

//Dynamic and recursive
#include<iostream>
using namespace std;
#include<math.h>
#define ll long long
#include<vector>
#include<algorithm>

int minpath(int v[][100],int i,int j)
{
	if(i==0&&j==0)
	return v[0][0];
	
	if(i<0||j<0)
	return 99999;
	return min(v[i][j]+minpath(v,i-1,j),v[i][j]+minpath(v,i,j-1));
}
int main()
{
	int r,c;
	cin>>r>>c;
	int a[100][100];
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		cin>>a[i][j];
	}
	cout<<minpath(a,r-1,c-1);
	return 0;
}
//------------------------------------------------------
//Dynamic approach
int main()
{
	int r,c;
	cin>>r>>c;
	int a[100][100];
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		cin>>a[i][j];
	}
	int dp[100][100];
	dp[0][0]=a[0][0];
	for(int i=1;i<r;i++)
	dp[i][0]=dp[i-1][0]+a[i][0];
	for(int j=1;j<c;j++)
	dp[0][j]=dp[0][j-1]+a[0][j];
	for(int i=1;i<r;i++)
	{
		for(int j=1;j<c;j++)
		{
			dp[i][j]=min(a[i][j]+dp[i-1][j],a[i][j]+dp[i][j-1]);
		}
	}
	cout<<dp[r-1][c-1];
}

