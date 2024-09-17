class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i = m ; i<nums1.size();i++){
            nums1[i] = nums2[j];
            j++;
        }
        //Shell Sort

        int total_len = m + n;

        int gap = (total_len / 2) + (total_len % 2);

        while(gap){
            int ptr1 = 0;
            int ptr2 = ptr1 + gap;

            while(ptr2 < nums1.size()){
                if(nums1[ptr1] > nums1[ptr2]){
                    swap(nums1[ptr1],nums1[ptr2]);
                }
                ptr1++;
                ptr2++;
            }

            gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
        }
        
    }
};