class Solution {
public:
    void findComb(int ind, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>&ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        // iterate to pick the subarray 
        for(int i =ind; i<candidates.size(); i++){
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]> target) break;
            ds.push_back(candidates[i]);
            findComb(i+1, target-candidates[i],candidates, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // to avoid duplicates & follow order
        vector<vector<int>>ans;
        vector<int>ds;
        findComb(0, target, candidates, ans, ds);
        return ans; 
    }
};