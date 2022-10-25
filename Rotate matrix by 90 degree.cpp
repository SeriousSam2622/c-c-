class Solution 
{
  public:
  void rotate(vector<vector<int>>& matrix) 
  {
      int n = matrix.size();
      vector<vector<int>> temp(n);
      for(int i=0; i<n; i++)
      {
          for(int j=n-1; j>=0; j--)
          {
              temp[i].push_back(matrix[j][i]);
          }
      }
      matrix = temp;
  }
};
