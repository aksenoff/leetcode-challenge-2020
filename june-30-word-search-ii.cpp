// https://leetcode.com/problems/word-search-ii/

class TrieNode
{   
public:
    bool complete;
    TrieNode* map[26];
    TrieNode* parent;
    TrieNode(TrieNode* p)
    {
        for (int i = 0; i < 26; ++i) map[i] = nullptr;
        complete = false;
        parent = p;
    }
};

class Trie
{
    TrieNode* root;
    TrieNode* current;
public:
    Trie()
    {
        root = new TrieNode(nullptr);
    }
    void insert(string s)
    {
        TrieNode* tn = root;
        for (auto c : s)
        {
            if (tn->map[c - 'a']) tn = tn->map[c - 'a'];
            else
            {
                TrieNode* newnode = new TrieNode(tn);
                tn->map[c - 'a'] = newnode;
                tn = newnode;
            }
        }
        tn->complete = true;
    }
    void dropcurrent()
    {
        current = nullptr;
    }
    void up()
    {
        current = current->parent;
    }
    int search(char c)
    {
        if (!current) current = root;
        if (!current->map[c - 'a']) return 0;
        else
        {
            current = current->map[c - 'a'];
            return current->complete ? 2 : 1;
        }
    }
};

class Solution {
    void search(vector<vector<char>>& board, vector<string>& words, int i, int j, Trie& trie, string& currentword, bool** seen, vector<string>& oldwords)
    {        
        int m = board.size();
        int n = board[0].size();
        seen[i][j] = true;
        char c = board[i][j];        
        int res = trie.search(c);
        if (!res)
        {
            seen[i][j] = false;
            return;
        }
        currentword.push_back(c);
        if (res == 2)
        {
            bool found = false;
            for (auto word : words)
                if (word == currentword)
                {
                    found = true;
                    break;
                }
            if (!found) words.push_back(currentword);
        }
        if (i > 0 && !seen[i - 1][j] && currentword.size() < m * n) search(board, words, i - 1, j, trie, currentword, seen, oldwords);
        if (i < m - 1 && !seen[i + 1][j] && currentword.size() < m * n) search(board, words, i + 1, j, trie, currentword, seen, oldwords);
        if (j > 0 && !seen[i][j - 1] && currentword.size() < m * n) search(board, words, i, j - 1, trie, currentword, seen, oldwords);
        if (j < n - 1 && !seen[i][j + 1] && currentword.size() < m * n) search(board, words, i, j + 1, trie, currentword, seen, oldwords);
        if (currentword.size() < m * n)
        {
            trie.up();
            currentword.pop_back();
            seen[i][j] = false;
        }
        
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if (!m) return {};
        int n = board[0].size();
        if (!n) return {};
        Trie trie;
        bool** seen = new bool* [m];
        for (int i = 0; i < m; ++i)
        {
            bool* seenrow = new bool[n] {false};
            seen[i] = seenrow;
        }           
        for (auto word : words) trie.insert(word);
        string currentword;
        vector<string> resultwords;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                trie.dropcurrent();
                currentword.clear();
                for (int a = 0; a < m; ++a)
                    for (int b = 0; b < n; ++b)
                        seen[a][b] = false;
                search(board, resultwords, i, j, trie, currentword, seen, words);
            }
        return resultwords;
    }
};