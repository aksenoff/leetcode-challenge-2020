// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products;
        int product = 1;
        products.push_back(product);
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            product *= nums[i];
            products.push_back(product);
        }
        product = 1;
        for (int i = nums.size() - 1; i > 0; --i)
        {
            product *= nums[i];
            products[i - 1] *= product;
        }
        return products;
    }
};