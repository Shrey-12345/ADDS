#include "Autocomplete.h"

TrieNode::TrieNode() {
    isWord = false;
}

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->isWord = true;
}

void Autocomplete::dfs(TrieNode* node, string prefix, vector<string>& result) {
    if (node->isWord) result.push_back(prefix);
    for (auto& p : node->children) {
        dfs(p.second, prefix + p.first, result);
    }
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
    TrieNode* node = root;
    for (char c : partialWord) {
        if (!node->children.count(c)) return {};
        node = node->children[c];
    }
    vector<string> result;
    dfs(node, partialWord, result);
    return result;
}
