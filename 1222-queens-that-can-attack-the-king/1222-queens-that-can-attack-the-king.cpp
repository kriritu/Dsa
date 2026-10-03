class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        //lookup for queens pos so that it takes O(1) time
        bool isqueen[8][8] = {};
        for(auto &q: queens) isqueen[q[0]][q[1]] = true;

        vector<vector<int>>res;

        for(int dr= -1; dr<= 1; dr++){
            for(int dc= -1; dc<=1; dc++){
                if(dr==0 && dc==0) continue;

                int r = king[0] +dr;
                int c = king[1] +dc;

                while(r>=0 && r<8 && c>=0 && c<8){
                    if(isqueen[r][c]){
                        res.push_back({r,c});
                        break; //she blocks everything behind her
                    }
                    r += dr;
                    c += dc;
                }
               
            }
        } 
        return res;
    }
};