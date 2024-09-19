class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }
        
        vector<string>vec(numRows,"");
        int direction = 1;  //1 for Up , -1 for Down
        int index = 0;
        
        for(int i = 0;i<s.size();i++){
            
            vec[index].push_back(s[i]);
            
            if(index == 0){
                direction = 1;  //Move Up
            }
            else if(index == numRows - 1){
                direction = -1; //Move Down
            }
            index += direction;
        }
        
        string ans;
        for(const string& row : vec){
            ans += row;
        }
        return ans;
        
    }
};