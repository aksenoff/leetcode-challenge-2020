// https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (!people.size()) return people;
        sort(people.begin(), people.end(), [](auto& a, auto& b) { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
        vector<vector<int>> result;
        result.resize(people.size());
        for (auto& person : people)
        {
            int n = 0, i = 0;
            while (result[i].size())
            {
                if (result[i][0] == person[0]) n++;
                i++;
            }
            while (n < person[1] || result[i].size())
            {                
                if (!result[i].size() || result[i][0] == person[0]) n++;
                i++;
            }
            result[i] = person;
        }
        return result;
    }
};