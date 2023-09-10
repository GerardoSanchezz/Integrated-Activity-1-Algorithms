// Gerardo Ulises Sanchez Felix - A01641788
// Alan Antonio Ruelas Robles - A01641426
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

string storeFileInString(const string);
void LCS(string, int, string, int);
int* fillLPS(string, int);
void KMP(string, int, string, int);
void manacher(string, int);
string getModifiedText(string, int);

int main() {
    string transmission1 = storeFileInString("transmission1.txt");
    string transmission2 = storeFileInString("transmission2.txt");
    string mcode1 = storeFileInString("mcode1.txt");
    string mcode2 = storeFileInString("mcode2.txt");
    string mcode3 = storeFileInString("mcode3.txt");

    int m = transmission1.length(), n = transmission2.length();

    cout << "Transmission 1" << endl;
    cout << "mcode1: " << endl;
    KMP(transmission1, m, mcode1, mcode1.length());
    cout << "mcode2: " << endl;
    KMP(transmission1, m, mcode2, mcode2.length());
    cout << "mcode3: " << endl;
    KMP(transmission1, m, mcode3, mcode3.length());

    cout << endl;

    cout << "Transmission 2" << endl;
    cout << "mcode1: " << endl;
    KMP(transmission2, n, mcode1, mcode1.length());
    cout << "mcode2: " << endl;
    KMP(transmission2, n, mcode2, mcode2.length());
    cout << "mcode3: " << endl;
    KMP(transmission2, n, mcode3, mcode3.length());

    cout << endl;
    cout << "Palindrome" << endl;
    cout << "Transmission 1" << endl;
    manacher(transmission1, m);
    cout << "Transmission 2" << endl;
    manacher(transmission2, n);

    cout << endl;
    cout << "Longest Common Substring" << endl;
    LCS(transmission1, m, transmission2, n);

    

    return 0;
}

string storeFileInString(const string file) {
    string filePath = "../src/inputFiles/" + file;
    ifstream inputFile(filePath);
    string text = "";

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << file << endl;
        return "";
    }

    char c;
    while (inputFile.get(c)) {
        if (c == '\n') continue;
        text += c;
    }

    inputFile.close();
    return text;
}
// Time complexity: O(m * n)
// Space complexity: O(L). L represents the length of the Longest Common Subsequence (LCS)
// between the two input strings X and Y. 
void LCS(string X, int m, string Y, int n) {
    int maxlen = 0;       
    int endingIndex = m;  

    // `lookup` is a sparse matrix represented as a hashmap
    unordered_map<int, unordered_map<int, int>> lookup;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;

                // update the maximum length and ending index
                if (lookup[i][j] > maxlen) {
                    maxlen = lookup[i][j];
                    endingIndex = i;
                }
            }
        }
    }

    int end = endingIndex - 1;
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

// Time Complexity O(n + m)
// Space Complexity O(m)
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
    delete[] LPS;
}


// Time Complexity: O(N)
// Space Complexity: O(N)
void manacher(string text, int n) {
    string newText = getModifiedText(text, n);
    int len = (2 * n) + 1;
    int* LPS = new int[len];
    int c = 0;
    int r = 0;
    int maxLen = 0;
    int maxCenter = 0;

    for (int i = 0; i < len; i++) {
        LPS[i] = 0;
        int mirror = (2 * c) - i;
        
        if (i < r) {
            LPS[i] = min(r - i, LPS[mirror]);
        }
        
        int a = i + (1 + LPS[i]);
        int b = i - (1 + LPS[i]);
        while(a < len && b >= 0 && newText[a] == newText[b]) {
            LPS[i]++;
            a++;
            b--;
        }
        
        if(i + LPS[i] > r) {
            c = i;
            r = i + LPS[i];
            
            if(LPS[i] > maxLen) {
                maxCenter = c;
                maxLen = LPS[i];
            }
        }
    }

    delete[] LPS;
    cout << "Start: " << maxCenter/2 - maxLen/2 << endl;
    cout << "End: " << maxCenter/2 + maxLen/2 << endl;
}

// Time complexity: O(n)
// Space complexity: O(n)
string getModifiedText(string text, int n) {
    string newText = "";
    for(int i = 0; i < n; i++){
        newText += "#";
        newText += text[i];
    }
    newText += "#";
    return newText;
}
