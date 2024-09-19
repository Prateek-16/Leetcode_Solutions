class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word;
        vector<string>vec;
        while(ss >> word){
            vec.push_back(word);
        }
        string ans = "";
        int n = vec.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            ans += vec[i];
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
        
    }
};