#include <bits/stdc++.h>
using namespace std;

class Solution
{
  int n, m;
  int timer = 1;
  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
  vector<vector<int>> vis;
  vector<vector<int>> a;
  vector<vector<int>> tin;
  vector<vector<int>> low;

  bool check(int x, int y)
  {
    return x >= 0 && x < n && y < m && y >= 0 && a[x][y];
  }

  bool dfs(int x, int y, int px, int py)
  {
    vis[x][y] = 1;
    tin[x][y] = low[x][y] = timer++;
    int child = 0;
    for (int i = 0; i < 4; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx == px && yy == py)
        continue;
      if (check(xx, yy))
      {
        if (!vis[xx][yy])
        {
          if (dfs(xx, yy, x, y))
            return 1;
          low[x][y] = min(low[x][y], low[xx][yy]);
          if (low[xx][yy] >= tin[x][y] && px != -1)
            return 1;
          child++;
        }
        else
        {
          low[x][y] = min(low[x][y], tin[xx][yy]);
        }
      }
    }
    if (child > 1 && px == -1)
      return 1;
    return 0;
  }

public:
  int minDays(vector<vector<int>> &grid)
  {
    n = grid.size(), m = grid[0].size();
    if (n == 1 || m == 1)
    {
      int sum = 0;
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          sum += grid[i][j];
        }
      }
      return sum;
    }

    a = grid;
    int cnt = 0;
    vis.assign(n, vector<int>(m, 0));
    tin.assign(n, vector<int>(m, 0));
    low.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vis[i][j] && grid[i][j])
        {
          if (dfs(i, j, -1, -1))
            return 1;
          cnt++;
        }
      }
    }
    if (cnt > 1)
      return 0;
    return 2;
  }
};

int main()
{
  Solution a;
  vector<vector<int>> grid = {{1, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  cout << a.minDays(grid) << endl;
  return 0;
}