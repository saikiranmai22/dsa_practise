#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to convert a character to its corresponding numerical value
int charToNum(char c) {
    return (c - 'a' + 1);  // 'a' -> 1, 'b' -> 2, ..., 'z' -> 26
}

// Function to compute hash value for a string (substring) using modulus q
int computeHash(const string& str, int start, int length, int q) {
    int hashValue = 0;
    int m = length;  // length of the pattern or substring
    
    for (int i = 0; i < m; i++) {
        hashValue = (hashValue * 10 + charToNum(str[start + i])) % q;
    }
    
    return hashValue;
}

// Rabin-Karp function with mod q
void rabinKarpSearch(const string& text, const string& pattern, int q) {
    int N = text.length();
    int M = pattern.length();
    
    // Calculate hash for the pattern
    int patternHash = computeHash(pattern, 0, M, q);
    cout << "Pattern Hash: " << patternHash << endl;
    
    // Calculate hash for the first window of the text
    int textHash = computeHash(text, 0, M, q);
    
    // Precompute the highest power of 10 modulo q
    int highestPow = 1;  // This will store 10^(M-1) % q
    for (int i = 0; i < M - 1; i++) {
        highestPow = (highestPow * 10) % q;
    }
    
    // Slide the pattern over the text
    for (int i = 0; i <= N - M; i++) {
        // If the hash matches, do character-by-character comparison
        if (textHash == patternHash) {
            bool match = true;
            for (int j = 0; j < M; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        
        // Compute hash for the next window of the text
        if (i < N - M) {
            // Remove the leading character and add the new trailing character
            textHash = (textHash - charToNum(text[i]) * highestPow) % q;
            textHash = (textHash * 10 + charToNum(text[i + M])) % q;
            
            // Handle negative values of textHash
            if (textHash < 0) {
                textHash += q;
            }
        }
    }
}

int main() {
    string text = "ababaccabaabcd";
    string pattern = "abaab";
    int q = 101;  // A prime number used as modulus to reduce collisions
    
    rabinKarpSearch(text, pattern, q);
    
    return 0;
}
