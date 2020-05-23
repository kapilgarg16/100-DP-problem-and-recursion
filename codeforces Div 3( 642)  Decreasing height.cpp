//https://codeforces.com/contest/1353/problem/F



//this all greedy method and DP...
#include<iostream>
using namespace std;
#include<algorithm>
#define ll long long

ll int minpath(ll int a[][101], ll int dp[][101],int i,int j,ll int value,int r,int c)
{
	//base condition
	if(i==r-1&&j==c-1)
	{
		if(a[i][j]<value)
		return dp[i][j]=1e18;
		else
		return dp[i][j]=a[i][j]-value;
	}
	if(i>=r||j>=c)
	return 1e18;
	if(a[i][j]<value)
	return 1e18;
	
	if(dp[i][j]!=-1)
	return dp[i][j];
	ll int x=a[i][j]-value;
	return dp[i][j]=min(x+minpath(a,dp,i+1,j,value+1,r,c),x+minpath(a,dp,i,j+1,value+1,r,c));
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		ll int a[101][101];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			cin>>a[i][j];
		}
		ll int dp[101][101]; 
		ll int mini=1e18;   
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				for(int i1=0;i1<r;i1++)
				{ 					//greedy methodd
					for(int j1=0;j1<c;j1++)
					dp[i1][j1]=-1;            //intialize of DP
				}
				ll int value=a[i][j]-(i+j);
				ll int ans =minpath(a,dp,0,0,value,r,c);
				mini=min(mini,ans);
			}se
			
		}
		cout<<mini<<endl;
	}
}
