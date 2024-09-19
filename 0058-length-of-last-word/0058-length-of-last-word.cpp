class Solution {
public:
    int lengthOfLastWord(string s) {
        // Time complexity O(n) Space complexity O(n)
        
        istringstream ss(s);
        string word;
        int len = 0;
        while(ss >> word){
            len = word.length();
            
        }
        return len;
        
        //Another beeter approach will be to loop from end, skip all trailing " " and then find the length of the last word
        // TC - O(n)    SC - O(1)
    }
};