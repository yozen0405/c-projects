#include <bits/stdc++.h>
int d[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty()) return mat;
        queue<pair<int,int>> q;
        int r=mat.size(),c=mat[0].size();
        vector<vector<int>> dis(r, vector<int> (c, INT_MAX));
        for(int i=0;i<mat.size();i++){
            if(c<mat[i].size()) c=mat[i].size();
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;   
                }
                
            }
        }
        
        while(q.size()){
            pair<int,int> front=q.front();
            q.pop();
            for(auto [u,v]:d){
                int nx=front.first+u,ny=front.second+v;
                if(nx>=r||nx<0||ny>=c||ny<0) continue;
                if(dis[nx][ny]>=dis[front.first][front.second]+1){
                    q.push({nx,ny});
                    dis[nx][ny]=dis[front.first][front.second]+1;
                }
                    
            }
        }
        return dis;
    }
};
