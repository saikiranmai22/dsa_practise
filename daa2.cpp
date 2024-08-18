//Huffman coding
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// A tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Custom comparator to order the nodes in the priority queue by frequency
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; // Min-heap based on frequency
    }
};

// Function to print the Huffman codes from the root of the Huffman Tree
void printCodes(Node* root, string str) {
    if (!root) {
        return;
    }

    if (root->ch != '#') {  // '#' denotes an internal node
        cout << root->ch << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// The main function to build a Huffman Tree and generate Huffman Codes
void HuffmanCoding(vector<char>& characters, vector<int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create a leaf node for each character and add it to the priority queue.
    for (size_t i = 0; i < characters.size(); ++i) {
        minHeap.push(new Node(characters[i], frequencies[i]));
    }

    // Iterate until the size of the heap becomes 1
    while (minHeap.size() != 1) {
        // Extract the two nodes with the lowest frequency
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes
        Node* z = new Node('#', left->freq + right->freq);
        z->left = left;
        z->right = right;

        // Add the new node to the min-heap
        minHeap.push(z);
    }

    // The remaining node is the root of the Huffman Tree
    Node* root = minHeap.top();

    // Print Huffman codes
    printCodes(root, "");
}

int main() {
    // Example set of characters and their corresponding frequencies
    vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};

    // Build Huffman Tree and print Huffman Codes
    HuffmanCoding(characters, frequencies);

    return 0;
}