class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>seen;

        for(int i =0; i<n; i++){
            int needed = target -nums[i];
            if(seen.count(needed)){
                return {seen[needed], i};
            }
            seen[nums[i]] =i;
        }
        return {};
    
    }
};