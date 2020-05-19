//subset sum
		
		
		
		/* there is a array.find subset which element sum is equal to given sum**
			
			
		i/p   -    n=5
		         sum=11;
			w={2,3,7,8,10};
			
		o/p  -	"YES"
		*/
			
	
	
//Dynmaic Approach
#include<iostream>
using namespace std;
int main ()
{
	int n,sum,w[n+1];
	
	cin>>n>>sum;
	
	for(int i=0;i<n;i++)
	cin>>w[i];
	
	bool dp[n+1][sum+1];
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0&&j==0)
			dp[i][j]=true;
			else if(i==0)
			dp[i][j]=false;
			else if(j==0)
			dp[i][j]=true;
			else if(w[i-1]<=j)
			dp[i][j]=dp[i-1][j-w[i-1]] || dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	
	if(dp[n][w])
	cout<<"YES\n";
	else
	cout<<"NO\n";
	/*for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
}
