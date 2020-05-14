// https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode {
public:
    map<char, TrieNode*> arr;
    bool is_last;
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* currentNode = root;
        for (auto c : word)
        {
            auto node = currentNode->arr.find(c);
            if (node != currentNode->arr.end()) currentNode = node->second;
            else {
                currentNode->arr[c] = new TrieNode();
                currentNode = currentNode->arr[c];
            }
        }
        currentNode->is_last = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* currentNode = root;
        for (auto c : word)
        {
            auto node = currentNode->arr.find(c);
            if (node != currentNode->arr.end()) currentNode = node->second;
            else return false;
        }
        return currentNode->is_last;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* currentNode = root;
        for (auto c : prefix)
        {
            auto node = currentNode->arr.find(c);
            if (node != currentNode->arr.end()) currentNode = node->second;
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */