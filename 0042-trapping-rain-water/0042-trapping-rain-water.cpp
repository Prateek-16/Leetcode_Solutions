class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int>LeftMax(n);
        vector<int>RightMax(n);
        
        for(int i = 0;i<n;i++){
            LeftMax[i] = i == 0 ? height[i] : max(height[i] , LeftMax[i - 1]);      //whenever there is no leftMax we treat height[i] as LeftMax
        }
        
        for(int i = n-1 ; i>=0;i--){
            RightMax[i] = i == n -1 ? height[i] : max(height[i] , RightMax[i + 1]); //whenever there is no rightMax we treat height[i] as rightMax
        }
        
        int ans = 0;
        
        for(int i = 0; i<n;i++){
            ans += min(LeftMax[i],RightMax[i]) - height[i];            
        }
        
        return ans;
    }
};