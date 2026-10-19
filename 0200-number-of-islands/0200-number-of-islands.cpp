class Solution {
public:
    void bfs(int ro, int co, vector<vector<int>>&vis, vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[ro][co] = 1;
        queue<pair<int, int>>q;
        q.push({ro, co});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // we don't have to count diagonal as connected components, only up, down, left, right
            int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, 1, 0, -1};

            for(int k = 0; k < 4; k++){

                int nrow = row + dr[k];
                int ncol = col + dc[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int row =0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col, vis, grid);
                }
            }
        }
        return cnt;   
    }
};