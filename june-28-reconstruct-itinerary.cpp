// https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
    map<string, priority_queue<string, vector<string>, greater<string>>> g;
    vector<string> itinerary;
    void dfs(string ap)
    {
        while (!g[ap].empty())
        {
            auto dest = g[ap].top();
            g[ap].pop();
            dfs(dest);            
        }
        itinerary.push_back(ap);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto t : tickets) g[t[0]].push(t[1]);
        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};