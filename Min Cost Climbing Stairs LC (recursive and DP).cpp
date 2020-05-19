//prblm 
/*	
	On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
	
	Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor,
	 and you can either start from the step with index 0, or the step with index 1.
	
	Example 1:
		Input: cost = [10, 15, 20]
		Output: 15
	Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
	
	Example 2:
	
		Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
		Output: 6
	Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
	
	
	Note:
	cost will have a length in the range [2, 1000].
	Every cost[i] will be an integer in the range [0, 999]
*/







//recursion and DP
#include<iostream>
using namespace std;
#include<math.h>
#define ll long long
#include<vector>
#include<algorithm>
int mini,x=0,y=0;


//Recursive Approach(complexity-  2^n)
int clst(int *a,int n)
{
	if(n<0)   //base codn
	return 0;
	return min(a[n]+clst(a,n-2),a[n]+clst(a,n-1));
}
int main()
{	
	int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++)
	cin>>a[i];
	reverse(a,a+n);
	cout<<min(clst(a,n-1),clst(a,n-2));
	return 0;
}
//------------------------------------------------------------------------------------
//Dynamic approach(complexity- n)(BETTER)
int main()
{
	int n;
	cin>>n;
	int a[10000];
	for(int i=0;i<n;i++)
	cin>>a[i];
	if(n==0)
	return 0;
	
	int dp[n+1];
	dp[0]=a[0];
	dp[1]=a[1];
	for(int i=2;i<n;i++)
	dp[i]=min(a[i]+dp[i-2],a[i]+dp[i-1]);
	cout<< min(dp[n-1],dp[n-2]);
}
