class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 +7;
        int even = 1; // no of prev even prefix-sum( 0 - which is even)
        int odd = 0;
        long long  ans =0;
        int curr_parity = 0;

        for(long long i:arr){
            
            if(i %2 != 0){
                curr_parity = 1- curr_parity;
            }
            if(curr_parity ==1){
                ans = (ans+even) %mod;
                odd++;
            }
            else{
                ans= (ans+odd)%mod;
                even++;
            }
        }
        return ans;
    }
};