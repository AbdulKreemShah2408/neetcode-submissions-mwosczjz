class Solution {
public:
  vector<vector<int>>result;
  void backtrack(vector<int>& nums,vector<int>&current,int target,int start){
    if(target==0){
        result.push_back(current);
    }
    if(target<0){
        return;
    }
    for(int i=start;i<nums.size();i++){
        current.push_back(nums[i]);
        backtrack(nums,current,target-nums[i],i);
        current.pop_back();
    }
  }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>current;
        backtrack(nums,current,target,0);
        return result;
    }
};
