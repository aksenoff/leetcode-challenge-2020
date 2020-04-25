// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // TLE:
        //if (nums.size() == 1) return true;
        //for (int i = nums.size() - 2; i >= 0; --i)
        //{
        //    if (nums[i] == 0 || nums[i] == 1) continue;
        //    for (int j = 1; (j < nums[i]) && (i + j < nums.size() - 1); ++j) nums[i + j]++;
        //}
        //for (int i = nums.size() - 2; i >= 0; --i)
        //    if (!nums[i]) return false;
        //return true;
        if (nums.size() == 1) return true;
        if (!nums[0]) return false;
        nums[nums.size() - 1] = 1;
        for (int i = nums.size() - 1; i >= 2; --i)
        {
            if (nums[i] && !nums[i - 1])
            {
                bool flag = false;
                for (int j = i - 2; j >= 0; --j)
                    if (j + nums[j] >= i)
                    {
                        flag = true;
                        break;
                    }
                if (!flag) return false;
            }
        }
        return true;
    }
};