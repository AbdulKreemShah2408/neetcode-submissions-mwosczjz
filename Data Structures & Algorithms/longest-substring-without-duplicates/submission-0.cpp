class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int maxLength=0;
        unordered_map<char,int>mp;
        if(s.size()<2){
            return s.size();
        }
        while(right<s.size()){
            char currChar=s[right];
            if(mp.find(currChar)==mp.end() || mp.find(currChar)->second<1){
                mp[currChar]=1;
                right++;
                maxLength=max(right-left,maxLength);
            }else{
                mp[s[left]]--;
                left++;

            }
            
        }
        return maxLength;
    }
};
