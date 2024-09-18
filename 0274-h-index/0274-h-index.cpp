class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());  // Sort in descending order
        for (int i = 0; i < n; ++i) {
            if (citations[i] < i + 1) {
                return i;
            }
        }
        return n;
    }
};

