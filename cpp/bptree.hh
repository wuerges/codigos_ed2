#include <iostream>
#include <vector>
using namespace std;

//const long int N = 300;

template <typename K, int N>
struct bpnode {
    vector<long int> fs;
    vector<K> ks;
    long int p, ie, id;

};

template <typename K, int N>
bpnode<K, N> * read_bpnode(FILE* f, long int p);

template <typename K, int N>
void write_bpnode(FILE* f, bpnode<K, N>* n,  long int p);



template< typename K, int N >
void bp_insert_2(K k, FILE* f, long int p) {
    bpnode<K, N> * folha = bp_search(k, f, p);
    bp_insert(folha, k, 0, f);
}

template< typename K, int N >
void bp_insert(bpnode<K, N> * folha, K k, long int filho, FILE* f) {

    int i = folha->ks.size();
    for(; i > 0; --i) {
        if (folha->ks[i] <= k) {
            break;
        }
    }
    if (folha->ks[i] == k) {
        return;
    }
    else {
        folha->ks.insert(i, k);
        folha->fs.insert(i, filho);
        if (i == 0) 
            update_index(F, folha, p);
    }

    if (folha->ks.size()  == N) {
        // Caso seja necessario dividir o nodo
        bpnode<K, N> * novo  = new bpnode<K, N>();

        int m = folha->ks.size() / 2;
        for (int i = m+1; i < folha->ks.size(); ++i) {
            novo->ks.push_back(folha->ks[i]);
            novo->fs.push_back(folha->fs[i]);
        }
        folha->ks.resize(m);
        folha->fs.resize(m);
        write_bpnode(f, folha, folha_pos);


        fseek(f, SEEK_END);
        long int pos_novo = fgetpos(f);
        write_bpnode(f, novo, pos_novo);

        if (folha->p) {
            //update_index(F, folha, p);
        }
        else {
            bpnode<K, N>* pai = new bpnode<K, N>();
            pai->ks.push_back(folha->ks[0]);
            pai->fs.push_back(p);
            fseek(f, SEEK_END);
            write_bpnode(f, pai, fgetpos(f));

        }
        bpnode<K, N>* pai = read_bpnode(f, folha->p);
        bp_insert(pai, novo->ks[0], pos_novo, f);
    }
}

template< typename K, int N >
bpnode<K,N> * bp_search(K k, FILE* f, long int p) {
    bpnode<K,N> * n = read_bpnode<K,N>(f, p);

    int i = n->ks.size();
    for(; i > 0; --i) {
        if (n->ks[i] <= k) {
            break;
        }
    }

    if (n->fs[i]) {
        long int filho = n->fs[i];
        delete n;
        return bp_search(k, f, filho);
    }

    return n;

}
