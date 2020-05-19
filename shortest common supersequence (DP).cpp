//Shortest common supersequence


	/*
	we will take 2 string s1 and s2. and we will find minimum length of a merge string (s1 and s2)
	 which have both sequence s1 and s2;
	
	i/p -> s1 = "geek" ,  s2 = "eke"
	
	o/p  ->   5
	
	explain-  "g e e k e"   --->  "geek" + "eke"
	*/
	
//-------------------------------------------------------------

/*Basically this is same as lcs problem. 
first we will find LCS b/c it is common in both string. so it will come only single time in supersequence...

so basically len(s1)+len(s2) - len(lcs)  will be the length of supersequence
*/	


//Top down approach(Dynamic Approach)
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
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
	cout<<s1.length()+s2.length()-dp[l1][l2];
	return 0;
}
