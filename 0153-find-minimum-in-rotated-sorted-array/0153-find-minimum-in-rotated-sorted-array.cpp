class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            if (nums[l] < nums[r])   // Our solution would not work on a completely sorted array
            {
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);

            if (nums[mid] >= nums[l]) // mid present in left sorted array
            {
                l = mid + 1; // try to move closer to right sorted array
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
};
