#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> dis;

void solve()
{
    cin >> n >> m;
    dis.assign(n, 1e9);
    adj.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dis[0] = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int node = p.second;
        int wt = p.first;
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int adjWt = it.second;
            if (dis[adjNode] > dis[node] + adjWt)
            {
                dis[adjNode] = dis[node] + adjWt;
                pq.push({adjWt, adjNode});
            }
        }
    }
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