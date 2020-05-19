//prblm

	/* A robot is located at the top-left corner of a m x n grid (marked 'Start' ).
	
	The robot can only move either down or right at any point in time. The robot is trying to 
	reach the bottom-right corner of the grid (marked 'Finish')
	
	Now consider if some obstacles are added to the grids. How many unique paths would there be?
	
	
	An obstacle and empty space is marked as 1 and 0 respectively in the grid.
	
	Note: m and n will be at most 100.
	
	Example 1:
	
	Input:
	r=3,c=3
	[
	  [0,0,0],
	  [0,1,0],
	  [0,0,0]
	]
	
	Output: 2
	
	Explanation:
	
		There is one obstacle in the middle of the 3x3 grid above.
		There are two ways to reach the bottom-right corner:
		1. Right -> Right -> Down -> Down
		2. Down -> Down -> Right -> Right */


//-------------------------------------------------------------------		
//soln
//recursive apporach
#include<iostream>
using namespace std;
#include<math.h>
#define ll long long
#include<vector>
#include<algorithm>
#define mod 99999


int unique_path2(int a[][100],int r,int c)
{
	if(r==0&&c==0)  //base condition
	return 1;
	if(r<0||c<0)    //base condition
	return 0;
	if(a[r][c]==1)
	return 0;
	
	return unique_path2(a,r-1,c) + unique_path2(a,r,c-1);  //recursive fun,,
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
	cout<<unique_path2(a,r-1,c-1);
}

//---------------------------------------------------------------------------------------
//Dynamic approach

int main()
{

 	int r,c;
 	cin>>r>>c;
 	int a[r+1][c+1];
 	
 	for(int i=0;i<r;i++)
 	{
 		for(int j=0;j<c;j++)
		cin>>a[i][j];	
	}
	int dp[r+1][c+1];
        
	if(a[0][0]==1)
            return 0;
        
	int i,j;
        
        //this is for row base condition
	for( i=0;i<r;i++)
   	{ 
	        if(a[i][0]==0)
	        dp[i][0]=1;
	        else
	        break;
    	}
    	
	for(j=i;j<r;j++)
        dp[j][0]=0;
	
	//this is for column base condition
	
	for(j=0;j<c;j++)
	{ 
	        if(a[0][j]==0)
	        dp[0][j]=1;
	        else
	        break;
    	}
        
	for(i=j;i<c;i++)
        dp[0][i]=0;
	
	
	for(i=1;i<r;i++)
	{
		for( j=1;j<c;j++)
		{
            		if(a[i][j]==0)
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		        else
		        dp[i][j]=0;
		}
	}
    	
	cout<<dp[r-1][c-1];
}

