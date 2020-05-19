//prblm	
	
	/*
	Given a non negative integer number num. For every numbers i in the range 0 = i = num calculate the number of 1's in their binary representation and return them as an array.
	
	Example 1:
	
	Input: 2
	Output: [0,1,1]
	Example 2:
	
	Input: 5
	Output: [0,1,1,2,1,2]
	
	Note:-
	
	-   It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
	-    Space complexity should be O(n).
	-    Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
	*/
	
	
#include<iostream>
using namespace std;
#include<math.h>
#define ll long long
#include<vector>
#include<algorithm>

//Recursive approach( n*logn)
int count_bits(int n)
{
	if(n==0)
	return 0;
	if(n==1)
	return 1;
	if(n%2)
	return 1+count_bits(n/2);
	else
	return count_bits(n/2);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	cout<<count_bits(i)<<" ";
}
//----------------------------------------------------
//Dynamic approach(better(n))

int main()
{
	int n;
	cin>>n;
	int dp[100000];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(i%2)
                dp[i]=1+dp[i/2];
            else
                dp[i]=dp[i/2];
        }
        vector<int>v;
        for(int i=0;i<=n;i++)
            v.push_back(dp[i]);
        for(int i=0;i<=n;i++)
            cout<<v[i]<<" ";
}
