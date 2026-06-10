#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int n=grid.size();
       vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
       dist[0][0]=grid[0][0];
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       dist[0][0]=grid[0][0];
       pq.push({grid[0][0],{0,0}});
       int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
       while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        int cost=curr.first;
        int r=curr.second.first;
        int c=curr.second.second;
        if(r==n-1 && c==n-1)return cost;
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 &&nr<n && nc>=0 &&nc<n){
                int newcost=max(cost,grid[nr][nc]);
                if(newcost<dist[nr][nc]){
                    dist[nr][nc]=newcost;
                    pq.push({newcost,{nr,nc}});
                }
            }
        }
       
       }
       return -1;
    }
};