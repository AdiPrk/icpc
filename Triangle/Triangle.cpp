#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>

using namespace std;

int main() {
    // Input
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

    // sort triangle lengths
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    if (d > f) swap(d, f);
    if (e > f) swap(e, f);
    if (d > e) swap(d, e);

    // print yes if lengths are equal and it's a right triangle
    (a==d && b==e && c==f && a*a + b*b == c*c) ? printf("YES") : printf("NO");

    return 0;
}
