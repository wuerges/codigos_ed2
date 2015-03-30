#include <cstdio>

struct Nodo {
    int k;
    Nodo * n;
};

void write_lista(FILE* f, Nodo * n) {
    int s = 0;
    for(Nodo* aux = n; aux != NULL; aux = aux->n) {
        ++s;
    }
    fwrite(&s, sizeof(int), 1, f);
    for(Nodo* aux = n; aux != NULL; aux = aux->n) {
        fwrite(&(aux->k), sizeof(int), 1, f);
    }
}
Nodo * read_lista(FILE* f) {
    
    int s; // s = 4
    fread(&s, sizeof(int), 1, f);

    Nodo * h = new Nodo(); // malloc(sizeof(Nodo))
    Nodo * aux = h;
    for(int i = 0; i<s; ++i) {
        fread(&(aux->k), sizeof(int), 1, f);
        if(i < s - 1) {
            Nodo * next = new Nodo();
            aux->n = next;
            aux = next;
        }
        else {
            aux->n = NULL;
        }
    }
    return h;
}

int main(int nargs, char** argv) {

    Nodo n1, n2, n3, n4;
    n1.k = 97;
    n2.k = 98;
    n3.k = 99;
    n4.k = 100;
    n1.n = &n2;
    n2.n = &n3;
    n3.n = &n4;
    n4.n = NULL;

    FILE * f = fopen("teste.txt", "w+");


    write_lista(f, &n1);

    fclose(f);



    FILE * f2 = fopen("teste.txt", "r");

    Nodo * lidos = read_lista(f);

    fclose(f2);
    for (Nodo * aux = lidos; aux != NULL; aux = aux->n) {
        printf("aux->k %d\n", aux->k); 
    }

    printf("final\n");

    
    
    return 0;

}
