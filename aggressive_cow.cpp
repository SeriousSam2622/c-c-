#include<bits/stdc++.h>
using namespace std;
#define ff(i, s, n) for (int i = s; i < n; i++)
#define fb(i, s, n) for (int i = n; i >= s; i--)
bool check(int c,long long a[],int n,long long mid)
{
  int count = 1;
  long long curr_pos = a[0];
  ff(i,1,n)
  {
    if(a[i]-curr_pos >= mid)
    {
      curr_pos = a[i];
      count++;
    }
    if(count == c)
    {
      return true;
    }
  }
  return false;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,c;
    cin>>n>>c;
    long long a[n];
    ff(i,0,n)
    {
      cin>>a[i];
    }
    sort(a,a+n);
    long long start = 0;
    long long end = a[n-1]-a[0];
    int ans = -1;
    while(start<=end)
    {
      long long mid = start + (end-start)/2;
      if(check(c,a,n,mid))
      {
        ans = mid;
        start = mid+1;
      }
      else
      {
        end = mid-1;
      }
    }
    cout<<ans<<endl;
  }

}
