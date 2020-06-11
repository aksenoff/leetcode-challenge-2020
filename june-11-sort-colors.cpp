// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {        
        int n = nums.size();
        if (!n || n == 1) return;
        int a = 0, b = n - 1, ones = 0, zeros = 0, twos = 0;
        int i = a;
        int cur = nums[i];
        while (a <= b)
            if (cur == 0)
            {
                if (i == a)
                {
                    a++;
                    i++;
                    if (i <= n - 1) cur = nums[i];
                }
                else
                {
                    i = a;
                    b--;
                    cur = nums[i];
                }
                nums[zeros] = 0;
                zeros++;
            }
            else if (cur == 1)
            {
                if (i == a)
                {
                    a++;
                    i++;
                    if (i <= n - 1) cur = nums[i];
                }
                else
                {
                    b--;
                    i--;
                    if (i >= 0) cur = nums[i];
                }
                ones++;
            }
            else 
            {
                if (i == b)
                {
                    b--;
                    i--;
                    if (b >= 0) cur = nums[i];                  
                }
                else
                {
                    i = b;
                    a++;
                    cur = nums[i];
                }
                nums[n - twos - 1] = 2;
                twos++;
            }
        for (int i = zeros; i < zeros + ones; ++i)
            nums[i] = 1;
    }
};