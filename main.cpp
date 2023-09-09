#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void storeFileInString(const string, string&);
void LCS(string, int, string, int);
int* fillLPS(string, int);
void KMP(string, int, string, int);

int main() {
    string transmission1;
    string transmission2;
    string mcode1;
    string mcode2;
    string mcode3;

    storeFileInString("transmission1.txt", transmission1);
    storeFileInString("transmission2.txt", transmission2);
    storeFileInString("mcode1.txt", mcode1);
    storeFileInString("mcode2.txt", mcode2);
    storeFileInString("mcode3.txt", mcode3);

    // Find the longest common substring between transmission1 and transmission2
    int m = transmission1.length(), n = transmission2.length();
    // LCS(transmission1, m, transmission2, n);

    cout << "Transmission 1" << endl;
    cout << "mcode1: " << endl;
    KMP(transmission1, m, mcode1, mcode1.length());
    cout << "mcode2: " << endl;
    KMP(transmission1, m, mcode2, mcode2.length());
    cout << "mcode3: " << endl;
    KMP(transmission1, m, mcode3, mcode3.length());

    cout << "Transmission 2" << endl;
    cout << "mcode1: " << endl;
    KMP(transmission2, m, mcode1, mcode1.length());
    cout << "mcode2: " << endl;
    KMP(transmission2, m, mcode2, mcode2.length());
    cout << "mcode3: " << endl;
    KMP(transmission2, m, mcode3, mcode3.length());

    return 0;
}

void storeFileInString(const string file, string& text) {
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


void LCS(string X, int m, string Y, int n) {
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

    int end = endingIndex - 1; // Adjust ending index to get the correct position
    int start = end - maxlen + 1;
    if (maxlen > 0) {
        cout << "Start Position in transmission1: " << start + 1 << endl;
        cout << "End Position in transmission1: " << end + 1 << endl;
    } else {
        cout << "No common substring found." << endl;
    } 
}

int* fillLPS(string pattern, int m) {
    int *LPS = new int[m];
    int i = 0;
    int j = 1;
    LPS[0] = 0;

    while (j < m) {
        if (pattern[i] == pattern[j]) {
            LPS[j] = i + 1;
            i++; 
            j++;
        } else if (i > 0) {
            i = LPS[i-1];
        } else {
            LPS[j] = 0;
            j++;
        }
    }
    return LPS;
}

void KMP(string text, int n, string pattern, int m) {
    int *LPS  = fillLPS(pattern, m);
    int i = 0;
    int j = 0;
    bool found = false;

    while (i < n) {
        if (pattern[j] == text[i]) {
            if (j == m - 1) {
                found = true;
                cout << "true " << i - m + 1 << endl;
                // return i - m + 1;
            }
            i++;
            j++;
        } else if (j > 0) {
            j = LPS[j-1];
        } else {
            i++;
        }
    }
    if (!found) {
        cout << "False" << endl;
    }
}
