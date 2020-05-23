//    https://codeforces.com/contest/1353/problem/E


//Dynamic programming
#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int *pref=new int[n];
		pref[0]=s[0]-'0';
		for(int i=1;i<n;i++)
		pref[i]=pref[i-1]+s[i]-'0';
		//for(int i=0;i<n;i++)
		//cout<<pref[i]<<" ";
		int *dp=new int[n];
		for(int i=0;i<n;i++)
		dp[i]=0;
		for(int i=n-1;i>=0;i--)
		{
			int r1= 1 ^ (s[i]-'0');
			if(i+k<n)
			{
				r1+=pref[i+k-1]-pref[i];
				r1+=dp[i+k];	
			}
			else
			r1+=pref[n-1]-pref[i];
			
			int r2=pref[n-1]-pref[i]+s[i]-'0';
			dp[i]=min(r1,r2);
		}
		cout<<endl;
		int mini=dp[0];
		for(int i=1;i<n;i++)
		{
		dp[i]=dp[i]+pref[i-1];
		mini=min(mini,dp[i]);}
		cout<<mini<<endl;
	}
}
