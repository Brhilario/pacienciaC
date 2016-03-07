struct pilha {
    ListaMesa* prim;
};
typedef struct pilha Pilha;

Pilha* pilha_cria (void);
void pilha_push (Pilha* p, int v,char naipe, int flag);
Carta pilha_pop (Pilha* p);
int pilha_vazia (Pilha* p);
void pilha_libera (Pilha* p);

Pilha* pilha_cria (void) {
    Pilha* p = (Pilha*) malloc (sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push (Pilha* p, int flag, char naipe, int v){

    ListaMesa* n= (ListaMesa*)malloc(sizeof(ListaMesa));
    n->info.valor = v;
    n->info.naipe = naipe;
    n->info.flag = flag;
    n->prox = p->prim;
    p->prim = n ;
}

int pilha_vazia (Pilha* p){

    if(p->prim == NULL)
        return 1;
    return 0;
}

Carta pilha_pop (Pilha* p){
    ListaMesa* t;
    Carta v;

    if (pilha_vazia(p))
        exit(1); /* aborta programa */
    t = p->prim;
    v.valor = t->info.valor;
    v.naipe = t->info.naipe;
    v.flag = t->info.flag;
    p->prim = t->prox;
    free(t);
    return v;
}
