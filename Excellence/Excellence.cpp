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
    freopen("../input.txt", "r", stdin);

    // apparently speeds up io operations //
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ---------------------------------- //

    // Input
    int n;
    cin >> n;

    list<int> scores;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        scores.push_back(val);
    }
    scores.sort();

    int minScore = 10000;
    while (!scores.empty()) {
        int pairScore = scores.back() + scores.front(); // score of smallest + highest people
        minScore = std::min(pairScore, minScore);
        scores.pop_back();
        scores.pop_front();
    }

    // Output
    cout << minScore << endl;

    fclose(stdin);
    return 0;
}
