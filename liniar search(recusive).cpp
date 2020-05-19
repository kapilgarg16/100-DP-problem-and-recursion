
/*find a number(liniar search) exist in a array or not using recursion

i/p: 	n=5
	key=2	
	1 2 3 4 5
	
o/p:   "YES"
*/

//RECUSIVE 
#include<iostream>
using namespace std;
bool lsrch(int *a,int key,int n)
{
	if(n==0)
	return false;
	else if(a[0]==key)
	return true;
	return lsrch(a+1,key,n-1);
}
int main()
{
		int n,key;
		cin>>n>>key;
		int *a=new int[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		if(lsrch(a,key,n))
		cout<<"YES\n";
		else
		cout<<"NO\n";
}
