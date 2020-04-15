// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int izero = 0, inonzero;
        while (izero < nums.size() && nums[izero] != 0)
        {
            ++izero;
        }
        inonzero = izero;
        while (izero < nums.size())
        {
            while (izero < nums.size() && nums[izero] != 0)
            {
                ++izero;
            }
            while (inonzero < nums.size() && nums[inonzero] == 0)
            {
                ++inonzero;
            }
            if (inonzero != nums.size())
            {
                nums[izero] = nums[inonzero];
                nums[inonzero] = 0;
            }
            ++izero;
        }
    }
};