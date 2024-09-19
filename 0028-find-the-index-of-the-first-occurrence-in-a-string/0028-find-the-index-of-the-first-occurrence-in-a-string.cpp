class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        for(int i = 0;i<haystack.size();i++){
            if(haystack[i] == needle[0]){
                bool isMatch = true;
                for(int j = 0; j < needle.size();j++){
                    if(haystack[j + i] != needle[j] ){
                        isMatch = false;
                        break;
                    }
                }
                if(isMatch){
                    return i;
                }
            }
        }
        return index;
        
    }
};