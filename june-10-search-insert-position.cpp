// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (!nums.size() || target < nums.front()) return 0;
        if (target > nums.back()) return nums.size();
        int a = 0, b = nums.size() - 1;
        while (b - a > 1)
        {
            int mid = a + (b - a) / 2;
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) b = mid;
            else if (target > nums[mid]) a = mid;
        }
        if (target == nums[a]) return a;
        return b;
    }
};