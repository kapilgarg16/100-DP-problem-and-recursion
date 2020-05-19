// LONGEST PALINDROME SUBSEQUENCE
 
 
 	/*	given a string s then find longest palindromic subsequence
 
		 input->   s = "agbcba"
		 
		 output->  5
 
 		explain :-  "abcba" ->l=5 */	
 		
//if we find LCS of s and reverse(s) then it will give longest palindromic string...

//-------------------------------------------------------
//Dynmaic Approach
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
int main()
{
	string s1;
	cin>>s1;
	string s2=s1;
	reverse(s1.begin(),s1.end());
	int l=s1.length();
	int dp[l+1][l+1];
	for(int i=0;i<=l;i++)
	{
		for(int j=0;j<=l;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else 
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[l][l]<<endl;
	return 0;
}
