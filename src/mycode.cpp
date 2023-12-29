#include "mycode.h"
#include "QVector"
#include "QString"

bool match_from_mycode(string &s, int pos, string &sub) {
    if (s.size()-pos < sub.size())
        return false;

    for (int i = 0; i < sub.size(); i++) {
        if (s[pos+i] != sub[i])
            return false;
    }
    return true;
}


QVector<int> my_substr_mycode(string &s, string &sub) {
    QVector<int> inds;

    for (int i = 0; i < s.size(); i++) {
        if (match_from_mycode(s, i, sub)) {
            inds.push_back(i);
        }
    }
    return inds;
}
