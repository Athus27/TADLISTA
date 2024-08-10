#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "interface.h"
#include "TADlista.h"

void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
}

void MENU(TLista *lista){
    TProduto produto;
    int opcao=0;
    bool i;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                LerProduto(&produto);
                Inserir(produto,lista);
                break;
            case 2:
                printf("\ninsira os dados do produto que deseja pesquisar:\n ");
                    LerProduto(&produto);
                    Pesquisar(*lista,produto);
                system("PAUSE");
                
                break;
            case 3:
                printf("\ntem certeza que deseja excluir um produto? ");
                    scanf("%d",&i);
                        if (i!=0){
                            printf("\npor favor insira os dados do produto que deseja remover\n");
                            LerProduto(&produto);
                        }
                        else{
                            printf("\noperacao cancelada!\n");
                            system("PAUSE");
                            break;
                            }
                Excluir(lista,&produto);
                    
                system("PAUSE");
                break;
            case 4:
                IMprimir(*lista);
                system("PAUSE");
                break;
            case 5:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}
