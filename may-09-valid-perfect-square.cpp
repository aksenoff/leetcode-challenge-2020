// https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long guess = 1;
        while (guess * guess < num) guess++;
        return (guess * guess == num ? true : false);
    }
};