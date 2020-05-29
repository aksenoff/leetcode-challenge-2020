// https://leetcode.com/problems/counting-bits/

class Solution {
public:
	vector<int> countBits(int num) {
		if (!num) return { 0 };
		if (num == 1) return { 0, 1 };
		vector<int> result = { 0, 1 };
		vector<int> previous = { 1 };
		int i = 1;
		while(i < num)
		{
			vector<int> current;
			current.reserve(previous.size() * 2);
			for (auto el : previous)
			{
				if (i++ >= num) break;
				current.push_back(el);
			}
			for (auto el : previous)
			{
				if (i++ >= num) break;
				current.push_back(el + 1);
			}
			result.insert(result.end(), current.begin(), current.end());
			previous = current;
		}
		return result;
    }
};