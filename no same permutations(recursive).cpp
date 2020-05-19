/*	Given a collection of numbers containing duplicates, print all possible permutations for the given collection of numbers 
	in a lexicographic manner .Make sure that no two permutations are same.
	
	//Lexicographic Order. ... This is dictionary order, except that all the uppercase letters preceed all the lowercase letters.\\
	
	
	Input Format
	The first line will contain the number of elements, N in the array.
	The second line will contain N elements of the array, A[i].
	
	Constraints
	1<= N <= 10 0 <= A[i] <= 100000
	
	Output Format
	Print all unique lexicographic permutations of the array. Each permutation will contain space separated elements. 
	The next permutation should be printed in a new line.
	
	Sample Input
	3
	1 1 3
	Sample Output
	1 1 3 
	1 3 1 
	3 1 1    
*/


//RECURSIVE APPROACH
#include<iostream>
using namespace std;
#include<string>
#define ll long long
#include<algorithm>
#include<vector>
void perm(vector<ll int>v,ll int i,ll int j,ll int n,vector<ll int>v1)
{
	if(j==n)
	{
		for(ll int i=0;i<j;i++)
		cout<<v1[i]<<" ";
		cout<<endl;
		return;
	}
	int k=i;
	for(ll int p=k;p<n;p++)
	{
		if((v[k]==v[p])&&(k!=p))
		continue;
		v1[j]=v[p];
		swap(v[k],v[p]);
		perm(v,i+1,j+1,n,v1);
	}
}
int main()
{
		ll int n;
		cin>>n;
		vector<ll int>v(n);
		vector<ll int> vout(n);
		for(ll int i=0;i<n;i++)
		cin>>v[i];
		sort(v.begin(),v.end());
		perm(v,0,0,n,vout);
	
	return 0;
}
