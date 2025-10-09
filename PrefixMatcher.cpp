#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNodeRouter {
public:
    unordered_map<char, TrieNodeRouter*> children;
    int routerNumber;
    
    TrieNodeRouter() {
        routerNumber = -1;
    }
};

class PrefixMatcher {
private:
    TrieNodeRouter* root;

public:
    PrefixMatcher() {
        root = new TrieNodeRouter();
    }

    void insert(string address, int routerNumber) {
        TrieNodeRouter* node = root;
        for (char bit : address) {
            if (!node->children.count(bit)) {
                node->children[bit] = new TrieNodeRouter();
            }
            node = node->children[bit];
        }
        node->routerNumber = routerNumber;
    }

    int selectRouter(string networkAddress) {
        TrieNodeRouter* node = root;
        int lastRouter = -1;
        for (char bit : networkAddress) {
            if (!node->children.count(bit)) break;
            node = node->children[bit];
            if (node->routerNumber != -1) lastRouter = node->routerNumber;
        }
        return lastRouter;
    }
};

// Test
int main() {
    PrefixMatcher pm;
    pm.insert("1100110111", 1);
    pm.insert("110011011", 2);
    pm.insert("11001101", 3);

    cout << pm.selectRouter("110011011001") << endl;
    return 0;
}
