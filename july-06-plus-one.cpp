// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i)
            if (digits[i] < 9)
            {
                ++digits[i];
                return digits;
            }
            else
            {
                digits[i] = 0;
                if (!i)
                {
                    vector<int> result = { 1 };
                    result.insert(result.end(), digits.begin(), digits.end());
                    return result;
                }
            }
        return {};
    }
};