class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n = s.size();
        int start = 0;
        int end = 0;
        int len = 0;
        while(end < n){
            char curr = s[end];
            if(mp.find(curr) != mp.end()){
                start = max(start, mp[curr] + 1);   //Moving the start of the window
            }
            mp[curr] = end;
            len = max(len , end - start + 1);
            end++;
        }
        return len;
    }
};