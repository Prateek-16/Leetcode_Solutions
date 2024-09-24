class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<int>prev = points[0];
        int count = 1;
        
        for(int i = 1;i<points.size();i++){
            int currStarting = points[i][0];
            int currEnding = points[i][1];
            
            //int prevStarting = prev[0];
            int prevEnding = prev[1];
            
            if(prevEnding < currStarting){
                //Definately new interval
                count++;
                prev = points[i];
            }
            else{
                //prev[0] = max(currStarting,prevStarting);
                prev[1] = min(currEnding,prevEnding);
            }
        }
        return count;
    }
};