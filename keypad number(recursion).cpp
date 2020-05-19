//  key pad phone number


/* you are given a keypad...then you dialled a number...then find the total number of substring 

i/p:-   23
o/p:-   "AD", "AE", "AF", "BD" ,"BE", "BF", "CD" ,"CE","CF"

*/
#include<iostream>
using namespace std;
string s1[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
char out[100];
void keypad(string s,int i,int j,int n)
{
	if(i==n)
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	int d=s[i]-'0';
	if(d==0|d==1)
	{
		keypad(s,i+1,j,n);
	}
	else 
	for(int k=0;k<s1[d].length();k++)
	{
		out[j]=s1[d][k];
		keypad(s,i+1,j+1,n);
	}
}
int main()
{
		string s;
		cin>>s;
		keypad(s,0,0,s.length());
}
