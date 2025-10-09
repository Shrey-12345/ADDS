#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode();
};

class Autocomplete {
private:
    TrieNode* root;
    void dfs(TrieNode* node, string prefix, vector<string>& result);

public:
    Autocomplete();
    void insert(string word);
    vector<string> getSuggestions(string partialWord);
};

#endif
