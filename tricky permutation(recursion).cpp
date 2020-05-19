
	/*
	
	Given a string containing duplicates, print all its distinct permutations such that there are no duplicate
	permutations and all permutations are printed in a lexicographic order.
	
	Input Format
	The first and only line of the test case contains the input string.
	
	Constraints
	Length of the string <= 8
	
	Output Format
	Print all the distinct permutations in a lexicographic order such that each permutation is in a new line.
	 Note that there should not be any duplicate permutations.
	 
	Sample Input:-
	
	ABA
	
	Sample Output:-
	
	AAB
	ABA
	BAA
	
	Explanation:-
	The possible permutations for the given string are { "AAB" , "AAB" , "ABA" , "BAA" } . We
	skip the repeating "AAB" permutation and only print it in once. Also we print the final output 
	in lexicographical order.
	
	*/



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
