// https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (!k) return num;
        if (k == num.size()) return "0";
        int erases = 0;
        for (int i = 0; i < num.size() - 1 && erases < k; ++i)
        {
            if (num[i] > num[i + 1])
            {
                num.erase(i, 1);
                erases++;
                i -= i ? 2 : 1;
            }
        }
        while (erases++ < k) 
            num.erase(num.size() - 1, 1);
        int pos = num.find_first_not_of('0');
        return pos != string::npos ? num.substr(pos) : "0";
    }
};