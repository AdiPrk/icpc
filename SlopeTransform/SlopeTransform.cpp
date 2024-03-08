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

float targetSlope = 8;
float targetIntercept = 21;
float minRange = targetIntercept;
float maxRange = targetSlope * 300 + targetIntercept;
int numInBounds = 0;

bool inBounds(float x) {
    numInBounds++;
    return x >= minRange && x <= maxRange;
}

int main() {
    // Input
    int a = 0;
    int b = 0;
    int searchStart = 0;
    int searchEnd = 100;
    
    if (inBounds(8 * 300)) {
        a = 8;
    }
    else if (inBounds(4 * 300)) {
        a = 4;
    }
    else if (inBounds(2 * 300)) {
        a = 2;
    }
    else {
        a = 1;
    }

    searchStart = 0;
    searchEnd = 100;

    int mid = (searchStart + searchEnd) / 2;

    bool isInBounds = false;
    int highestInBound = 0;
    int lowestOutOfBound = 100;
    int loopTimes = 0;
    while (true) {
        loopTimes++;
        isInBounds = inBounds(mid);
        if (!isInBounds) { // b is greater than or equal to mid
            searchStart = mid;
            mid = (mid + searchEnd) * 0.5;
            highestInBound = max(highestInBound, mid);
        }
        else { // b is less than mid
            searchEnd = mid;
            mid = (mid + searchStart) * 0.5;
            lowestOutOfBound = min(lowestOutOfBound, mid);
        }
        if (searchEnd - searchStart == 2) {
            break;
        }
    }

    b = mid;
    /*for (int i = searchStart; i <= searchEnd + 1; i++) {
        if (!inBounds(i)) {
            b = i - 1;
            b -= 300 * a;
            break;
        }
    }*/
    
    cout << a << "t + " << b << endl;

    cout << "Number of time InBounds was called: " << numInBounds << endl;

    return 0;
}
