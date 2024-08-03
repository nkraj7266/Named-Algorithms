#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> dis(n, 1e9);
    vector<vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
    dis[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : adj)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dis[u] != 1e9 && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    // N_th iteration for -ve cycle detection
    bool f = 0;
    for (auto it : adj)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if (dis[u] != 1e9 && dis[v] > dis[u] + w)
        {
            f = 1; // -ve cycle present
        }
    }
    cout << ((f) ? "-ve cycle detected" : "No -ve cycle") << endl;
    for (auto it : dis)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}