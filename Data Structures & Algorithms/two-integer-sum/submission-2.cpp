class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>hashMap;
        for(int i=0;i<n;i++){
           int sum=target-nums[i];
           if(hashMap.find(sum) !=hashMap.end()){
            return {hashMap[sum],i};
           }
           hashMap[nums[i]]=i;
        }
        return {};

    }
};
