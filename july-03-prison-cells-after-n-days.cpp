// https://leetcode.com/problems/prison-cells-after-n-days/

class Solution {
    vector<int> int2vector(int input)
    {
        bitset<8> res(input);
        vector<int> result;
        for (int i = 0; i < 8; ++i) result.push_back(res[i]);
        return result;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        bitset<8> bits;
        bitset<8> temp;
        bits[0] = bits[7] = temp[0] = temp[7] = 0;
        for (int j = 1; j < 7; ++j)
            if (cells[j - 1] == cells[j + 1])
                bits[j] = 1;
            else bits[j] = 0;
        int first = bits.to_ulong();
        if (N == 1) return int2vector(first);
        vector<int> vals;
        int test, count = 1;
        do
        { 
            for (int j = 1; j < 7; ++j) 
                if (bits[j - 1] == bits[j + 1]) 
                    temp[j] = 1; 
                else temp[j] = 0;
            test = temp.to_ulong();
            vals.push_back(test);
            bits = temp;
        } while (++count < N && test != first);
        if (count == N) return int2vector(vals.back());
        if (vals.size() == 1) return int2vector(vals[0]);
        return int2vector(vals[(N - 2) % vals.size()]);
    }
};