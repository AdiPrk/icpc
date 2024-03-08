#pragma warning(disable : 6031) // annoying scanf warning
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Wave {
    int min, pts, wait;
    bool operator<(const Wave& rhs) const { return min < rhs.min; }
};

int main() {
    // Input
    freopen("../input.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    std::vector<Wave> waves(n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &waves[i].min, &waves[i].pts, &waves[i].wait);
    }

    std::sort(waves.begin(), waves.end());
    std::vector<int> scores(n+1);

    // go over waves from last to start
    int i, j;
    for (i = n - 1; i >= 0; i--) {
        // get next available wave's index (j). Goes all the way to the end if there's nothing valid.
        // score of invalid wave (n + 1) is 0 by default
        for (j = i + 1; (j < n && waves[j].min < waves[i].min + waves[i].wait); j++) {}
        
        // get the max possible fun from the current i
        // scores[i] is maximum fun at i
        // since it goes backwards it stores max fun from every future wave until now
        // so scores[j] is the maximum it can get 
        //cout << "(i, j) = " << "(" << i << " " << j << ")" << endl;
        scores[i] = std::max(scores[i + 1], scores[j] + waves[i].pts);
    }
    // cout << endl;
    // for (auto& s : scores) {
    //     cout << s << " ";
    // }
    // Output
    printf("%d", scores[0]);

    fclose(stdin);
    return 0;
}
