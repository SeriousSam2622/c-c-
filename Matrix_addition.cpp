#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m, n, c, d;

  cout << "Enter number of rows and columns of matrix\n";
  cin >> m >> n;
  int first[m][n], second[m][n], sum[m][n];
  cout << "Enter elements of first matrix\n";

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      cin >> first[c][d];

  cout << "Enter the elements of second matrix\n";

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
        cin >> second[c][d];

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      sum[c][d] = first[c][d] + second[c][d];

  cout << "Sum of the matrices:\n";

  for (c = 0; c < m; c++)
  {
    for (d = 0; d < n; d++)
      cout << sum[c][d] << "\t";

    cout << endl;
  }

  return 0;
}
