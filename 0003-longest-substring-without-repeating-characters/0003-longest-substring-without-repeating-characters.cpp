class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        fill(begin(last), end(last), -1); //-1 means never seen here
        int left = 0, best = 0;

        for(int right = 0; right< (int)s.size(); right++){
            unsigned char c = s[right];

            if(last[c] >= left){  //-1 >= 0 ->false(not seen before), 
                left = last[c] +1; // jump left (if seen then jump left's pos)   
            }
            
            last[c] = right; // write on which index we saw char "c"
            best = max(best, right-left+1);
        }
        return best;
        
    }
};