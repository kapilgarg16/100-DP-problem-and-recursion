//Dynamic and Recursive approach


	/*Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only 
	once. Find out the total number of ways in which friends can remain single or can be paired up.
	
	
	Input Format:- 
	First line contains an integer t denoting the number of test cases. Next t lines contain an integer n each.
	
	Constraints
	1<= n < 30
	
	Output Format
	Output t lines each line describing the answer.

	Sample Input:	1
			3
			
	sample Output:  4
	
	Explanation:-
	{1}, {2}, {3} : all single {1}, {2,3} : 2 and 3 paired but 1 is single. {1,2}, {3} : 1 and 2 are
	paired but 3 is single. {1,3}, {2} : 1 and 3 are paired but 2 is single. Note that {1,2} and {2,1}
	 are considered same.*/
	 

#include<iostream>
using namespace std;
#define ll long long 
//recursive approach
ll int pairs(int n)
{
	//base condition
	if(n==1||n==0)
	return 1;
	
	ll int p=pairs(n-1);
	ll int q=(n-1)*pairs(n-2);
	return p+q;
}
int main()
{
	ll int t;
	cin>>t;
	while(t--)
	{
		ll int n;
		cin>>n;
		cout<<pairs(n)<<endl;
	}
	return 0;
}
//Dynamic programming approach (O(n) complexity)
//...............................
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int tt;
   cin>>tt;
   int dp[31]={0};
   dp[1]=1;
   dp[2]=2;
   for(int i=3;i<=30;i++)
   {
	   dp[i]=dp[i-1]+(i-1)*dp[i-2];
   }
   while(tt--)
   {
	   int n;
	   cin>>n;
	   cout<<dp[n]<<endl;
   }
   return 0;
}
