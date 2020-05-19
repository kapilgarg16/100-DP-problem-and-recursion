/*
Given a string (s)containing n characters find all the substring of string..

input:- "kap"
o/p:- "kap","ka","kp","k","ap","a","p","",

*/




#include<iostream>
using namespace std;
#include<string>
char opstrn[100];
void substring(string s,int i,int j,int n)
{
	if(i==n)
	{
		opstrn[j]='\0';
		cout<<opstrn<<endl;
		return;	
	}
	opstrn[j]=s[i];
	substring(s,i+1,j+1,n);
	substring(s,i+1,j,n);
}
int main()
{
	
		string s;
		cin>>s;
		substring(s,0,0,s.length());
		return 0;
}
