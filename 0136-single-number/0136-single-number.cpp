class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        int single;
        for(int i =0; i<=nums.size()-1; i++){
            XOR = XOR ^ nums[i];
        }

        return XOR;
        
    }
};