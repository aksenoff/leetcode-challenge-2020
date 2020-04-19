// https://leetcode.com/problems/search-in-rotated-sorted-array/

int find_pivot(vector<int>& nums, int a, int b)
{
    if (b - a == 1) return nums[a] < nums[b] ? a : b;
    int mid = a + (b - a) / 2;
    if (nums[a] < nums[mid] && nums[mid] > nums[b])
        return find_pivot(nums, mid, b);
    else if (nums[a] > nums[mid] && nums[mid] < nums[b])
        return find_pivot(nums, a, mid);
    else return a;
}

int bin_search(vector<int>& nums, int b, int e, int elem)
{
    while (b <= e)
    {
        int mid = b + (e - b) / 2;
        if (nums[mid] == elem) return mid;
        if (nums[mid] > elem) e = mid - 1;
        else b = mid + 1;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        int pivot = find_pivot(nums, 0, nums.size() - 1);
        if (pivot == 0) return bin_search(nums, 0, nums.size() - 1, target);
        nums.insert(nums.end(), nums.begin(), nums.end());
        int result = bin_search(nums, pivot, pivot + nums.size() / 2 - 1, target);
        return (result == -1 ? -1 : result % (nums.size() / 2));
    }
};