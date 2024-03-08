#pragma warning(disable : 6031) // annoying scanf warning
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

int main() {
    freopen("../input.txt", "r", stdin);

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int dropCount, top;
    std::cin >> dropCount >> top;

    int highestSafe = 0; // 0 is the base safe case
    int lowestBreak = top; // highestFloor always breaks egg

    for (int i = 0; i < dropCount; ++i) {
        int floor;
        char outcome[7]; // Enough to store "SAFE" or "BROKEN"
        std::cin >> floor >> outcome;

        if (outcome[0] == 'S') highestSafe = std::max(floor, highestSafe);
        else if (outcome[0] == 'B') lowestBreak = std::min(floor, lowestBreak);
    }

    // print lowest floor the egg (possibly) breaks on
    // and highest floor it's (possibly) safe on
    std::cout << (highestSafe + 1) << " " << (lowestBreak - 1) << std::endl;

    fclose(stdin);
    return 0;
}