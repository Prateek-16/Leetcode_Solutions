class Solution {
public:
    
    void solve(string digits ,string mapping[], vector<string>&ans , int index , string comb){
        if(index >= digits.size()){
            if(comb.length() > 0)   
                ans.push_back(comb);
            return;
        }
        int num = digits[index] - '0';
        string combinations = mapping[num];
        for(auto it : combinations){
            comb.push_back(it);
            solve(digits,mapping,ans,index + 1, comb);
            comb.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string mapping[] = {"",    "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string comb = "";
        int index = 0;
        solve(digits,mapping,ans,index,comb);
        return ans;
    }
};