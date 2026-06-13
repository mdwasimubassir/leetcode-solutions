#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<string, int> mp;
        int idx = 0;
        for (auto &d : equations)
        {
            string a = d[0];
            string b = d[1];
            if (mp.find(a) == mp.end())
                mp[a] = idx++;
            if (mp.find(b) == mp.end())
                mp[b] = idx++;
        }
        int n = idx;
        vector<vector<double>> dp(n, vector<double>(n, -1.0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1.00;
            int k=0;
        for (auto &d : equations)
        {
            string a = d[0];
            string b = d[1];
            dp[mp[a]][mp[b]]=values[k];
            dp[mp[b]][mp[a]]=1/values[k];
            k++;

        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                   if (dp[i][k] != -1.0 && dp[k][j] != -1.0 && dp[i][j]==-1) {
                        dp[i][j] = dp[i][k] * dp[k][j];
                    }
                }
            }
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            string a = queries[i][0];
            string b = queries[i][1];

            if (mp.find(a) == mp.end() || mp.find(b) == mp.end()) {
                ans.push_back(-1.0);
                continue;
            }

            ans.push_back(dp[mp[a]][mp[b]]);
        }

    }
};