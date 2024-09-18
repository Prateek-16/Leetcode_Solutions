
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        for (int i = 0; i < n; ++i) {
            if (n - i <= citations[i]) {
                return n - i;
            }
        }
        return 0;
    }
};
