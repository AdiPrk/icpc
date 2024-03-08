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

    vector<int> lis(str.size(), 1);
    int longest = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[j] > str[i]) {
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
        longest = max(lis[i], longest);
    }

    // Output
    printf("%i", 26 - longest);

    fclose(stdin);
    return 0;
}
