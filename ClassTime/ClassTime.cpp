#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    // apparently speeds up io operations //
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ---------------------------------- //

    // Input
    int n;
    cin >> n;

    struct Name {
        string first;
        string last;
        Name(const string& f, const string& l) : first(f), last(l) {};
        
        // alphabetical by last name, and if last names are equal then by first name
        bool operator<(const Name& rhs) {
            if (last == rhs.last) {
                return first < rhs.first;
            }
            return last < rhs.last;
        }
    };

    vector<Name> names;
    names.reserve(n);

    for (int i = 0; i < n; i++) {
        string first;
        string last;
        cin >> first >> last;
        names.emplace_back(first, last);
    }

    sort(names.begin(), names.end());

    for (auto& name : names) {
        cout << name.first << " " << name.last << endl;
    }

    return 0;
}
