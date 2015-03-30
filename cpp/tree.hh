struct Node {
    int k;
    Node* l;
    Node* r;
    Node* p;

    Node(int _k): k(_k) {}

    Node* search(int x);

    void remove();

    Node * minimum();
    Node * successor();
};




