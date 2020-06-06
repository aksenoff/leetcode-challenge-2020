// https://leetcode.com/problems/possible-bipartition/

class Solution {
	struct Node
	{
		vector<int> adj;
		int part{0};
	};
	bool dfs(int cur, Node* nodes, int prevpart, unordered_set<int>& dislikers)
	{
		if (!nodes[cur].part)
		{
			dislikers.erase(cur);
			nodes[cur].part = prevpart == 1 ? 2 : 1;
			for (auto n : nodes[cur].adj)
				if (!dfs(n, nodes, nodes[cur].part, dislikers)) return false;		
		}
		else if (nodes[cur].part == prevpart) return false;
		return true;		
	}

public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
	    auto* g = new Node[N + 1];
		unordered_set<int> dislikers;
    	for (auto dislike : dislikes)
    	{
			g[dislike[0]].adj.push_back(dislike[1]);
			g[dislike[1]].adj.push_back(dislike[0]);
			dislikers.insert({ dislike[0], dislike[1] });
    	}
		bool result = true;
    	while(dislikers.size())	result &= dfs(*dislikers.begin(), g, 1, dislikers);
		return result;
    }
};