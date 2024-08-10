#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TADLISTA.h"

void liberarLista(TLista *Lista){
    TProduto aux;
    aux = Lista->primeiro->item;
    while(!Vazia(*Lista)){
        Excluir(Lista,&aux);
    }
    free(Lista);

}

int Vazia(TLista Lista){
    return (Lista.primeiro==Lista.ultimo);
}

void FLVazia(TLista *Lista){
    Lista -> primeiro = (TCelula*)malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista -> tamanho = 0;
}

void Inserir(TProduto x, TLista *Lista){
    Lista -> ultimo -> prox = (TCelula*)malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;
}

void IMprimir(TLista Lista){
    TCelula* Aux;
    Aux = Lista.primeiro->prox;
    int c = 0;
    printf("\tIMPRESSAO DA LISTA\n------------------------------------------------\n");
    while(Aux!=NULL){
        printf("%d-/%s",c, Aux->item.nome);
        Aux = Aux -> prox;
        c++;
    }
}

void LerProduto(TProduto *produto){
    printf("insira a quantidade do produto :");
    fflush(stdin);
        scanf("%d",&(produto->quantidade));
    printf("insira o nome do produto :");
        fflush(stdin);
        fgets(produto->nome, 31, stdin); 
    printf("insira o codigo do produto :");
        fflush(stdin);
        fgets(produto->codigo, 10, stdin);  
    printf("insira a descricao do produto :");
        fflush(stdin);
        fgets(produto->descricao, 50, stdin);
    printf("------------------------------------------------\n");
}

void ImprimirProduto(TProduto produto){
    printf("\n-----------------------------------------------");
    printf("\n\tDADOS DO PRODUTO");
    printf("\nnome:\t\t\t\t %s ",produto.nome);
    printf("\nquantidade:\t\t\t\t %d ",produto.quantidade);
    printf("\ncodigo:\t\t\t\t %s ",produto.codigo);
    printf("\ndescricao:\n\t %s ",produto.descricao);
}

TCelula* Pesquisar(TLista Lista,TProduto Produto){
    TCelula* Aux = Lista.primeiro;
    while (Aux->prox != NULL)
    {
        if ((strcmp(Aux->prox->item.codigo,Produto.codigo))==0){
            printf("\nproduto encontrado!\n");
            return Aux;
        }   
        Aux = Aux->prox;
    }
    printf("\nproduto nao encontrado\n");
    return NULL;
}

TCelula* PesquisarPorNome(TLista Lista,TProduto Produto){
    TCelula* Aux = Lista.primeiro;
    while (Aux->prox != NULL)
    {
        if (strcmp(Aux->prox->item.nome,Produto.nome)==0){
            printf("\nproduto encontrado!");
            ImprimirProduto(Aux->prox->item);
            return Aux;
        }
        else if (Aux->prox == NULL)
        {
            printf("\nnao encontrado\n");
        }
        Aux = Aux->prox;

    }
    return NULL;
}

    void Excluir(TLista* Lista,TProduto* Produto){
        TCelula *Aux1, *Aux2;
        Aux1 = Pesquisar(*Lista, *Produto);
        if (Aux1 != NULL)
        {
            Aux2=Aux1->prox;
            Aux1->prox = Aux2->prox;
            *Produto = Aux2->item;
            if (Aux1 == NULL)
                Lista->ultimo = Aux1;
            free(Aux2);
            printf("\nproduto excluido com sucesso!\n");
            Lista->tamanho--;
        }    
    }

