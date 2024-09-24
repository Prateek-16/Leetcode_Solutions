class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>wordCount;
        for(auto word : words){
            wordCount[word]++;
        }
        
        vector<int>ans;
        int k = words[0].size();
        int n = words.size();
        
        for(int i = 0; i < k ; i++){
            unordered_map<string,int>seen;
            int left = i;
            int right = i;
            int totalCount = 0;
            
            while(right + k <= s.size()){
                string str = s.substr(right,k);
                right += k;
                
                if(!wordCount.count(str)){
                    seen.clear();
                    left = right;
                    totalCount = 0;
                    continue;
                }
                
                seen[str]++;
                totalCount++;
                
                while(seen[str] > wordCount[str]){
                    string removeStr = s.substr(left,k);
                    left += k;
                    seen[removeStr]--;
                    totalCount--;
                }
                
                if(totalCount == n){
                    ans.push_back(left);
                }
            }
            
        }
     
        return ans;
    }
};