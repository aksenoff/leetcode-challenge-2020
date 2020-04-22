// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums;
        int sum = 0, count = 0;
        for (auto num : nums)
        {
            sum += num;
            sums.push_back(sum);
            if (sum == k) count++;
        }
        if (nums.size() == 1) return count;
        for (int i = 0; i < nums.size() - 1; ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (sums[j] - sums[i] == k) count++;
        return count;
    }
};