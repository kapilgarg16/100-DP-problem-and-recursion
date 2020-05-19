	
	/*	-------------------------------------------------------------------------------------
			Now important thing
			knapsack has 3 parts...
			
			a. fractional knapsack(greedy approach)
			b. 0/1 knapsack
			c. unbounded knapsack
		------------------------------------------------------------------------------------	
			
			(b) 0/1 knapsack :- there are 6 problem which are based on 0/1 knapsack...We will do some small change in 0/1 knapsack for perform
						this following programs...
						
						(1):-  SUBSET SUM PROBLEM
						(2):-  EQUAL SUM PARTITION PROBLEM
						(3):-  COUNT OF SUBSET SUM WITH A GIVEN SU,
						(4):-  MININMUM SUBSET SUM DIFFERENCE
						(5):-  COUNT NUMBER OF SUBSET WITH A GIVEN DIFFERENCE.
						(6):-  TARGET SUM
		
		-----------------------------------------------------------------------------------------*/
		

	//(b). firstly we will know about 0/1 knapsack.
	

/* ->   0-1 Knapsack Problem:-(language GFG)
	
	Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
	
	In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
	
	also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this
	
	subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
	
	
	i/p :-  n=5
		W=8(capacity)
		value[] =  {0,1,2,5,6}   (profit)
		weight[] = {0,2,3,4,5}
		
	o/p :-  8 (max profit)
*/

#include<iostream>
using namespace std;
#include<algorithm>


//-----------------------------------------------------

//(Dynamic approach)...tabular method
int main()
{
	int n,W;
	cin>>n>>W;
	
	int val[n+1];
	int wt[n+1];
	
	for(int i=0;i<n;i++)    //weight array
	cin>>wt[i];
	
	for(int i=0;i<n;i++)     //value array
	cin>>val[i];
	
	int dp[n+1][W+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			
			else if(j<wt[i])
			dp[i][j]=dp[i-1][j];
			
			else if(j>=wt[i])
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i]]+val[i]); 
			
		}
		
	}
	cout<<dp[n][W]<<endl;
}
