// https://leetcode.com/problems/h-index-ii/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (!n) return 0;
        if (n == 1) return citations[0] == 0 ? 0 : 1;
        int a = 0, b = n - 1, mid;
        while (b > a)
        {
            mid = a + (b - a) / 2 + 1;
            if (citations[mid] >= n - mid)
            {
                if (citations[mid - 1] < n - mid + 1) return n - mid;
                else
                    if (mid != 0) b = mid - 1;
                    else return n;
                    
            }
            else 
                if (mid + 1 != n) a = mid + 1;
                else return 0;
        }
        return n - a;
    }
};