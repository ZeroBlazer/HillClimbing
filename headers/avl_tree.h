#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "headers/nodo.h"
#include <fstream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

template <typename T>
class AVL_tree
{
    enum RotationWay {
        LEFT = 0,
        RIGHT = 1
    };

    typedef AVL_Node<T> Node_T;

private:

    Node_T *m_pRoot;

private:

    bool insert(T &d, Node_T *&p, bool &Balanced);

    void printElem(Node_T *&p);

    void singleRotationTo(Node_T *&p, RotationWay way);

    void doubleRotationTo(Node_T *&p, RotationWay way);

    void makeRelations(Node_T *origin, ofstream& file);

public:

    AVL_tree() :
        m_pRoot(NULL)
    {}

    ~AVL_tree();

    bool find(T &d, Node_T **&p);

    bool insert(T &d);

    bool remove(T &d);

    void graph();

    void printIn();

    void printPre();

    void printPos();

    void printIn(Node_T *p);

    void printPre(Node_T *p);

    void printPos(Node_T *p);

    int height();
};

#include "avl_tree.cpp"

#endif // AVL_TREE_H
