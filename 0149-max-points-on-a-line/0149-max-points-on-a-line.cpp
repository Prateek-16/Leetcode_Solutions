class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)  return points.size();
        
        int maxi = 1;
        
        for(int i = 0;i<n;i++){
            unordered_map<double,int>mp;
            for(int j = i + 1 ; j < n ;j++){
                
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int dy = y2 - y1;
                int dx = x2 - x1;
                
                double slope = 0.0;
                
                if(dx == 0){    //points are vertical
                    slope = INT_MAX;
                }
                else{
                    slope = double(dy) / dx;
                }
                
                mp[slope]++;
            }
            for(auto it : mp){
                maxi = max(maxi , it.second);
            }
        }
        return maxi + 1;
    }
};