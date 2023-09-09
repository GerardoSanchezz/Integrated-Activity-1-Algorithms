#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void readFileAndStoreInString(const string file, string& text);

void showString(const string&);

struct LCSSubstring {
    int start;  // starting position of the common substring in tranmission file
    int end;    // ending position of the common substring in tranmission file 
    int length; // length of the common substring
};

LCSSubstring LCS(string, string, int, int);

int main() {
    string transmission1;
    string transmission2;
    string mcode1;
    string mcode2;
    string mcode3;

    readFileAndStoreInString("transmission1.txt", transmission1);
    readFileAndStoreInString("transmission2.txt", transmission2);
    readFileAndStoreInString("mcode1.txt", mcode1);
    readFileAndStoreInString("mcode2.txt", mcode2);
    readFileAndStoreInString("mcode3.txt", mcode3);
    
    // Display the content of each string
    showString(transmission1);
    showString(transmission2);
    showString(mcode1);
    showString(mcode2);
    showString(mcode3);

    // Find the longest common substring between transmission1 and mcode1
    int m = transmission1.length(), n = transmission2.length();
    LCSSubstring longestCommonSubstring = LCS(transmission1, transmission2, m, n);

    // Check if the longest common substring was found
    if (longestCommonSubstring.length > 0) {
        cout << "Longest Common Substring: " << transmission1.substr(longestCommonSubstring.start, longestCommonSubstring.length) << endl;
        cout << "Start Position in transmission1: " << longestCommonSubstring.start + 1 << endl;
        cout << "End Position in transmission1: " << longestCommonSubstring.end + 1 << endl;
    } else {
        cout << "No common substring found." << endl;
    }

    return 0;
}

void showString(const string& str) {
    cout << str << endl;
}


void readFileAndStoreInString(const string file, string& text) {
    ifstream inputFile(file);

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << file << endl;
        return;
    }

    char c;
    while (inputFile.get(c)) {
        text += c;
    }

    inputFile.close();
}


LCSSubstring LCS(string X, string Y, int m, int n) {
    int maxlen = 0;       // stores the max length of LCS
    int endingIndex = m;  // stores the ending index of LCS in `X`

    // `lookup[i][j]` stores the length of LCS of substring `X[0…i-1]`, `Y[0…j-1]`
    int dp[m + 1][n + 1];

    // initialize all cells of the lookup table to 0
    memset(dp, 0, sizeof(dp));

    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // if the current character of `X` and `Y` matches
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                // update the maximum length and ending index
                if (dp[i][j] > maxlen) {
                    maxlen = dp[i][j];
                    endingIndex = i;
                }
            }
        }
    }

    LCSSubstring result;
    result.length = maxlen;
    result.end = endingIndex - 1; // Adjust ending index to get the correct position
    result.start = result.end - maxlen + 1;

    return result;
}
