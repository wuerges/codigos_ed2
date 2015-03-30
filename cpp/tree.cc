#include "tree.hh"
#include <iostream>
using namespace std;


Node* Node::search(int x) {

    if (x == k) {
        return this;
    }
    else if (x > k && r) {
        return r->search(x);
    }
    else if (x < k && l) {
        return l->search(x);
    }
    else {
        return NULL;
    }
}

void Node::remove() {

    // Se nao tiver filhos
    if (!r && !l) {
        if (p->r == this) {
            p->r = NULL;
        }
        else {
            p->l = NULL;
        }

    }
    else if (r && !l) {
        r->p = p;

        if (this == p->r)
        {
            p->r = r;
        }
        else {
            p->l = r;
        }
        // Caso 2
    }
    else if (l && !r) {
        // Caso 2'
        //
        // TODO
    }
    else {
        // Caso 3
        //
        // Tem 2 Filhos

        Node * s = this->successor();
        this->k = s->k;
        s->remove();
    }

}

Node* Node::minimum() {
    if (l) {
        return l->minimum();
    }
    else {
        return this;
    }
}

Node* Node::successor() {
    return r->minimum();
}


void Node::traverse(vector<int> & nodes) {
    if (l)
        l->traverse(nodes);
    nodes.push_back(k);
    if (r)
        r->traverse(nodes);
}

