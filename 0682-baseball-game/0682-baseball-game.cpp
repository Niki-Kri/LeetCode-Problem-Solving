class Solution{
public:
    int calPoints(vector<string>& operations){
        vector<int>record;
        for(const string& op:operations){
            if(op=="+"){
                int last=record.back();
                int secondLast=record[record.size()-2];
                record.push_back(last+secondLast);
            }else if(op=="D"){
                record.push_back(2*record.back());
            }else if(op=="C"){
                record.pop_back();
            }else{
                record.push_back(stoi(op));
            }
        }
        int totalSum=0;
        for(int score:record){
            totalSum+=score;
        }
        return totalSum;
    }
};