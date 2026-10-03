class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        long long maxI = 0;
        long long maxDiff = 0;
        long long ans =0;
        for(int x: nums){
            ans = max(ans, maxDiff*x); //k
            maxDiff = max(maxDiff, maxI-x); //j 
            maxI = max(maxI, (long long) x); //i
        }
        return ans;
    }
};