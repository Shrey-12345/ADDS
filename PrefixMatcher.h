#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <unordered_map>
using namespace std;

class TrieNodeRouter {
public:
    unordered_map<char, TrieNodeRouter*> children;
    int routerNumber;

    TrieNodeRouter();
};

class PrefixMatcher {
private:
    TrieNodeRouter* root;

public:
    PrefixMatcher();
    void insert(string address, int routerNumber);
    int selectRouter(string networkAddress);
};

#endif
