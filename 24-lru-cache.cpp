// https://leetcode.com/problems/lru-cache/

class LRUCache {
    unordered_map<int, int> recent; // <key, priority>
    unordered_map<int, int> inverse; // <priority, key>
    unordered_map<int, int> dict;  // <key, value>
    set<int> priorities;
    int capacity;
    int max;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        max = 0;
    }

    int get(int key) {
        if (dict.find(key) != dict.end())
        {
            max++;
            priorities.erase(recent[key]);
            inverse.erase(recent[key]);
            recent[key] = max;
            inverse.insert(make_pair(max, key));
            priorities.insert(max);
            return dict[key];
        }
        else return -1;
    }

    void put(int key, int value) {
        if (dict.find(key) != dict.end())
        {
            max++;
            dict[key] = value;
            priorities.erase(recent[key]);
            inverse.erase(recent[key]);
            recent[key] = max;
            inverse.insert(make_pair(max, key));
            priorities.insert(max);
        }
        else
        {
            max++;
            dict.insert(make_pair(key, value));
            recent.insert(make_pair(key, max));
            inverse.insert(make_pair(max, key));
            priorities.insert(max);
            if (dict.size() > capacity)
            {
                int min = *priorities.begin();
                priorities.erase(min);
                int bye = inverse[min];
                dict.erase(bye);
                recent.erase(bye);
                inverse.erase(min);
            }            
        }
    }
};