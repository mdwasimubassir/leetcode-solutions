#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;
class Edge
{
public:
    int v;
    int wt;
    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<Edge>> adj(n + 1);
        for (auto &e : times)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            Edge m(v, w);
            adj[e[0]].push_back(m);
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k ] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (pq.size())
        {
            int top = pq.top().second;
            pq.pop();
            for (Edge e : adj[top])
            {
                if (dist[e.v] > dist[top] + e.wt)
                {
                    dist[e.v] = dist[top] + e.wt;
                    pq.push({dist[e.v], e.v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};