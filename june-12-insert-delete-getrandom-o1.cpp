// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
    uniform_int_distribution<>* dist;
    random_device* rd;
    mt19937* gen;
    map<int, int> m;
    vector<int> vi;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        rd = new random_device;
        gen = new mt19937((*rd)());
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        vi.push_back(val);
        m[val] = vi.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        dist = new uniform_int_distribution<>(0, vi.size() - 1);
        int x = (*dist)(*gen);
        while (m.find(vi[x]) == m.end())
        {
            x = (*dist)(*gen);
        }
        return vi[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */