#include <bits/stdc++.h>
using namespace std;

int main ()
{
	string s;
	cin>>s;
	long long int max=0, x=0, l;
	l=s.length();
	char a = s[0];
	for (long long int i=0; i<l; i++)
	{
		if (a==s[i])
			x++;
		else
		{
			a = s[i];
		if (x>=max)
		{
			max=x;
		}
			x=1;
		}
	}
	if (x>max)
		{
			max=x;
		}
	cout<<max;
}