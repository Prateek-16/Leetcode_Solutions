class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>st;
        for(int i = 0;i<intervals.size();i++){
            if(st.empty()){
                st.push_back(intervals[i]);
                continue;
            }
            if(intervals[i][0] <= st.back()[1]){
                st.back()[1] = max(st.back()[1],intervals[i][1]);
            }
            else{
                st.push_back(intervals[i]);
            }
        }
        return st;
    }
};