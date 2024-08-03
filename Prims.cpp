#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> vis;
int ans = 0;
vector<pair<int, int>> mst;

void solve()
{
    cin >> n >> m;
    adj.resize(n);
    vis.assign(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, -1}});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second.first;
        int par = it.second.second;
        int wt = it.first;
        if (vis[node])
            continue;
        vis[node] = 1;
        if (par != -1)
        {
            ans += wt;
            mst.push_back({node, par});
        }
        for (auto e : adj[node])
        {
            int adjNode = e.first;
            int adjWt = e.second;
            if (!vis[adjNode])
            {
                pq.push({adjWt, {adjNode, node}});
            }
        }
    }

    cout << ans << endl;
    for (auto &e : mst)
    {
        cout << e.first << ", " << e.second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}