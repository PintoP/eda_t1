#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "structs.h"

int main()
{
    gestor* gestores = NULL;
    cliente* clientes = NULL;
    char nome_c[50], pass_c[50], morada_c[50];
    int nif_c = 0, saldo_c=0;
    int op1=0,opc=0;

    do
    {
        menu_inicial(&op1);

        switch (op1)
        {
        case 1:
            printf("Insira o NIF: ");
            scanf_s("%d", &nif_c);

            printf("Insira uma senha: ");
            scanf_s("%49s", pass_c, 50);

            
            if (c_confirmaconta(clientes, nif_c, pass_c))
            {
                menu_cliente(&opc);
                switch (opc)
                {
                case 1://aluguer
                    
                    break;
                case 2://adicionar dinheiro na conta
                    
                    break;
                case 3://ordem por aut
                    
                    break;
                case 4://veiculos em uma zona
                    
                    break;
                }

            }
            else if (g_confirmaconta(gestores, nif_c, pass_c))
            {
                menu_gestor(&opc);
            }
            else
            {
                printf("Nao existe nenhum utilizador com essas credenciais");
            }

            break;

        case 2:
            printf("Insira um nome: ");
            scanf_s("%49s", nome_c, 50);

            printf("Insira uma senha: ");
            scanf_s("%49s", pass_c, 50);

            printf("Insira a morada:");
            scanf_s("%49s", morada_c, 50);

            printf("nif:");
            scanf_s("%d", &nif_c);

            clientes = inserircliente(clientes, nif_c, pass_c, nome_c, morada_c, 0);
            break;

        default:
            return 0;
        }

        
    }while(op1!=0);
}