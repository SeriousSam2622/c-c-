#include <bits/stdc++.h>
using namespace std;

int main ()
{
	long long int n;
	cin>>n;
	long long int a[n+1]={0};
	for (long long int i=1; i<n; i++)
	{
		long long int x;
		cin>>x;
		a[x]++;
	}
	for (long long int i=1; i<n+1; i++)
	{
		if ( a[i]==0 )
		{
			cout<<i;
			break;
		}
	}
}