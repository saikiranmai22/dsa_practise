#include <iostream>
#include <vector>
using namespace std;

// Function to build the LPS (Longest Prefix Suffix) array
void computeLPSArray(string pattern, int m, vector<int>& lps) {
    int length = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    // Build the lps array
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function to find pattern in text
void KMPSearch(string pattern, string text) {
    int m = pattern.size();
    int n = text.size();

    // Create the LPS array for the pattern
    vector<int> lps(m);
    computeLPSArray(pattern, m, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern

    // Search the pattern in the text
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // Pattern found at index (i - j)
            cout << "Pattern found at index " << (i - j) << endl;
            j = lps[j - 1];  // Move j to the last matched prefix
        } else if (i < n && pattern[j] != text[i]) {
            // Mismatch after j matches
            if (j != 0) {
                j = lps[j - 1];  // Shift pattern based on LPS
            } else {
                i++;  // Move to the next character in the text
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(pattern, text);
    return 0;
}