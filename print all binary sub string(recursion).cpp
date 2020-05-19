	/*
	You are provided an integers N. You need to print all possible distinct binary strings of length N such that there are no consecutive 1’s.
	
	Input Format
	First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.
	
	Constraints
	1<=t<=100 1<=n<=90
	
	Output Format
	Print the number of all possible binary strings.
	
	Sample Input:-
	
	2
	2
	3

	Sample Output:-
	
	00, 01, 10
	000, 001, 010, 100, 101
	
	Explanation
	1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101
	
	*/


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
		cout<<out<<endl;
		//c++;
		return;
	}
	//condition
	if(out[i-1]=='1')
	{
		out[i]='0';
		binary(i+1,n,out);	
	}
	if(out[i-1]=='0')
	{	
		out[i]='0';
		binary(i+1,n,out);
		out[i]='1';
		binary(i+1,n,out);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		out[0]='0';
		//c=0;
		binary(1,n,out);
		//int d=c;
		//c=0;
		out[0]='1';
		binary(1,n,out);
		//cout<<d+c<<endl;
	}
	return 0;
	
}
