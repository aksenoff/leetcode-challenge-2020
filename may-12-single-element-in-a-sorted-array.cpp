// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a = 0, b = nums.size() - 1, mid;
        while (a < b)
        {
            mid = a + (b - a) / 2;
            if (mid % 2)
            {
                if (nums[mid] != nums[mid + 1]) a = mid + 1;
                else b = mid - 1;
            }
            else
            {
                if (nums[mid] == nums[mid + 1]) a = mid + 2;
                else if (nums[mid] == nums[mid - 1]) b = mid - 2;
                else return nums[mid];
            }
        }
        return nums[a];
    }
};