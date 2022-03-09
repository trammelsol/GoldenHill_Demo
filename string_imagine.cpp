#include <iostream>
#include <string>
#include <regex>
#include <set>
using namespace std;
struct cmp{
    bool operator()(const string& a,const string& b) const {
        return a.size() != b.size() ? a.size() < b.size() : a < b;
    }
};
int main() {
    int n, k;
    string str,record;
    char type;
    set<string, cmp> match;
    cin >> n >> k >> str;
    for (int i = 0; i < n; i++) {
        cin >> type;
        if (type == 'A') {
            cin >> record;
            if(regex_search(record, regex(str)))
                match.insert(record);
        }
        else {
            cout << "P:" << endl;
            int output = 0;
            for (const string& s : match) {
                cout << s << endl;
                if (++output==k)
                    break;
            }
        }
    }
    return 0;
}