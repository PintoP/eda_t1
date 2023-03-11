#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"

void menu_inicial(int* op)
{
    printf("1)Login\n");
    printf("2)Registar\n");
    printf("0)Sair\n");
    scanf_s("%d", op);
}

void menu_gestor(int* op)
{
    printf("Menu: \n");
    printf("1)Armazenar dados \n");
    printf("2)Mostrar dados \n");
    printf("3)Inserir dados \n");
    printf("4)Alterar dados \n");
    printf("5)Remover dados \n");
    printf("0)Sair\n");
    scanf_s("%d", op);
}

void menu_cliente(int* op)
{
    printf("1)Alugar \n");
    printf("2)Depositar saldo \n");
    printf("3)Listar por autonomia (decrescente) \n");
    printf("4)Listar meios numa determinada localizacao\n");
    printf("0)Sair\n");
    scanf_s("%d", op);
}

/*funçoes cliente*/

int existecliente(cliente* inicio, int niff)
{
    while (inicio != NULL)
    {
        if (inicio->nif == niff) return(1);
        inicio = inicio->seguinte;
    }
    return(0);
}

int c_confirmaconta(cliente* inicio, int niff, char pass[])
{
    while (inicio != NULL)
    {
        if ((inicio->nif == niff) && (strcpy(inicio->palavra_passe, pass))) return(1);
        inicio = inicio->seguinte;
    }
    return(0);
}


cliente* inserircliente(cliente* inicio, int niff, char palavra_pass[], char nomee[], char moradaa[])
{
    if (!existecliente(inicio, niff))
    {
        cliente* novo = malloc(sizeof(struct registo2));
        if (novo != NULL)
        {
            novo->nif = niff;
            strcpy(novo->palavra_passe, palavra_pass);
            strcpy(novo->nome, nomee);
            strcpy(novo->morada, moradaa);
            novo->saldo = 0;
            novo->seguinte = inicio;
            printf("sucesso");
            return(novo);
        }
    }
    else
    {
        printf("Cliente já existe");
        return inicio; /*change*/
    }
    return inicio; /*change*/
}

void listarclientes(cliente* inicio)
{
    while (inicio != NULL)
    {
        printf("%d %s %s %.2f %s\n",inicio->nif, inicio->palavra_passe, inicio->nome,
            inicio->saldo, inicio->morada);
        inicio = inicio->seguinte;
    }
}

void alugar(aluguer* algueres,int nif_a,char hora_a[],char veiculo_a[])
{
    printf("adoado");
}
/*fim funçoes cliente*/

/*funções gestor*/

int g_confirmaconta(gestor* inicio, int niff, char pass[])
{
    while (inicio != NULL)
    {
        if ((inicio->nif_g == niff) && (strcpy(inicio->palavra_passe_g, pass))) return(1);
        inicio = inicio->seguinte_g;
    }
    return(0);
}


/*fim funções gestor*/