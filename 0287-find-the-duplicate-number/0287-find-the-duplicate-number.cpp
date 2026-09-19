class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        unordered_map<int, int> mp;
        for(int n : nums){
            mp[n]++;
        }
        for(auto& pair: mp){
            if(pair.second >1){
                ans = pair.first;
                break;
            }
        }
        return ans;
    }
};