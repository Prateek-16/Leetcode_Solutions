class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int n = words.size();
        for(int i = 0; i < n ;){
            vector<string>currRow = {words[i]};
            int currRow_len = words[i].length();
            i++;
            
            //Adding Possible words in currRow
            while(i < n && currRow_len + 1 + words[i].length() <= maxWidth){
                currRow.push_back(words[i]);
                currRow_len += 1 + words[i].length();
                i++;
            }
            
            //Edge case of currRow with 1 word or lastRow
            if(i == n || currRow.size() == 1){
                string currRow_string = currRow[0];
                
                for(int j =1;j<currRow.size();j++){
                    currRow_string += " " + currRow[j];
                }
                
                string trailingSpaces = string(maxWidth - currRow_string.size(),' ');
                currRow_string += trailingSpaces;
                ans.push_back(currRow_string);
                continue;
            }
            
            //Normal Cases
            int total_spaces = (maxWidth - currRow_len) + currRow.size() - 1;
            int space_between = total_spaces / (currRow.size() - 1);
            int extra_spaces = total_spaces % (currRow.size() - 1);
            
            string row;
            for(int j = 0;j<currRow.size() - 1;j++){
                row += currRow[j] + string(space_between + (j < extra_spaces ? 1 : 0),' ');
            }
            row += currRow.back();
            ans.push_back(row);
        }
        return ans;
        
    }
};