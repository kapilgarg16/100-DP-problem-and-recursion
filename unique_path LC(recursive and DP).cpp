



//prblm
/*	A boy is located at the top-left corner of a m x n grid(matrix) (marked 'Start')
	
	The boy can only move either down or right at any point in time. 
	The boy is trying to reach the bottom-right corner of the grid  (marked 'Finish')
	
	How many possible unique paths are there...
	
	input :- r = 3 , c = 2
	output:- 3
*/
//------------------------------------------------------------------------------------------------------

//recursive apporach
#include<iostream>
using namespace std;
int unique_path(int r,int c)
{
	if(r==0&&c==0)  //base condition
	return 1;
	if(r<0||c<0)    //base condition
	return 0;
	
	return unique_path(r-1,c) + unique_path(r,c-1);  //recursive fun,,
}
int main()
{
	int r,c;
	cin>>r>>c;
	cout<<unique_path(r-1,c-1);
}

//-------------------------------------	

//Dynamic Approach
int main()
{
	int r,c;
	cin>>r>>c;
    	if(r==0&&c==0)
        return 0;
	int dp[r+1][c+1];
	
	for(int i=0;i<r;i++)
	dp[i][0]=1;              //base condition
	for(int j=0;j<c;j++)
	dp[0][j]=1;             //base condition
	
	for(int i=1;i<r;i++)
	{
		for(int j=1;j<c;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	cout<<dp[r-1][c-1];
	return 0;
}




