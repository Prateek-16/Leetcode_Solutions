class Solution {
private:
    bool recursionSol(string s1, string s2, string s3, int idx1, int idx2) {
        if(idx1>=s1.size() && idx2>=s2.size()) return true;

        bool flag = false;
        if(idx1<s1.size() && s1[idx1]==s3[idx1+idx2])
            flag |= recursionSol(s1, s2, s3, idx1+1, idx2);
        if(idx2<s2.size() && s2[idx2]==s3[idx1+idx2])
            flag |= recursionSol(s1, s2, s3, idx1, idx2+1);
        
        return flag;
    }

    bool memoizationSol(string s1, string s2, string s3, int idx1, int idx2, vector<vector<int>> &dp){
        if(idx1>=s1.size() && idx2>=s2.size()) return true;

        if(dp[idx1][idx2]!=-1) dp[idx1][idx2]==1? true:false;
        bool nexts1=false, nexts2=false;
        if(idx1<s1.size() && s1[idx1]==s3[idx1+idx2])
            nexts1=memoizationSol(s1, s2, s3, idx1+1, idx2, dp);
        if(idx2<s2.size() && s2[idx2]==s3[idx1+idx2])
            nexts2=memoizationSol(s1, s2, s3, idx1, idx2+1, dp);
        
        dp[idx1][idx2]=(nexts1||nexts2);
        return dp[idx1][idx2]==1? true:false;
    }

    bool tabulationSol(string s1, string s2, string s3){
        int len1=s1.size(), len2=s2.size();
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        dp[len1][len2]=true;    //base case

        for(int idx1=len1; idx1>=0; idx1--){
            for(int idx2=len2; idx2>=0; idx2--){
                if(idx1==len1 && idx2==len2) continue;
                bool nexts1=false, nexts2=false;
                if(idx1<len1 && s1[idx1]==s3[idx1+idx2])
                    nexts1=dp[idx1+1][idx2];
                if(idx2<len2 && s2[idx2]==s3[idx1+idx2])
                    nexts2=dp[idx1][idx2+1];
                
                dp[idx1][idx2]=(nexts1||nexts2);
            }
        }

        return dp[0][0];
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.size(), len2=s2.size();
        if(s3.size()!=len1+len2) return false;
        //return recursionSol(s1,s2,s3,0,0);
        // vector<vector<int>> dp(len1+1, vector<int>(len2+1, -1));
        // return memoizationSol(s1, s2, s3, 0, 0, dp);

        return tabulationSol(s1, s2, s3);
    }
};