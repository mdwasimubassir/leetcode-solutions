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
    double wt;
    Edge(int a, double b)
    {
        v = a;
        wt = b;
    }
};
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        int k = 0;
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        vector<vector<Edge>> adj(n);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            Edge m(v, succProb[k++]);
            Edge n(u, succProb[k - 1]);
            adj[u].push_back(m);
            adj[v].push_back(n);
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        while (pq.size())
        {
            int u = pq.top().second;
            pq.pop();
            for (Edge &e : adj[u])
            {

                if (dist[e.v] < dist[u] * e.wt)
                {
                    dist[e.v] = dist[u] * e.wt;
                    pq.push({dist[e.v], e.v});
                }
            }
        }
        return dist[end_node];
    }
};