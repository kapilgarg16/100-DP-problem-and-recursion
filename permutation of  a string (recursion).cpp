/*
Print total permutation (n!) of a given string

i/p:-   "kap"

o/p:-   akp
	apk
	kap
	kpa
	pak
	pka
*/


//RECURSION APPROACH
#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
char out[100000];

void perm(string s,int i,int j,int n)
{
	if(j==n)
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	int k=i;
	for(int p=k;p<s.length();p++)
	{
		if((s[k]==s[p])&&(k!=p))
		continue;
		out[j]=s[p];
		swap(s[k],s[p]);
		perm(s,i+1,j+1,n);
		
	}
}
int main()
{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		perm(s,0,0,s.length());
	
	return 0;
}
