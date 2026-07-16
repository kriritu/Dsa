class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int sum = nums[0];
        int maxisum = nums[0];
        int n = nums.size();

        for(int i = 1; i<n; i++){
            sum = max(nums[i], sum+ nums[i]);
            maxisum = max(sum, maxisum);
        }

        return maxisum;

  
    }
};