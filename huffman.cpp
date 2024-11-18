// #include <iostream>
// #include <queue>
// #include <vector>
// #include <map>
// using namespace std;

// // A Huffman tree node
// struct MinHeapNode {
//     char data;             // One of the input characters
//     int freq;              // Frequency of the character
//     MinHeapNode *left, *right; // Left and right child of this node
    
//     MinHeapNode(char data, int freq) {
//         left = right = nullptr;
//         this->data = data;
//         this->freq = freq;
//     }
// };

// // Custom comparator for priority queue to order by frequency
// struct compare {
//     bool operator()(MinHeapNode* l, MinHeapNode* r) {
//         return (l->freq > r->freq);
//     }
// };

// // Function to print Huffman codes from the root of the tree
// void printCodes(MinHeapNode* root, string str) {
//     if (!root)
//         return;
    
//     // If this is a leaf node, it contains one of the input characters
//     if (root->data != '$') // '$' is used for internal nodes
//         cout << root->data << ": " << str << "\n";
    
//     // Recursively traverse left and right subtrees
//     printCodes(root->left, str + "0");
//     printCodes(root->right, str + "1");
// }

// // Main function to build Huffman Tree and print Huffman Codes
// void HuffmanCodes(map<char, int>& freqMap) {
//     MinHeapNode *left, *right, *top;
    
//     // Create a min-heap (priority queue) & insert all characters of freqMap
//     priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    
//     for (auto& pair : freqMap) {
//         minHeap.push(new MinHeapNode(pair.first, pair.second));
//     }
    
//     // Iterate while size of heap doesn't become 1
//     while (minHeap.size() != 1) {
//         // Extract the two minimum frequency nodes
//         left = minHeap.top();
//         minHeap.pop();
        
//         right = minHeap.top();
//         minHeap.pop();
        
//         // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
//         top = new MinHeapNode('$', left->freq + right->freq);
//         top->left = left;
//         top->right = right;
        
//         // Add this node to the min-heap
//         minHeap.push(top);
//     }
    
//     // Print the Huffman codes by traversing the built Huffman Tree
//     printCodes(minHeap.top(), "");
// }

// int main() {
//     // Example input with characters and their corresponding frequencies
//     map<char, int> freqMap = {
//         {'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}
//     };
    
//     // Build Huffman Tree and print codes
//     HuffmanCodes(freqMap);
    
//     return 0;
// }

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// A Huffman tree node
struct Node {
    char ch;      // Character
    int freq;     // Frequency
    Node* left;   // Left child
    Node* right;  // Right child
    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
    Node(int freq, Node* left, Node* right) : ch('\0'), freq(freq), left(left), right(right) {}
};

// Comparison object to be used to order the heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; // Min-heap based on frequency
    }
};

// Function to print the Huffman Codes
void printCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr) return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    // Traverse the left and right children
    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

// Function to decode a given Huffman encoded string
void decode(Node* root, const string& str) {
    cout << "\nDecoded string:\n";
    Node* curr = root;
    for (char bit : str) {
        curr = (bit == '0') ? curr->left : curr->right;

        // Reached a leaf node
        if (!curr->left && !curr->right) {
            cout << curr->ch; // Output the character
            curr = root;      // Go back to root for the next character
        }
    }
    cout << "\n";
}

// Function to build the Huffman Tree and generate Huffman Codes from a frequency table
void buildHuffmanTree(const vector<pair<char, int>>& freqTable) {
    // Create a priority queue to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : freqTable) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Do till there is more than one node in the queue
    while (pq.size() != 1) {
        // Remove the two nodes of highest priority (lowest frequency) from the queue
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new internal node with these two nodes as children
        int sum = left->freq + right->freq;
        pq.push(new Node(sum, left, right));
    }

    // Root stores pointer to the root of the Huffman Tree
    Node* root = pq.top();

    // Traverse the Huffman Tree and store Huffman Codes in a map
    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);

    // Print Huffman Codes
    cout << "Huffman Codes:\n";
    for (const auto& pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Print encoded string based on the frequency table
    string encodedString = "";
    for (const auto& pair : freqTable) {
        encodedString += huffmanCode[pair.first];
    }
    cout << "\nEncoded string:\n" << encodedString << "\n";

    // Decode the encoded string
    decode(root, encodedString);
}

int main() {
    // Example frequency table: (character, frequency)
    vector<pair<char, int>> freqTable = {
        {'H', 1},
        {'U', 1},
        {'F', 2},
        {'M', 1},
        {'A', 1},
        {'N', 1}
    };

    buildHuffmanTree(freqTable);
    return 0;
}
