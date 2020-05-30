// https://leetcode.com/problems/course-schedule/

class Solution {
    bool dfs(int cur, vector<int>* g, int* visited, unordered_set<int>& reqs)
    {
        if (visited[cur] == 1) return false;
        if (visited[cur] == 2) return true;
        visited[cur] = 1;
        reqs.erase(cur);
        bool result = true;
        for (auto next : g[cur])
            if (!dfs(next, g, visited, reqs)) return false;
        visited[cur] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int* visited = new int[numCourses]{};
        auto* g = new vector<int>[numCourses]{};
        unordered_set<int> reqs;
        for (auto req_pair : prerequisites)
        {
            g[req_pair[0]].push_back(req_pair[1]);
            reqs.insert(req_pair[0]);
        }
        while (reqs.size())
            if (!dfs(*reqs.begin(), g, visited, reqs)) return false;
        return true;
    }
};