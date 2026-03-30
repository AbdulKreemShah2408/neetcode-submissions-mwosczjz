class Solution {
public:
    vector<string>result;
     vector<string> digitsMap={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void backtrack(const string & digits,string & current,int index){
      if(index>=digits.length()){
        if(!current.empty()){
        result.push_back(current);
        }
        return;
      }
      int digit=digits[index]-'0';
      string letters=digitsMap[digit];
      for(char letter:letters){
        current +=letter;
        backtrack(digits,current,index+1);
        current.pop_back();
      }

         
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return result;
        }
        string current;
        backtrack(digits,current,0);
        return result;
    }
};
