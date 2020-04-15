// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        int ans = n, digit;
        bool happy = false;
        for (size_t i = 0; i < 1000; i++)
        {
            int digit_square_sum = 0;
            while (ans)
            {
                digit = ans % 10;
                digit_square_sum += digit * digit;
                ans /= 10;
            }
            if (digit_square_sum == 1)
            {
                happy = true;
                break;
            }
            ans = digit_square_sum;
        }
        return happy;
        
    }
};