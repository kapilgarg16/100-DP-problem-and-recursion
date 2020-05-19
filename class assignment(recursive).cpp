
/*
	In a mathematics class, Teacher ask kapil to find the number of all n digit distinct integers which is formed by 
	the two distinct digits ai and bi but there is a rule to form n digit integer.
	
	Rule: He has to form n digit integer by using two digits 'a' and 'b' without consecutive bi.
	
	Alice is very weak in maths section. Help her to find the number of such n digit integers.
	
	Input Format
	The first line contains T, the number of test cases. Further T lines contains the value n which is the 
	number of digit in the integer.
	
	Constraints
	1<=T<=20
	1<=n<=25
	
	Output Format
	For each test case print the number of such n digit integer.
	
	Sample Input
	3
	1
	2
	3
	Sample Output
	#1 : 2
	#2 : 3
	#3 : 5
	Explanation
	For n=1 : integers = a, b . For n=2 : integers = aa, ab, ba For n=3 : integers = aaa, aab, aba, baa, bab
*/

//recursive approach
#include<iostream>
using namespace std;
char out[100];
int c=0;
void binary(int i,int n,char out[])
{
	//base conditon
	if(i==n)
	{
		out[i]='\0';
		//cout<<out<<endl;           //if ypu want to print all strings
		c++;
		return;
	}
	//condition
	if(out[i-1]=='b')
	{
		out[i]='a';
		binary(i+1,n,out);	
	}
	if(out[i-1]=='a')
	{	
		out[i]='a';
		binary(i+1,n,out);
		out[i]='b';
		binary(i+1,n,out);
	}
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{   
		//a ->0
		//b ->1
		int n;
		cin>>n;
		out[0]='a';
		c=0;
		binary(1,n,out);
		int d=c;
		c=0;
		out[0]='b';
		binary(1,n,out);
		cout<<"#"<<i<<" : "<<d+c<<endl;
	}
	return 0;
	
}
