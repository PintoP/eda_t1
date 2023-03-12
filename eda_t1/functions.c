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

void menu_esc(int* op)
{
    printf("1)Clientes");
    printf("2)Gestor");
    printf("3)Meios");
    printf("0)Sair");
    scanf_s("%d",op);
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
        return inicio;
    }
    return inicio;
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

void deposito(cliente* inicio,int niff, float d)
{
    while (inicio != NULL)
    {
        if (inicio->nif == niff)
        {
            inicio->saldo += d;
            return(1);
        }
        inicio = inicio->seguinte;
    }
    return(0);
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

int existegestor(gestor* inicio, int niff)
{
    while (inicio != NULL)
    {
        if (inicio->nif_g == niff) return(1);
        inicio = inicio->seguinte_g;
    }
    return(0);
}

gestor* inserirgestor(gestor* inicio, int niff, char palavra_pass[], char nomee[])
{
    if (!existegestor(inicio, niff))
    {
        gestor* novo = malloc(sizeof(struct registo3));
        if (novo != NULL)
        {
            novo->nif_g = niff;
            strcpy(novo->palavra_passe_g, palavra_pass);
            strcpy(novo->nome_g, nomee);
            novo->seguinte_g = inicio;
            printf("sucesso");
            return(novo);
        }
    }
    else
    {
        printf("Gestor já existe");
        return inicio; /*change*/
    }
    return inicio; /*change*/
}

void listargestor(gestor* inicio)
{
    while (inicio != NULL)
    {
        printf("%d %s %s\n", inicio->nif_g, inicio->nome_g, inicio->palavra_passe_g);
        inicio = inicio->seguinte_g;
    }
}

/*fim funções gestor*/
/*funções meios*/

void listarmeio(meio* inicio)
{
    while (inicio != NULL)
    {
        printf("%d %s %.2f %.2f %s\n",inicio->codigo, inicio->tipo, inicio->custo, inicio->bateria, inicio->loc);
        if (inicio->estado == 0)
        {
            printf("disponivel");
        }
        else {
            printf("ocupado");
        }
        inicio = inicio->seguinte_m;
    }
}

int prox_cod(meio* inicio, int codd)
{
    while (inicio != NULL)
    {
        codd = inicio->codigo;//fazer if para ver o maior cod
        inicio = inicio->seguinte_m;
    }
    return(0);
}

meio* inserirmeio(meio* inicio,int codd, char tipoo[], float custoo, float bateriaa)
{
    
    prox_cod(inicio, codd);
        meio* novo = malloc(sizeof(struct registo));
        if (novo != NULL)
        {
            novo->codigo = codd + 1;
            strcpy(novo->tipo, tipoo);
            novo->custo = custoo;
            novo->bateria = bateriaa;
            strcpy(novo->loc, "indisponivel");
            novo->seguinte_m = inicio;
            novo->estado=0;
            printf("sucesso");
            return(novo);
        }
    
    return inicio; /*change*/
}

/*fim funções meios*/