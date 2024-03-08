#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // apparently speeds up io operations //
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ---------------------------------- //

    // Input
    string s;
    cin >> s;

    // Array to keep track of frequency of each character
    vector<int> freq(26, 0);

    // Count the occurrences of each character
    // mapping a to 0 and z to 25
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Sort the frequency array from big to small
    sort(freq.begin(), freq.end(), greater<int>());

    // erase total characters minus the two most frequent character counts
    int erasures = s.length() - (freq[0] + freq[1]);

    // Output
    cout << erasures << endl;

    return 0;
}

//--------------------------------------- //
// old dumb solution
// it's bad but it worked lol
/*int main() {
    // apparently speeds up io operations //
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ---------------------------------- //

    // Input
    string str;
    cin >> str;

    std::unordered_map<char, int> charMap;

    for (char c : str) {
        charMap[c]++;
    }

    int biggest = 0;
    int secondBiggest = 0;
    char biggestChar = 0;
    char secondBiggestChar = 0;

    for (auto& val : charMap) {
        char character = val.first;
        int charCount = val.second;

        if (charCount > biggest) {
            if (biggest != 0) {
                secondBiggest = biggest;
                secondBiggestChar = biggestChar;
            }
            if (secondBiggest != 0) {
                secondBiggest = biggest;
                secondBiggestChar = biggestChar;
            }
            biggest = charCount;
            biggestChar = character;
        }
        else if (charCount > secondBiggest) {
            secondBiggest = charCount;
            secondBiggestChar = character;
        }
    }

    int charsToDelete = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str.at(i);

        if (c != biggestChar && c != secondBiggestChar) {
            charsToDelete++;
        }
    }

    // Output
    cout << charsToDelete;

    return 0;
}*/
