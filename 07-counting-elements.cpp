class Solution {
public:
    int countElements(vector<int>& arr) {
        set<int> intset;
        int count = 0;
        for (auto& el : arr)
        {
            intset.insert(el);
        }
        for (auto& el : arr)
        {
            if (intset.find(el + 1) != intset.end()) count++;
        }
        return count;
    }
};