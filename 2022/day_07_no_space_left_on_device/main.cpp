#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    string name;
    bool isDir;
    int size;
    Node *parent;
    vector<Node *> children;
};

Node *newNode(string name, bool isDir, int size, Node *parent) {
    Node *temp = new Node;
    temp->name = name;
    temp->isDir = isDir;
    temp->size = size;
    temp->parent = parent;
    return temp;
}

// global vars
ifstream file("input.txt");
vector<string> vec;
string line;
Node *root = newNode("/", true, 0, NULL);
int sum = 0;
int minSize = INT_MAX;

// method declarations
int init();
int part_1();
int part_2();
int setDirSize(Node *curr);

int main(void) {
    init();
    cout << part_1() << endl;
    cout << part_2() << endl;
    return 0;
}

int init() {
    // read input file, put into vector
    while (getline(file, line)) {
        vec.push_back(line);
    }

    // create a tree for the dir
    Node *curr;
    for (string s : vec) {
        // command
        if (s[0] == '$') {
            // ls
            if (s == "$ ls")
                continue;
            // cd root
            else if (s == "$ cd /")
                curr = root;
            // cd out
            else if (s == "$ cd .." && curr->parent != NULL)
                curr = curr->parent;
            // cd in
            else {
                for (Node *child : curr->children) {
                    if (child->name == s.substr(5)) {
                        curr = child;
                        break;
                    }
                }
            }
        }
        // either file or dir
        else {
            // dir
            if (s.substr(0, s.find(" ")) == "dir") {
                Node *subdir = newNode(s.substr(s.find(" ") + 1), true, 0, curr);
                curr->children.push_back(subdir);
            }
            // file
            else {
                Node *file = newNode(s.substr(s.find(" ") + 1), false, stoi(s.substr(0, s.find(" "))), curr);
                curr->children.push_back(file);
            }
        }
    }

    setDirSize(root);

    return 0;
}

int setDirSize(Node *curr) {
    for (Node *child : curr->children) {
        if (child->isDir)
            child->size = setDirSize(child);
        curr->size += child->size;
    }
    return curr->size;
}

void getSum(Node *curr) {
    if (curr->isDir && curr->size <= 100000)
        sum += curr->size;
    for (Node *child : curr->children)
        getSum(child);
}

int part_1() {
    getSum(root);
    return sum;
}

void getMin(Node *curr) {
    if (curr->isDir && (root->size - curr->size) <= 70000000 - 30000000)
        minSize = min(minSize, curr->size);
    for (Node *child : curr->children)
        getMin(child);
}

int part_2() {
    getMin(root);
    return minSize;
}
