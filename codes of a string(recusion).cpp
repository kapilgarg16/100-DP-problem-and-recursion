
//RECURSION

/*
Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. Write a recursive function (return type Arraylist) to print all possible codes for the string. E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

Input Format:-   Enter a number
Output Format
Display all the possible codes

Sample Input
1125
Sample Output
[aabe, aay, ale, kbe, ky]

*/

#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<string>
map<string,string>mp;
vector <string>v(100000);
void codestring(string s,int i,int n,int j)
{
	if(i==n)
	{
		for(int i=0;i<j;i++)
		cout<<mp[v[i]];
		cout<<endl;
		return;
	}
	v[j]=s.substr(i,1);
	codestring(s,i+1,n,j+1);
	
	if((s[i]=='1'||s[i]=='2') && (i+1)<n)
	{
		if(s[i]=='2')
		{
			if(s[i+1]<='6')
			{
			v[j]=s.substr(i,2);
			codestring(s,i+2,n,j+1);
			}
		}
		else
		{
		v[j]=s.substr(i,2);
		codestring(s,i+2,n,j+1);
		}
	}
	
}
int main()
{
	int t;
	cin>>t;
	
mp["1"]="a";  mp["2"]="b"; mp["3"]="c";
mp["4"]="d";  mp["5"]="e";  mp["6"]="f";  mp["7"]="g";   mp["8"]="h";   mp["9"]="i";   mp["10"]="j";    mp["11"]="k";   mp["12"]="l";    
mp["13"]="m";   mp["14"]="n";   mp["15"]="o";   mp["16"]="p";   mp["17"]="q";   mp["18"]="r";   mp["19"]="s";   mp["20"]="t";   mp["21"]="u"; 
mp["22"]="v";   mp["23"]="w";   mp["24"]="x";   mp["25"]="y";   mp["26"]="z";
	while(t--)
	{
	string s;
	cin>>s;
	codestring(s,0,s.length(),0);
	}
}
