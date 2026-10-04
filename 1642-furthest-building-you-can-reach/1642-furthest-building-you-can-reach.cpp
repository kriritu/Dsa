class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>>pq; //heap can store ladders-used count
        
        for(int i =0; i< heights.size()-1; i++){
            int diff = heights[i+1] - heights[i];
            if(diff <= 0) continue; 

            pq.push(diff);
            if(pq.size() > ladders){
                bricks-= pq.top();
                pq.pop();

                if(bricks < 0) return i; // no bricks left also so stuck at i 
            } //size shows #laders in use, > means assign more ladder than i own so swwitch to bricks
        }
        return heights.size()-1;
    }
};