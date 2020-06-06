// https://leetcode.com/problems/random-pick-with-weight/

class Solution {
    uniform_int_distribution<> *dist;
    random_device* rd;
    mt19937* gen;
    // int counter;
    int n;
    int size;
    vector<int> v;
public:
    Solution(vector<int>& w) {
        // counter = 0;
        n = 0;
        size = w.size();
        v.reserve(size);
        for (int i = 0; i < size; ++i)
        {
            n += w[i];
            v.push_back(n);
        }
        rd = new random_device;
        gen = new mt19937((*rd)());
        dist = new uniform_int_distribution<>(1, n);
    }

    int pickIndex() {
        int x = (*dist)(*gen);
        // int x = counter++ % n + 1; // not random , but kinda
        int a = 0, b = size - 1;
        while (a < b)
        {
            int cur = a + (b - a) / 2;
            if (v[cur] >= x)
            {
                if (cur == a || v[cur - 1] < x) return cur;
                else b = cur - 1;
            }
            else a = cur + 1;
        }
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */