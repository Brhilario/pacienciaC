//Função para preencher os baralhos passando o ponteiro do vetor e o naipe
void preenche_baralho(Carta* vetor_baralho,char naipe );
//Preencher o baralho completo
Pilha* baralho (Carta* Baralho_ouro,Carta* baralho_copas,Carta* baralho_paus, Carta* baralho_espada,Pilha* p);
//criar as 7 listas da mesa
ListaMesa* pilha_mesa(Pilha* p,ListaMesa* l,int n);
//criar a pilha de estoque
Pilha* Pilha_estoque(Pilha* p,Pilha* pBaralho);
//imprimir a mesa completa
void ImpListaMesaComp(ListaMesa* l1,ListaMesa* l2,ListaMesa* l3,ListaMesa* l4,ListaMesa* l5,ListaMesa* l6,ListaMesa* l7);


void preenche_baralho(Carta* vetor_baralho,char naipe ){
    srand(time(NULL)); // Sequencias diferentes de numeros aleatorios

    int i = 0;
    int j = 0;
    int random;
    int achou_igual = 0;
    vetor_baralho[0].valor = rand() % 13 + 1;
    vetor_baralho[0].naipe = naipe;
    vetor_baralho[0].flag = 0;

    for (i=1;i<13;i++){
        random = rand() % 13 + 1;
        for (j=0;j<i;j++){
            if (vetor_baralho[j].valor == random){
                i--;
                break;
            }
        }
        if (j>=i){
            vetor_baralho[i].valor = random;
            vetor_baralho[i].naipe = naipe;
            vetor_baralho[i].flag = 0;
        }
    }
}



Pilha* baralho (Carta* baralho_ouro,Carta* baralho_copas,Carta* baralho_paus, Carta* baralho_espada,Pilha* p){
    Pilha* baralho;  //
    baralho = p;
    int i ;
    for (i=0; i<13 ; i++ ) {
        pilha_push(baralho,baralho_ouro[i].flag,baralho_ouro[i].naipe,baralho_ouro[i].valor);
        pilha_push(baralho,baralho_copas[i].flag,baralho_copas[i].naipe,baralho_copas[i].valor);
        pilha_push(baralho,baralho_espada[i].flag,baralho_espada[i].naipe,baralho_espada[i].valor);
        pilha_push(baralho,baralho_paus[i].flag,baralho_paus[i].naipe,baralho_paus[i].valor);
    }
    return p;
}

ListaMesa* pilha_mesa(Pilha* p,ListaMesa* l,int n){
    int i;
    ListaMesa* lista = l;
    Carta carta;
    for (i=0; i < n ;i++){
        carta =  carta = pilha_pop(p);
        if (i == n-1)
            carta.flag = 1;
        lista = Insere_Fim(lista,carta.valor,carta.naipe,carta.flag);
    }
    return lista;
}

Pilha* Pilha_estoque(Pilha* p,Pilha* pBaralho){
    Pilha* estoque;
    estoque = p;
    Carta aux;
    while (pilha_vazia (pBaralho) != 1)  {
        aux = pilha_pop (pBaralho) ;
        pilha_push (estoque,aux.flag, aux.naipe, aux.valor);
    }
    return estoque;
}


void ImpListaMesa(ListaMesa* l,int n){
    ListaMesa* p;
    for(p=l;p!=NULL;p=p->prox){
        if (p->info.flag == 0)
            printf( "info= xx " );
        else
            printf( "%d de %c " ,p->info.valor, p->info.naipe);

    }
}

void ImpListaMesaComp(ListaMesa* l1,ListaMesa* l2,ListaMesa* l3,ListaMesa* l4,ListaMesa* l5,ListaMesa* l6,ListaMesa* l7){
    ListaMesa* p1=l1;
    ListaMesa* p2=l2;
    ListaMesa* p3=l3;
    ListaMesa* p4=l4;
    ListaMesa* p5=l5;
    ListaMesa* p6=l6;
    ListaMesa* p7=l7;
    while (p1 != NULL || p2 != NULL || p3 != NULL || p4 != NULL || p5 != NULL || p6 != NULL || p7 != NULL) {
        if (p1 != NULL){
            if (p1->info.flag == 0)	//caso o flag seja 0 não será mostrada a carta
                printf("--xx--" );
            else
                printf("%2d-%c-" ,p1->info.valor, p1->info.naipe);
            p1=p1->prox;

        }else
            printf("------"); //se não imprimir nada imprime com tracos para manter a ordem
        if (p2 != NULL){   //as duas explicações se repetem para todas as listas
            if (p2->info.flag == 0)
                printf("--xx--");
            else
                printf("-%2d-%c-" ,p2->info.valor, p2->info.naipe);

            p2=p2->prox;
        }else
            printf("------");
        if (p3 != NULL){
            if (p3->info.flag == 0)
                printf("--xx--");
            else
                printf("-%2d-%c-" ,p3->info.valor, p3->info.naipe);

            p3=p3->prox;
        }else
            printf("------");
        if (p4 != NULL) {
            if (p4->info.flag == 0)
                printf("--xx--");
            else
                printf("-%2d-%c-" ,p4->info.valor, p4->info.naipe);

            p4=p4->prox;
        }else
            printf("------");
        if (p5 != NULL){
            if (p5->info.flag == 0)
                printf("--xx--");
            else
                printf("-%2d-%c-" ,p5->info.valor, p5->info.naipe);

            p5=p5->prox;
        } else
            printf("------");
        if (p6 != NULL) {
            if (p6->info.flag == 0)
                printf("--xx--");
            else
                printf("-%2d-%c-" ,p6->info.valor, p6->info.naipe);

            p6=p6->prox;
        }else
            printf("------");
        if (p7 != NULL){
            if (p7->info.flag == 0)
                printf("--xx--");
            else
                printf("-%2d-%c-" ,p7->info.valor, p7->info.naipe);

            p7=p7->prox;
        }else
            printf("------");
        printf("\n");
    }
}
