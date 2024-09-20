class Solution {
public:
    void mapping(string &s){
        char mapping[256] = {0};
        char start = 'a';
        
        //Mapping
        for(char it : s){
            if(mapping[it] == 0){
                mapping[it] = start;
                start++;
            }
        }
        //Replacement
        for(int i = 0;i<s.size();i++){
            s[i] = mapping[s[i]];
        }
    }
    
    bool isIsomorphic(string s, string t) {
        mapping(s);
        mapping(t);
        
        return s == t;
        
    }
};