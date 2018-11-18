#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>
using namespace std;

class nod {
    int info;
    nod* left;
    nod* right;

 public:
    inline int getInfo() const { return this->info; }
    inline nod* getLeftNode() const { return this->left; }
    inline nod* getRightNode() const { return this->right; }

    inline void setInfo(const int info) { this->info = info; }
    inline void setLeftNode(nod* left) { this->left = left; }
    inline void setRightNode(nod* right) { this->right = right; }

    nod(int number, nod*, nod*);
    nod(const nod&);
    ~nod();
};

class ABC {
    nod* root;

    nod* copyHelper(nod*);
    nod* insertHelper(nod*, int);
    void SRD(ostream&, nod*);
    void RSD(ostream&, nod*);
    void SDR(ostream&, nod*);

    nod* findMinNode(nod*);
    nod* deleteNode(nod*, int);
    int treeHeight(nod*);
    void printLeaves(nod*);
    bool isValueInTree(nod*, int);

 public:
    inline nod* getRoot() const { return this->root; }
    inline void setRoot(nod* root) { this->root = root; }
    const ABC& operator=(const ABC&);
    const ABC& operator+(int);
    friend istream& operator>>(istream&, ABC&);
    friend ostream& operator<<(ostream&, const ABC&);

    void deleteNode(int);
    int treeHeight();
    void printLeaves();
    bool isValueInTree(int);

    ABC();
    ABC(const ABC&);
    ~ABC();
};


#endif //BINARYSEARCHTREE_V2_BST_H
