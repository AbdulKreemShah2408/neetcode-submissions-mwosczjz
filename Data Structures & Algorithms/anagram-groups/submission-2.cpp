class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string,vector<string>>hashMap;
     for(auto it:strs){
       string temp=it;
       sort(it.begin(),it.end());
       hashMap[it].push_back(temp);
     }
     vector<vector<string>>ans;
     for(auto x:hashMap){
        ans.push_back(x.second);
     }
     return ans;

    }
};
