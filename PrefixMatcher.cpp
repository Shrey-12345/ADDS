#include "PrefixMatcher.h"

TrieNodeRouter::TrieNodeRouter() {
    routerNumber = -1;
}

PrefixMatcher::PrefixMatcher() {
    root = new TrieNodeRouter();
}

void PrefixMatcher::insert(string address, int routerNumber) {
    TrieNodeRouter* node = root;
    for (char bit : address) {
        if (!node->children.count(bit)) {
            node->children[bit] = new TrieNodeRouter();
        }
        node = node->children[bit];
    }
    node->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(string networkAddress) {
    TrieNodeRouter* node = root;
    int lastRouter = -1;
    for (char bit : networkAddress) {
        if (!node->children.count(bit)) break;
        node = node->children[bit];
        if (node->routerNumber != -1) lastRouter = node->routerNumber;
    }
    return lastRouter;
}
