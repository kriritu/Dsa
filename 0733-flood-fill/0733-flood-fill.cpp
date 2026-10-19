class Solution {
public:
    void dfs(vector<vector<int>>&ans, vector<vector<int>>&image, int color, int sr, int sc, int delr[], int delc[], int inicolor){
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i= 0; i<4; i++){
            int nrow = sr + delr[i];
            int ncol = sc + delc[i];

            if(nrow>=0 && nrow<n && ncol>= 0 && ncol<m && image[nrow][ncol]== inicolor && ans[nrow][ncol]!= color ){
                dfs(ans, image,color, nrow,ncol, delr, delc,inicolor);
            }

        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>ans = image;
        int initialColor = image[sr][sc];
        int delr[] = {-1, 0,+1, -0};
        int delc[] = {+0, +1,0,-1};
        dfs(ans, image,color, sr,sc,delr, delc,initialColor);
        return ans;
        
    }
};