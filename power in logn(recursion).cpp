


/*find the power of n^m  in log m comlexity

i/p=  2,5
o/p=  32*/

#include<iostream>
using namespace std;

//complexity 2^m ...
/*int fpow(int n,int m)
{
	if(m==0)
	return 1;
	else
	return n*fpow(n,m-1);
}*/


//recursive approach**
//complexity (log m)
int fpow(int n,int m)
{
	if(m==1)
	return n;
	else if(m==0)
	return 1;
	int p=fpow(n,m/2);
	if(m%2==1)
	return p*p*n;
	else
	return p*p;
}
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<fpow(n,m)<<endl;
}
