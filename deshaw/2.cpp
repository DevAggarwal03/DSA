#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxAMZ_Optimized(string s) {
    int countA = 0, countAM = 0, countAMZ = 0;
    int bestInsertGain = 0;

    for (char c : s) {
        if (c == 'A') {
            countA++;
        } else if (c == 'M') {
            countAM += countA;
        } else if (c == 'Z') {
            countAMZ += countAM;
        }

        // Try inserting 'A' here: would increase countAMZ by future M and Z
        bestInsertGain = max(bestInsertGain, countAM); // inserting 'Z'
        bestInsertGain = max(bestInsertGain, countA);  // inserting 'M'
        bestInsertGain = max(bestInsertGain, countAMZ + 1); // inserting 'A' doesn't immediately increase AMZ, but sets up future gain
    }

    return countAMZ + max(max(countA, countAM), bestInsertGain);
}

int main() {
    string input = "AKMZ";
    cout << "Maximum number of AMZ subsequences: " << maxAMZ_Optimized(input) << endl;
    return 0;
}