class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>temp;
        int n = profits.size();
        for(int i = 0 ; i < n ; i++){
            temp.push_back({capital[i],profits[i]});
        }
        sort(temp.begin(),temp.end());
        priority_queue<pair<int,int>>hp;
        //now temp is arranged in increasing order of capital
        int i = 0;
        while(k){
            while(i < n && temp[i].first <= w){
                hp.push({temp[i].second,temp[i].first});    //  {profit, captial}
                i++;
            }
            if(hp.empty()){
                break;
            }
            w += hp.top().first;
            hp.pop();
            k--;
        }
        return w;
    }
};