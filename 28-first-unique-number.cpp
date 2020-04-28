class FirstUnique {
    map<int, int> numbered_uniques; // <priority, element>
    map<int, int> inversed_uniques; // <element, priority>
    set<int> uniques;
    set<int> non_uniques;
    int max;
public:
    FirstUnique(vector<int>& nums) {
        max = 0;
        for (auto el : nums)
            add(el);
    }

    int showFirstUnique() {
        return (uniques.size() ? (*numbered_uniques.begin()).second : -1);
    }

    void add(int value) {
        if (uniques.find(value) != uniques.end())
        {
            uniques.erase(value);
            int bye = inversed_uniques[value];
            inversed_uniques.erase(value);
            numbered_uniques.erase(bye);
            non_uniques.insert(value);
        }
        else if (non_uniques.find(value) == non_uniques.end())
        {
            uniques.insert(value);
            numbered_uniques[max] = value;
            inversed_uniques[value] = max;
            max++;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */