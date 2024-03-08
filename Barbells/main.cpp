#pragma warning(disable : 6031) // annoying scanf warning
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

vector<int> plates, barbells;
set<int> equalSums, totalWeights;

// Recursive function to find all possible equal sums of plates on both sides
// it's O(3^n) and n <= 14 so max is 3^14 = 4782969
void findEqualSums(int leftSum, int rightSum, int i) {
    if (i == plates.size()) {
        if (leftSum == rightSum) {
            equalSums.insert(leftSum * 2);
        }
        return;
    }

    // try all possibilities (add plate to left, right, or skip it)
    findEqualSums(leftSum + plates[i], rightSum            , i + 1);
    findEqualSums(leftSum            , rightSum + plates[i], i + 1);
    findEqualSums(leftSum            , rightSum            , i + 1);
}

int main() {
    // Input
    freopen("../input.txt", "r", stdin);

    int n, m;
    scanf("%d%d", &n, &m);

    barbells.resize(n);
    plates.resize(m);

    for (auto& b : barbells) scanf("%d", &b);
    for (auto& p : plates) scanf("%d", &p);

    // Find all possible equal sums
    findEqualSums(0, 0, 0);

    // Try all possible weights
    for (int barbellWeight : barbells) {
        for (int platesSum : equalSums) {
            totalWeights.insert(barbellWeight + platesSum);
        }
    }

    // Output
    for (int weight : totalWeights) {
        printf("%d\n", weight);
    }

    fclose(stdin);
    return 0;
}