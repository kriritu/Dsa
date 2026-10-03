class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2= 0;
        int take;
        int not_take;
        int curr;
        
        for(int i =1; i<n; i++){
            take = nums[i]; 
            if(i>1) take+= prev2;
            not_take = 0 + prev;

            curr=  max(take, not_take); 
            prev2 = prev;
            prev = curr;
        }
        return prev;   
    }
};