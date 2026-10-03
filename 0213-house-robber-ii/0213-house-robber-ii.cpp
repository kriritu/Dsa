class Solution {
public:
    int robI(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==1) return nums[0];
        vector<int> temp1; // contains all except first part
        vector<int>temp2;

        for(int i =0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!= n-1) temp2.push_back(nums[i]);
        }
        return max(robI(temp1), robI(temp2));
    }
};