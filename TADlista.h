#ifndef TADLISTA_H_INCLUDED //matro de definição "se esta constante não foi definida, definir... linha 2"
#define TADLISTA_H_INCLUDED // se ela já esta definida o código não é executado, basicamente evita duplicidade;

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[31];
    char descricao[51];
    char codigo[10];
    int quantidade;
}TProduto;

typedef struct celula{
    TProduto item;
    struct celula* prox;
}TCelula;

typedef struct{
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

void FLVazia(TLista *Lista);
void Inserir(TProduto x, TLista *Lista);
void IMprimir(TLista Lista);
void LerProduto(TProduto *produto);
//
void ImprimirProduto(TProduto produto);
TCelula* Pesquisar(TLista Lista,TProduto Produto);
TCelula* PesquisarPorNome(TLista Lista,TProduto Produto);
void Excluir(TLista* Lista,TProduto* Produto);
TCelula* Pesquisar(TLista Lista,TProduto Produto);
void liberarLista(TLista *lista);
int Vazia(TLista Lista);

#endif



