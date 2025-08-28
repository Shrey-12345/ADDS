#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    size_t start = 0;
    for (size_t i = 1; i <= s2.size(); i++) {
        string prefix = s2.substr(0, i);
        size_t found = s1.find(prefix, start);
        if (found != string::npos) {
            result.push_back(static_cast<int>(found));
            start = found;
        } else {
            for (; i <= s2.size(); i++)
                result.push_back(-1);
            break;
        }
    }
    return result;
}
