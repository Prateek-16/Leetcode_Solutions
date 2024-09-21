class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(char it : t){
            mp[it]++;
        }
        
        int start = 0;
        int end = 0;
        
        int n = s.size();
        int len = INT_MAX;
        int counter = t.size();
        int max_string_ind = 0;

        while(end < n){
            if(mp[s[end]] > 0){
                counter--;
            }
            
            mp[s[end]]--;
            end++;
            
            while(counter == 0){
                if(end - start < len){
                    len = end - start;
                    max_string_ind = start;
                }
                
                mp[s[start]]++;
                
                if(mp[s[start]] > 0){
                    counter++;
                }
                
                start++;   
            }
        }
        
        return len != INT_MAX ? s.substr(max_string_ind,len) : "";
    }
};