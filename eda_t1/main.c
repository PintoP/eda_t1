#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "structs.h"

int main()
{
    gestor* gestores = NULL;
    gestores = inserirgestor(gestores, 1, "1", "1");
    cliente* clientes = NULL;
    meio* meios = NULL;
    meios = inserirmeio(meios,1, "mota", 1, 1);
    meios = inserirmeio(meios,2, "motaaa", 1, 1);
    char nome_c[50], pass_c[50], morada_c[50];
    int nif_c = 0;
    float dep_c = 0;

    char tipo[50];
    float custo = 0, auton = 0;
    int cod=0;

    int op1=0,opc=0,opc2=0;

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
                    scanf_s("%f",&dep_c);
                    deposito(clientes,nif_c,dep_c);
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
                switch (opc)
                {
                case 1://armazenar dados************************************
                    menu_esc(&opc2);
                    break;
                case 2://mostrar dados**************************************
                    menu_esc(&opc2);
                    switch (opc2)
                    {
                        case 1:
                            listarclientes(clientes);
                            break;
                        case 2:
                            listargestor(gestores);
                            break;
                        case 3:
                            listarmeio(meios);
                            break;
                        default:
                            break;
                    }
                    break;

                    break;
                case 3://inserir dados**************************************
                    menu_esc(&opc2);
                        switch (opc2)
                        {
                            case 1:
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
                            case 2:
                                printf("Insira um nome: ");
                                scanf_s("%49s", nome_c, 50);

                                printf("Insira uma senha: ");
                                scanf_s("%49s", pass_c, 50);

                                printf("nif:");
                                scanf_s("%d", &nif_c);

                                gestores = inserirgestor(gestores, nif_c, pass_c, nome_c);
                                
                                break;
                            case 3:
                                printf("Tipo de meio:");
                                scanf_s("%49s", tipo, 50);
                                printf("Autonomia:");
                                scanf_s("%f",&custo);
                                printf("Custo:");
                                scanf_s("%f", &auton);
                                meios = inserirmeio(meios, cod, tipo, custo, auton);

                                break;
                            default:
                                break;
                        }
                    break;
                case 4://alterar dados********************************

                    break;
                case 5://remover dados*********************************
                    menu_esc(&opc2);
                    switch (opc2)
                    {
                        case 1:
                            printf("Insira o nif : ");
                            scanf_s("%d", &nif_c);
                            clientes = removercliente(clientes,nif_c);
                            break;
                        case 2:
                            printf("Insira o nif : ");
                            scanf_s("%d", &nif_c);
                            gestores = removergestor(gestores, nif_c);
                            break;
                        case 3:
                            printf("Insira o cod:");
                            scanf_s("%d", &cod);
                            removermeio(meios, cod);
                            break;
                        default:
                            break;
                    }
                    break;
                default://**************************************************
                    break;
                }
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