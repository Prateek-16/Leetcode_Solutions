class Solution {
public:
    int romanToInt(string s) {
        //In Roman numerals, when a smaller value appears before a larger value, it represents subtraction, 
        //while when a smaller value appears after or equal to a larger value, it represents addition.
        
        unordered_map<char,int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0;i<s.length();i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
        
    }
};