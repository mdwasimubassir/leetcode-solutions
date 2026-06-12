#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> adj(n, vector<int>(n, 1e8));

        for (int i = 0; i < n; i++)
            adj[i][i] = 0;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        int f[n];
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            for (int j = 0; j < n; j++)
            {

                if (adj[i][j] <= distanceThreshold)
                    x++;
            }
            f[i] = x;
        }
        int min = f[0];
        int idx = 0;
        for (int i = 1; i < n; i++)
        {
            if (f[i] <= min)
            {
                min = f[i];
                idx = i;
            }
        }
        return idx;
    }
};