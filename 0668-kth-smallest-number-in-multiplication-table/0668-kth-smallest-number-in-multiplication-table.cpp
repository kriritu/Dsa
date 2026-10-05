class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int hi = n*m;
        int lo = 1; 
        while(lo < hi){
            int mid = lo + (hi -lo)/2;
            int cnt = 0;

            for(int i =1; i<=m; i++){
                cnt += min(mid/i, n); //#table values<=k
            }
            if(cnt >= k) hi = mid;
            else lo = mid+1;
        }
        return lo;
        
    }
};