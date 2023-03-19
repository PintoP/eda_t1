#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "structs.h"

#define MAX_LINE_LENGTH 100

int main()
{
    aluguer* alugueres = NULL;
    gestor* gestores = NULL;
    gestores = inserirgestor(gestores, 1, "1", "1");
    cliente* clientes = NULL;
    meio* meios = NULL;
    meios = inserirmeio(meios,1, "mota", 1, 12);
    meios = inserirmeio(meios,2, "motaaa", 1, 122);
    char nome_c[50], pass_c[50], morada_c[50];
    int nif_c = 0,veiculo_esc=0;
    float dep_c = 0;
    int c_logada;
    char tipo[50],zona[15];
    float custo = 0, auton = 0;
    int cod=0;
   // ler_contas(clientes, gestores, meios);
    int op1=0,opc=0,opc2=0,opc3=0;

    do
    {
        menu_inicial(&op1);

        switch (op1)
        {
        case 1:
            printf("Insira o NIF: ");
            scanf_s("%d", &nif_c);
            c_logada=nif_c;
            printf("Insira uma senha: ");
            scanf_s("%49s", pass_c, 50);
            system("cls");
            
            if (c_confirmaconta(clientes, nif_c, pass_c))
            {
                menu_cliente(&opc);
                switch (opc)
                {
                case 1://aluguer
                    listarmeio(meios);
                    scanf_s("%d", &veiculo_esc);
                    alugueres=alugar(alugueres, nif_c,veiculo_esc);
                    break;
                case 2://adicionar dinheiro na conta
                    scanf_s("%f",&dep_c);
                    deposito(clientes,nif_c,dep_c);
                    break;
                case 3://ordem por aut
                    ordenar(meios);
                    break;
                case 4://veiculos em uma zona
                    det_zona(meios);
                    break;
                }
            }
            else if (g_confirmaconta(gestores, nif_c, pass_c))
            {
                do
                {
                    menu_gestor(&opc);
                    switch (opc)
                    {
                    case 1://armazenar dados************************************
                    
                            armazena(clientes, gestores, meios);
                      
                        break;
                    case 2://mostrar dados**************************************
                        printf("--Insira uma opcao--\n1)Clientes\n2)Gestor\n3)Meios\n4)Alugueres\n0)Sair");
                        scanf_s("%d",&opc2);
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
                        case 4://aluguer
                            listaraluguer(alugueres);
                            break;
                        default:
                            break;
                        }
                        break;

                        break;
                    case 3://inserir dados**************************************
                        menu_esc(&opc2);
                        system("cls");
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

                            clientes = inserircliente(clientes, nif_c, pass_c, nome_c, morada_c);
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
                            scanf_s("%f", &custo);
                            printf("Custo:");
                            scanf_s("%f", &auton);
                            meios = inserirmeio(meios, cod, tipo, custo, auton);

                            break;
                        default:
                            break;
                        }
                        break;
                    case 4://alterar dados********************************
                        menu_esc(&opc2);
                        switch (opc2)
                        {
                            
                        case 1:
                            listarclientes(clientes);
                            printf("Nif do cliente que deseja alterar as infos:");
                            scanf_s("%d",&nif_c);
                            clientes=removercliente(clientes, nif_c);
                            nif_c = 0;
                            printf("Insira o novo nif:");
                            scanf_s("%d", &nif_c);

                            printf("Insira o novo nome:");
                            scanf_s("%49s", nome_c, 50);

                            printf("Insira a nova palavra-passe:");
                            scanf_s("%49s", pass_c, 50);

                            printf("Insira a nova morada:");
                            scanf_s("%49s", morada_c, 50);

                            
                            clientes = inserircliente(clientes,nif_c,pass_c, nome_c,morada_c);
                            printf("Informações do cliente alteradas");
                            break;
                        case 2:
                            listargestor(gestores);
                            printf("Nif do gestores que deseja alterar as infos:");
                            scanf_s("%d", &nif_c);
                            gestores=removergestor(gestores, nif_c);
                            printf("Insira o novo nif:");
                            scanf_s("%d", &nif_c);

                            printf("Insira o novo nome:");
                            scanf_s("%49s", nome_c, 50);

                            printf("Insira o nova palavra-passe:");
                            scanf_s("%49s", pass_c, 50);


                           gestores = inserirgestor(gestores, nif_c, nome_c, pass_c);
                            printf("Informações do gestor alteradas");

                            break;
                        case 3:
                            listarmeio(meios);
                            printf("cod do gestores que deseja alterar as infos:");
                            scanf_s("%d", &nif_c);
                            meios=removermeio(meios,nif_c);
                            printf("Insira o novo tipo:");
                            scanf_s("%d", &nif_c);

                            printf("Insira a nova autonomia:");
                            scanf_s("%f",&auton);

                            printf("Insira o novo custo:");
                            scanf_s("%f", &custo);

                            inserirmeio(meios,cod,nif_c,custo,auton);
                            break;
                        }
                        break;
                    case 5://remover dados*********************************
                        menu_esc(&opc2);
                        switch (opc2)
                        {
                        case 1:
                            printf("Insira o nif : ");
                            scanf_s("%d", &nif_c);
                            clientes = removercliente(clientes, nif_c);
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
                }while (opc != 0);
            }
            else
            {
                printf("Nao existe nenhum utilizador com essas credenciais");
            }

            break;

        case 2:
            printf("--Registo--\n");
            printf("Insira um nome: ");
            scanf_s("%49s", nome_c, 50);

            printf("Insira uma senha: ");
            scanf_s("%49s", pass_c, 50);

            printf("Insira a morada:");
            scanf_s("%49s", morada_c, 50);

            printf("nif:");
            scanf_s("%d", &nif_c);
            estetica("Registado com sucesso");
            clientes = inserircliente(clientes, nif_c, pass_c, nome_c, morada_c, 0);
            break;

        default:
            return 0;
        }

        
    }while(op1!=0);
}