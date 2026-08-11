class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() !=t.length()) return false;
        unordered_map<char,int>hashMap;
        for(char i:s){
         hashMap[i]++;
        }

        for(char i:t){
            if(hashMap.find(i) ==hashMap.end() || hashMap[i]==0){
                return false;
            }
            hashMap[i]--;
        }
        return true;

    }
};
