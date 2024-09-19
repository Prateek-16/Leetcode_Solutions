class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream ss(s);
        string word;
        int len = 0;
        while(ss >> word){
            len = word.length();
            
        }
        return len;
        
    }
};