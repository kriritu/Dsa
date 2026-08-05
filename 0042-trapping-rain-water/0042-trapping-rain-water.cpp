class Solution {
public:
    vector<int> leftmax(vector<int>&height){
        if(height.empty()) return {};
        vector<int> prefix(height.size());
        prefix[0] = height[0];

        for(int i= 1; i< height.size(); i++){
            prefix[i] = max(prefix[i-1], height[i]);
        }
        return prefix;
        
    }

    vector<int> rightmax(vector<int>&height){
        int n = height.size();
        vector<int> suffix(height.size());
        suffix[n-1] = height[n-1];
        
        for(int i= n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }
        return suffix;
    }
    int trap(vector<int>& height) {
        int n = height.size();

        vector <int> left = leftmax(height) ;
        vector <int> right = rightmax(height);
        int total = 0;
        
        for(int i=0; i<n; i++){
            total += min(left[i] , right[i])- height[i];
        }
        return total;
        
    }
};