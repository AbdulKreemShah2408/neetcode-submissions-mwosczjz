class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>s(nums.begin(),nums.end());
       int longest=0;
       for(int it :s){
        if(!s.count(it-1)){
            int currNum=it;
            int longStreak=1;
            while(s.count(currNum+1)){
                currNum++;
                longStreak++;
            }
            longest=max(longest,longStreak);
        }
        
       }
       return longest;
    }
};
