class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1; // Vector tracks its own size
        while (l < r) {
            std::swap(s[l], s[r]); // Idiomatic C++ swap function
            l++;
            r--;
        
        }
    }
};