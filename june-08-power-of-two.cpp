// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
		if (n <= 0) return false;
		int result = 0;
		for (int i = 0; i < 32; ++i)
		{
			result += (n >> i) & 1;
		}
		return result == 1;    
    }
};