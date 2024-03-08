#pragma warning(push)
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
    freopen("../x64/Release/input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    // Output
    printf("%d", n);

    fclose(stdin);
    return 0;
}

#pragma warning(pop)