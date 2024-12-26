class Solution {
public:
    void checkPalindrome(string s , int start , int end , int& maxLen , int& index){
        while(start >= 0 && end < s.length() && s[start] == s[end]){
            start--;
            end++;
        }
        if(end - start - 1 > maxLen){
            maxLen = end - start - 1;
            index = start + 1;
        }
        
    }
    string longestPalindrome(string s) {
        int index = 0;
        int maxLen = 1;
        for(int i = 0; i < s.length() - 1 ; i++){
            checkPalindrome(s,i,i,maxLen,index);    //odd Palindromes
            checkPalindrome(s,i,i+1,maxLen,index);  //Even Palindromes  
        }
        return s.substr(index , maxLen);
        
    }
};