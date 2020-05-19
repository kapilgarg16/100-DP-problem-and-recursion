//prblm

	/*
	You are climbing a stair case. It takes n steps to reach to the top.
	
	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
	
	Note: Given n will be a positive integer.


	Input: 3
	Output: 3
	
	Explanation: There are three ways to climb to the top.
	1. 1 step + 1 step + 1 step
	2. 1 step + 2 steps
	3. 2 steps + 1 step
	*/


#include<iostream>
using namespace std;
#include<math.h>
#define ll long long
#include<vector>
//recursive apporach

int c=0;
void step(int n,int i)
{
	if(i>=n)
	{if(i==n)
	  c++;
	return ;}
	
	step(n,i+1);
	step(n,i+2);
}
int main()
{
	int n;
	cin>>n;
	step(n,0);
	cout<<c<<endl;
}

//-------------------------------------
//Dynamic approach
int main()
{
	int n;
	cin>>n;
	int dp[n+1];
	dp[1]=1; dp[2]=2;
	
	for(int i=3;i<=n;i++)
	dp[i]=dp[i-1]+dp[i-2];
	cout<<dp[n]<<endl;
	return 0;
}
