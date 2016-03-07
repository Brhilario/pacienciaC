struct carta {
    int flag;	    //  0 = Esconder e 1 = Mostrar
    int valor;     //  Valores correspondentes a cada carta
    char naipe;    // O = Ouro C = Copas E = Espadas e P = Paus
};
typedef struct carta Carta;

struct lista {
    Carta info;
    struct lista* prox;
};
typedef struct lista ListaMesa;

//Funcionando
ListaMesa* Inicializar_Lista(void);
ListaMesa* Insere_Fim (ListaMesa* L, int i, char naipe, int flag);
ListaMesa* Insere_Inicio(ListaMesa* l,int i);
void Imprime(ListaMesa* l);

// Implementar
void Libera(ListaMesa* l);
ListaMesa* Retirar(ListaMesa* l,int v);
ListaMesa* lst_busca(ListaMesa* l,int v);



ListaMesa* Inicializar_Lista(void){
    return NULL;
}



ListaMesa* Insere_Inicio(ListaMesa* l,int i){
    ListaMesa* novo = (ListaMesa*)malloc(sizeof(ListaMesa));
    novo->info.valor = i;
    novo->info.flag = 0;
    novo->info.naipe = 'O';
    novo->prox = l;
    return novo;
}



// Aqui chamamos o Insere Fim. Usaremos nas pilhas de mesa (Sequência 1,2,3,4,5,6,7 cartas), mas com a estrutura de lista encadeada.
ListaMesa* Insere_Fim (ListaMesa* L, int i, char naipe, int flag){
    ListaMesa* novo = (ListaMesa*) malloc (sizeof(ListaMesa));
    /*if (!novo){
        printf("Não foi possivel alocar o elemento. Sem memória.");
        exit(1);
    } */

    novo->info.flag = flag;
    novo->info.naipe = naipe;
    novo->info.valor = i;
    novo->prox = NULL;

    if (L == NULL)
        L = novo;
    else {
        ListaMesa* aux = L;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return L;
}

void Imprime(ListaMesa* l){
    ListaMesa* p;
    for(p=l;p!=NULL;p=p->prox)
        printf( "info= %d flag = %d naipe = %c \n" ,p->info.valor, p->info.flag, p->info.naipe);
}
