class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //We are doing this in-place so:
        //last-bit ie &1 will contain the previous state
        //second to last bit ie & >> 1 will contain the next state
        
        int m = board.size();
        int n = m ? board[0].size() : 0;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                //Current Box
                int count = 0;
                for(int rn = max(i - 1, 0) ; rn < min(i+2,m);rn++){
                    for(int cn = max(j - 1, 0) ; cn < min(j+2,n);cn++){
                        count += board[rn][cn]&1;
                    }
                }
                count -= board[i][j]&1;
                
                //Rules Check, Dead condition is set by default, we will check if we need to make the cell live in next move
                if(count == 3 || (board[i][j]) && count == 2){
                    board[i][j] |= 2;
                }
            }
        }
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                board[i][j] >>= 1;
            }
        }
        
    }
};