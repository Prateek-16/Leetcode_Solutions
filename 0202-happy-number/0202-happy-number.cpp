class Solution {
public:
    
    int squareSum(int n){
        int ans = 0;
        while(n > 0){
            int lastDig = n % 10;
            n /= 10;
            ans += lastDig * lastDig;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        unordered_set<int>st;
        while(!st.contains(n)){
            st.insert(n);
            n = squareSum(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
};