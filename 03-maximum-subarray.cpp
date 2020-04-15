// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long sum = 0, maxsum = -2147483648;
        vector<long>sumstart;
        for (auto elem : nums)
        {
            sum += elem;
            sumstart.push_back(sum);
        }
        for (int i = 0; i < sumstart.size(); i++)
        {
            for (int j = sumstart.size()-1; j >= i; j--)
            {
                if (sumstart[j] - sumstart[i] + nums[i] > maxsum) maxsum = sumstart[j] - sumstart[i] + nums[i];
            }
        }
        return maxsum;
    }
};