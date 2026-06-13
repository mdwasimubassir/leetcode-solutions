#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(numCourses, vector<int>(numCourses, 1e8));
        for (int i = 0; i < numCourses; i++)
            adj[i][i] = 0;
        for (auto &edge : prerequisites)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = 1;
            adj[u][v] = 1;
        }
        for (int k = 0; k < numCourses; k++)
        {
            for (int i = 0; i < numCourses; i++)
            {
                for (int j = 0; j < numCourses; j++)
                {
                   
                        adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
        vector<bool> ans;
        for (auto &edge : queries)
        {
            int u = edge[0];
            int v = edge[1];
            if (adj[u][v]!=1e8 && adj[u][v]>0)
            {
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }
        return ans;
    }
};