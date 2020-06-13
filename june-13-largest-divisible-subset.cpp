// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (!n) return nums;
        vector<int> dp;
        dp.resize(n);
        unordered_map<int, int> um;
        sort(nums.begin(), nums.end());
        dp[0] = 0;
        int totalmax = 0, itotalmax = 0;
        for (int i = 1; i < n; ++i)
        {
            int max = -1;
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[i] % nums[j] == 0 && dp[j] > max)
                {
                    max = dp[j];
                    dp[i] = 1 + dp[j];
                    um[i] = j;
                    if (max == totalmax)
                    {
                        totalmax++;
                        itotalmax = i;
                        break;
                    }
                }
            }
        }
        vector<int> result;
        int i = itotalmax;
        result.push_back(nums[i]);
        while (um.find(i) != um.end())
        {
            i = um[i];
            result.push_back(nums[i]);
        }
        return result;
    }
};