class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        if( nums.size()== 0 || nums.size()==1 ){
            return k;
        }
        int prefixsum = 0;
        int left =0;
        int count = 0;
        unordered_map <int, int> freq;
        freq[0] = 1;

        for(int i= 0; i< nums.size(); i++){
            prefixsum += nums[i];
            //checks if sum already exits in the map or not
            if(freq.find(prefixsum-k) != freq.end()){
                count += freq[prefixsum-k];
            }
             freq[prefixsum]++;
        }
        
        return count;
    }
};