class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
     unordered_map<int,int>m;
     for(int i=0;i<numbers.size();i++){
        int first=numbers[i];
        int second=target-first;
        if(m.find(second) != m.end()){
            return {m[second]+1,i+1};
        }
        m[first]=i;
     }
     return {};
    }
};
