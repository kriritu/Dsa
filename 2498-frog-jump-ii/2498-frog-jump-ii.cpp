class Solution {
public:
    int maxJump(vector<int>& stones) {
        int jump_max = stones[1] - stones[0];

        for(int i = 2; i < stones.size(); i++){
            jump_max = max(jump_max, stones[i]-stones[i-2]);
        }
        return jump_max; 
    }
};