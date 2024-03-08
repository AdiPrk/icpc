#pragma warning(disable : 6031) // annoying scanf warning
#define _CRT_SECURE_NO_WARNINGS

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
    // Input
    freopen("../input.txt", "r", stdin);

    std::string str;
    cin >> str;

    // Get longest increasing subsequence (lis)
    vector<int> lis;
    for (const char& c : str) {
        // Find first element in lis that's bigger than c
        auto it = lower_bound(lis.begin(), lis.end(), c);

        // If it doesn't exist, c is the biggest so add c to end of lis
        if (it == lis.end()) {
            lis.push_back(c);
        }
        // Otherwise, replace it with c
        else {
			*it = c;
		}
    }

    // Output
    cout << 26 - lis.size();

    fclose(stdin);
    return 0;
}
