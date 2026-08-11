
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>hashset;
        for(int i=0;i<n;i++){
          if(hashset.find(nums[i]) != hashset.end()){
            return true;
          }
            hashset.insert(nums[i]);

        }
        return false;
    }
};