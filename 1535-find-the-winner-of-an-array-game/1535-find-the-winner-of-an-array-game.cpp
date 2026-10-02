class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        int winner = arr[0];
        int win_count =0;
        int n = arr.size();

        for(int i = 1; i<n; i++){
            if(winner> arr[i]){
                win_count++;
            }
            else{
                winner = arr[i];
                win_count = 1;
            }
            if(win_count ==k ) return winner;
        }
        return winner;

    }
};