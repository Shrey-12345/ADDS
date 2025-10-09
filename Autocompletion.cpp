#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    
    TrieNode() {
        isWord = false;
    }
};

class Autocomplete {
private:
    TrieNode* root;

    void dfs(TrieNode* node, string prefix, vector<string>& result) {
        if (node->isWord) result.push_back(prefix);
        for (auto& p : node->children) {
            dfs(p.second, prefix + p.first, result);
        }
    }

public:
    Autocomplete() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }

    vector<string> getSuggestions(string partialWord) {
        TrieNode* node = root;
        for (char c : partialWord) {
            if (!node->children.count(c)) return {};
            node = node->children[c];
        }
        vector<string> result;
        dfs(node, partialWord, result);
        return result;
    }
};

// Test
int main() {
    Autocomplete ac;
    ac.insert("bin");
    ac.insert("ball");
    ac.insert("ballet");

    vector<string> suggestions = ac.getSuggestions("ba");
    for (string s : suggestions) cout << s << " ";
    cout << endl;
    return 0;
}
