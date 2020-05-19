
//prblm

/*
	Given a string s and a string t, check if s is subsequence of t.
	
	A subsequence of a string is a new string which is formed from the original string by deleting some 
	(can be none) of the characters without disturbing the relative positions of the remaining characters. 
	(ie, "ace" is a subsequence of "abcde" while "aec" is not).
	
	
	Example 1:
	
		Input: s = "abc", t = "ahbgdc"
		Output: true
	
	Example 2:
	
		Input: s = "axc", t = "ahbgdc"
		Output: false

*/

//-----------------------------------------------------------
//Recursive
#include<iostream>
using namespace std;
#include<math.h>
#define ll long long
#include<vector>
//recursive apporach

void sub(string s1,string s2,int n1,int n2)
{
	if(n2<0)
	{
		cout<<"TRUE\n";
		return;
	}
	if(n1<0&&n2>=0)
	{
		cout<<"FALSE\n";
		return;
	}
	
	if(s1[n1]==s2[n2])
	sub(s1,s2,n1-1,n2-1);
	else
	sub(s1,s2,n1-1,n2);
}
int main()
{
	while(1)
	{
	string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	sub(s1,s2,s1.length()-1,s2.length()-1);
	}
	return 0;
}
//----------------------------------------------------------
//Dynamic Approach

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int n1=s1.length();
	int n2=s2.length();
	
	bool dp[100][10000];
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			if(i==0&&j==0)
			dp[i][j]=true;
			
			else if(i==0)
			dp[0][j]=true;
			
			else if(j==0)
			dp[i][0]=false;
			
			else if(s1[i-1]==s2[j-1])
			dp[i][j]=dp[i-1][j-1];
			
			else if(s1[i-1]!=s2[j-1])
			dp[i][j]=dp[i][j-1];
		}
	}
	if(dp[n1][n2])
	cout<<"true\n";
	else
	cout<<"false\n";
	return 0;
	
}
