// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        set<pair<int, int>> seen;
        unordered_map<int, int> nums_map;
        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) nums_map[nums[i]]++;
        int third;
        for (int i = 0; i < n && nums[i] <= 0; ++i)
            for (int j = i + 1; j < n && nums[i] + nums[j] <= 0; ++j)
            {
                third = -nums[i] - nums[j];
                if (nums_map[third] != 0 && third > nums[j] 
                    || nums_map[third] > 1 && third == nums[j] && third != 0 
                    || nums_map[third] > 2 && third == nums[j] && third == 0)
                    if (seen.find({ nums[i], nums[j]}) == seen.end())
                    {
                        seen.insert({ nums[i], nums[j] });
                        result.push_back({ nums[i], nums[j], third });
                    }
            }
        return result;
    }
};