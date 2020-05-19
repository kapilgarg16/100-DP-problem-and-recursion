
/*

	Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
	The output strings should be printed in the sorted order considering '(' has higher value than ')'.
	
	Input Format
	Single line containing an integral value 'n'.
	
	Constraints
	1<=n<=11
	
	Output Format
	Print the balanced parentheses strings with every possible solution on new line.
	
	Sample Input
	
	Sample Output
	()()()
	()(())
	(())()
	(()())
	((()))
*/



//RECURSIVE approach
#include<iostream>
using namespace std;
void paran(string s,int open,int close,int pos,int n)
{
	//base
	if(pos==2*n)
	{
		if(open==close)
		cout<<s<<endl;
		return;
	}
	if(open>close)
	paran(s+")",open,close+1,pos+1,n);
	
	if(open<=n)
	paran(s+"(",open+1,close,pos+1,n);
}
int main()
{
		int n;
		cin>>n;
		paran("(",1,0,1,n);
}
