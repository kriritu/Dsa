class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        int sum = 0;
        int x;

        for(int i = 0; i<operations.size(); i++){
            if(operations[i]== "+"){
                int last = record[record.size() - 1];
                int prev_last = record[record.size() - 2];
                record.push_back(last + prev_last);
            } 
           
            else if (operations[i]== "D"){
                int last= record.back();
                record.push_back(last*2);

            } 
            else if(operations[i]== "C"){
                record.pop_back();
            }
            else{
                record.push_back(stoi(operations[i]));

            }
        }
        for(int i: record){
            sum+= i;
        }
        return sum;
 
    }
};