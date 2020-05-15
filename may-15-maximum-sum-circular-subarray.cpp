// https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0, currentsum = 0, maxsum = -31000, bigsum = -31000;
        int n = A.size();
        vector<int> sums(n);
        for (int i = n - 1; i >= 0; --i)
        {
            sum = max(A[i], sum + A[i]); // maximum sum beginning with current element
            maxsum = max(maxsum, sum); 
            currentsum += A[i]; // sum from current to end
            bigsum = max(bigsum, currentsum); // maximum sum on the part starting with current element that lasts to the end
            sums[i] = bigsum;
        }
        A.insert(A.end(), A.begin(), A.end());
        currentsum = 0;
        for (int i = n; i < 2 * n - 1; ++i)
        {
            currentsum += A[i];
            sum = max(A[i], sums[i - n + 1] + currentsum); // maximum sum lasting to the end starting on i-n+1 or later + sum from the beginning to i included
            maxsum = max(maxsum, sum);            
        }
        return maxsum;
    }
};