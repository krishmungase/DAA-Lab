#include<iostream>
#include<queue>
using namespace std;

// Node Class
class Node{
public:
    char ch;
    int freq;

    Node *left;
    Node *right;

    // Constructor
    Node(char c, int f){
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

// Comparator for Min Heap
class compare{
public:
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

// Function to print Huffman Codes
void print(Node* root, string code){

    if(root == NULL){
        return;
    }

    // Leaf node
    if(root->left == NULL && root->right == NULL){
        cout << root->ch << " : " << code << endl;
    }

    // Left = 0
    print(root->left, code + "0");

    // Right = 1
    print(root->right, code + "1");
}

int main(){

    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char ch[n];
    int freq[n];

    cout << "Enter characters:\n";
    for(int i=0; i<n; i++){
        cin >> ch[i];
    }

    cout << "Enter frequencies:\n";
    for(int i=0; i<n; i++){
        cin >> freq[i];
    }

    // Min Heap
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Insert nodes into heap
    for(int i=0; i<n; i++){
        pq.push(new Node(ch[i], freq[i]));
    }

    // Build Huffman Tree
    while(pq.size() > 1){

        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        // Create new node
        Node* temp = new Node('$', left->freq + right->freq);

        temp->left = left;
        temp->right = right;

        pq.push(temp);
    }

    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";

    print(root, "");

    return 0;
}
