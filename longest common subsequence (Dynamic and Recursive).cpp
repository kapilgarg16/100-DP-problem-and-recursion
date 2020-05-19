//length of longest common subsequence
/*

	input-> 	s1= "kapilgarg"
			s2=  "mplgrk"
			
	output->         4
	
	explain->        "plgr" (Common)

*/


//-------------------------------------------------------


//recursive 
#include<iostream>
#include<string>
using namespace std;
#include<algorithm>
int LCS(string s1, string s2,int l1,int l2)
{
	//Base condition
	if(l1==0||l2==0)
	return 0;
	//choice diagram
	if(s1[l1-1]==s2[l2-1])
	return (1+LCS(s1,s2,l1-1,l2-1));   //small input
	else
	return max(LCS(s1,s2,l1-1,l2),LCS(s1,s2,l1,l2-1));
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int l1=s1.length();
	int l2=s2.length();
	cout<<LCS(s1,s2,l1,l2);
	return 0;
}

//-------------------------------------------------------
//Dynmaic Approach

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int l1=s1.length();
	int l2=s2.length();
	int dp[l1+1][l2+1];
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else 
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[l1][l2]<<endl;
	return 0;
}
