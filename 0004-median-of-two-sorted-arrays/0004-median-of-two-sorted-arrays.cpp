class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int n = n1 + n2;

        int ind2 = n / 2;
        int ind1 = ind2 - 1;

        int ind1_val = 0;
        int ind2_val = 0;

        int count = 0; // this will be the current index when it reaches the
                       // required index we will stop

        int i = 0;
        int j = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {

                if (count == ind1) {
                    ind1_val = nums1[i];
                }
                if (count == ind2) {
                    ind2_val = nums1[i];
                }
                count++;
                i++;
            } else {
                if (count == ind1) {
                    ind1_val = nums2[j];
                }
                if (count == ind2) {
                    ind2_val = nums2[j];
                }
                count++;
                j++;
            }
        }
        while (i < n1) {

            if (count == ind1) {
                ind1_val = nums1[i];
            }
            if (count == ind2) {
                ind2_val = nums1[i];
            }
            count++;
            i++;
        }

        while (j < n2) {

            if (count == ind1) {
                ind1_val = nums2[j];
            }
            if (count == ind2) {
                ind2_val = nums2[j];
            }
            count++;
            j++;
        }

        if (n & 1) {
            return (double)(ind2_val);
        } else {
            return ((double)(ind1_val + ind2_val)) / 2;
        }
    }
};