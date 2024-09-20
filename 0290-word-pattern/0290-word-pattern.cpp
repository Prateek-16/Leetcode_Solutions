class Solution {
public:
    void mapping(string& pattern){
        char mapping[26] = {0};
        char start = 'a';
        for(char it : pattern){
            if(mapping[it - 'a'] == 0 ){
                mapping[it - 'a'] = start;
                start++;
            }
        }
        for(int i = 0 ; i < pattern.size() ; i++){
            pattern[i] = mapping[pattern[i] - 'a'];
        }
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char>mp;
        
        char start = 'a';
        
        istringstream ss(s);
        vector<string>vec;
        
        string word;
        while(ss >> word){
            if(mp.find(word) == mp.end()){
                mp[word] = start;
                start++;
            }
            vec.push_back(word);
        }
        mapping(pattern);
        if(vec.size() != pattern.size())
            return false;
        
        for(int i = 0;i<vec.size();i++){
            if(mp[vec[i]] != pattern[i] ){
                return false;
            }   
        }
        return true;
        
        
        
    }
};