class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>hashMap;
        int n=nums.size();
        for(int i=0;i<n;i++){
          hashMap[nums[i]]++;
        }
         vector<pair<int,int>>freq;
         for(auto it:hashMap){
            freq.push_back({it.second,it.first});
         }
         sort(freq.begin(),freq.end());
         vector<int>result;
         for(int i=freq.size()-1;i>=0 && k>0; i--,k--){
            result.push_back(freq[i].second);
         }
         return result;
         
    }
};
