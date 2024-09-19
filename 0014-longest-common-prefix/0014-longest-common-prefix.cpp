class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int index = 0;
        char curr;
        string ans = "";
        bool stop = false;
        while(true){
            
            curr = strs[0][index];
            
            for(int i=0;i<n;i++){
                if(index >= strs[i].length()){
                    stop = true;
                }
                if(strs[i][index] != curr){
                    stop = true;
                }
            }
            if(stop){
                break;
            }
            ans.push_back(curr);
            index++;
        }
        return ans;
    }
};