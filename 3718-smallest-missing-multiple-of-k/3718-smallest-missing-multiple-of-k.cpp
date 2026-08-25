class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mul;
        
        for(int i =0; i< nums.size(); i++){
            
            if(nums[i] %k == 0){
                mul[nums[i] /k]++;
            }
        }
        int j =1;
        while(mul.find(j)!= mul.end()){
            j++;
        }

        return j*k;

    }
};