#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"

#define MAX_LINE_LENGTH 100

void estetica(char frase[])
{
    system("cls");
    printf("%s", frase);
    for (int z=0;z<3;z++)
    {
        Sleep(450);
        printf(".");
    }
    Sleep(600);
    system("cls");
}

void menu_inicial(int* op)
{
    printf("--MENU--\n");
    printf("1)Login\n");
    printf("2)Registar\n");
    printf("0)Sair\n");
    scanf_s("%d", op);
    system("cls");
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
    printf("--Insira uma opcao--\n");
    printf("1)Clientes\n");
    printf("2)Gestor\n");
    printf("3)Meios\n");
    printf("0)Sair\n");
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
            //printf("sucesso");
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
        printf("Nif:%d Nome:%s Saldo:%.2f Morada:%s\n",inicio->nif, inicio->nome,
            inicio->saldo, inicio->morada);
        inicio = inicio->seguinte;
    }
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

cliente* removercliente(cliente* inicio, int niff)
{
    cliente* anterior = inicio, * atual = inicio, * aux;

    if (atual == NULL) return(NULL);
    else if (atual->nif == niff) // remoção do 1º registo
    {
        aux = atual->seguinte;
        free(atual);
        return(aux);
    }
    else
    {
        while ((atual != NULL) && (atual->nif != niff))
        {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual == NULL) return(inicio);
        else
        {
            anterior->seguinte = atual->seguinte;
            free(atual);
            return(inicio);
        }
    }
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
    {/*
        if (inicio->nif_g == niff) return(1);
        inicio = inicio->seguinte_g;*/
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
            //printf("sucesso");
            return(novo);
        }
    }
    else
    {
        printf("Gestor já existe");
        return inicio;
    }
    return inicio; 
}

void listargestor(gestor* inicio)
{
    while (inicio != NULL)
    {
        printf("Nif:%d Nome:%s\n", inicio->nif_g, inicio->nome_g);
        inicio = inicio->seguinte_g;
    }
}

gestor* removergestor(gestor* inicio, int niff)
{
    gestor* anterior = inicio, * atual = inicio, * aux;

    if (atual == NULL) return(NULL);
    else if (atual->nif_g == niff)
    {
        aux = atual->seguinte_g;
        free(atual);
        return(aux);
    }
    else
    {
        while ((atual != NULL) && (atual->nif_g != niff))
        {
            anterior = atual;
            atual = atual->seguinte_g;
        }
        if (atual == NULL) return(inicio);
        else
        {
            anterior->seguinte_g = atual->seguinte_g;
            free(atual);
            return(inicio);
        }
    }
}

/*fim funções gestor*/
/*funções meios*/

void listarmeio(meio* inicio)
{
    while (inicio != NULL)
    {
        printf("%d %s %.2f %.2f %s ",inicio->codigo, inicio->tipo, inicio->custo, inicio->bateria, inicio->loc);
        if (inicio->estado == 0)
        {
            printf("disponivel\n");
        }
        else {
            printf("ocupado");
        }
        inicio = inicio->seguinte_m;
    }
}

int prox_cod(meio* inicio, int* codd)
{
    while (inicio != NULL)
    {
        if ((inicio->codigo) > *codd)
        {
            *codd = inicio->codigo;
        }
        inicio = inicio->seguinte_m;
    }
    *codd += 1;
    return(0);
}

meio* inserirmeio(meio* inicio, int codd, char tipoo[], float custoo, float bateriaa)
{
    prox_cod(inicio, &codd);

    meio* novo = malloc(sizeof(struct registo));
    if (novo != NULL)
    {
        novo->codigo = codd;
        strcpy(novo->tipo, tipoo);
        novo->custo = custoo;
        novo->bateria = bateriaa;
        strcpy(novo->loc, "indisponivel");
        novo->seguinte_m = inicio;
        novo->estado = 0;
        //printf("sucesso");
        return(novo);
    }

    return inicio;
}

meio* removermeio(meio* inicio, int cod)
{
    meio* anterior = inicio, * atual = inicio, * aux;

    if (atual == NULL) return(NULL);
    else if (atual->codigo == cod) // remoção do 1º registo
    {
        aux = atual->seguinte_m;
        free(atual);
        return(aux);
    }
    else
    {
        while ((atual != NULL) && (atual->codigo != cod))
        {
            anterior = atual;
            atual = atual->seguinte_m;
        }
        if (atual == NULL) return(inicio);
        else
        {
            anterior->seguinte_m = atual->seguinte_m;
            free(atual);
            return(inicio);
        }
    }
}

/*fim funções meios*/
/*funções aluguer*/

aluguer* alugar(aluguer* inicio, int niff,int veic)
{
    aluguer* novo = malloc(sizeof(struct registo));
    if (novo != NULL)
    {
        novo->nif_a = niff;
        novo->veiculo_cod = veic;
        novo->seguinte_a = inicio;
        //printf("sucesso");
        return(novo);
    }

    return inicio;
}

void listaraluguer(aluguer* inicio)
{
    while (inicio != NULL)
    {
        printf("nif do aluguer: %d, codigo do carro alugado: %d\n", inicio->nif_a, inicio->veiculo_cod);
        inicio = inicio->seguinte_a;
    }
}

/*fim funções ãluguer*/


/*armazenamento e leitura*/

void armazena(cliente* inicio, gestor* inicio2, meio* inicio3, aluguer* inicio4)
{
    FILE* arquivo;
    arquivo = fopen("C:/Users/dific/OneDrive/Desktop/eda_t1/eda_t1/clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    while (inicio != NULL)
    {
        fprintf(arquivo, "%d;%s;%s;%.2f;%s;\n", inicio->nif, inicio->palavra_passe, inicio->nome, inicio->saldo, inicio->morada);
        inicio = inicio->seguinte;
    }
    fclose(arquivo);
    /**/
    arquivo = fopen("C:/Users/dific/OneDrive/Desktop/eda_t1/eda_t1/gestores.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    while (inicio2 != NULL)
    {
        fprintf(arquivo, "%d;%s;%s;\n", inicio2->nif_g, inicio2->palavra_passe_g, inicio2->nome_g);
        inicio2 = inicio2->seguinte_g;
    }
    fclose(arquivo);
    /**/
    FILE* arq2;
    arq2 = fopen("C:/Users/dific/OneDrive/Desktop/eda_t1/eda_t1/meios.txt", "w");
    if (arq2 == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    while (inicio3 != NULL)
    {
        fprintf(arq2, "%d;%s;%.2f;%.2f;%s;", inicio3->codigo, inicio3->tipo, inicio3->custo, inicio3->bateria, inicio3->loc);
        if (inicio3->estado == 0)
        {
            fprintf(arq2, "disponivel;\n");
        }
        else {
            fprintf(arq2, "ocupado;\n");
        }
        inicio3 = inicio3->seguinte_m;
    }
    fclose(arq2);
    /**/
    arq2 = fopen("C:/Users/dific/OneDrive/Desktop/eda_t1/eda_t1/aluguer.txt", "w");
    if (arq2 == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    while (inicio4 != NULL)
    {
        fprintf(arq2, "%d;%d;\n",inicio4->nif_a, inicio4->veiculo_cod);
        inicio4 = inicio4->seguinte_a;
    }
    fclose(arq2);
}

void armazenabin(cliente* inicio, gestor* inicio2, meio* inicio3, aluguer* inicio4)
{
    FILE* arquivo;
    arquivo = fopen("C:/Users/dific/OneDrive/Desktop/eda_t1/eda_t1/clientes.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    while (inicio != NULL)
    {
        fwrite(inicio, sizeof(cliente), 1, arquivo);
        inicio = inicio->seguinte;
    }
    fclose(arquivo);

    arquivo = fopen("C:/Users/dific/OneDrive/Desktop/eda_t1/eda_t1/gestores.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    while (inicio2 != NULL)
    {
        fwrite(inicio2, sizeof(gestor), 1, arquivo);
        inicio2 = inicio2->seguinte_g;
    }
    fclose(arquivo);

    FILE* arq2;
    arq2 = fopen("C:/Users/dific/OneDrive/Desktop/eda_t1/eda_t1/meios.bin", "wb");
    if (arq2 == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    while (inicio3 != NULL)
    {
        fwrite(inicio3, sizeof(meio), 1, arq2);
        inicio3 = inicio3->seguinte_m;
    }
    fclose(arq2);

    arq2 = fopen("C:/Users/dific/OneDrive/Desktop/eda_t1/eda_t1/aluguer.bin", "wb");
    if (arq2 == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    while (inicio4 != NULL)
    {
        fwrite(inicio4, sizeof(aluguer), 1, arq2);
        inicio4 = inicio4->seguinte_a;
    }
    fclose(arq2);
}


void ler_contas(cliente* inicio, gestor* inicio2, meio* inicio3)
{
    FILE* arquivo;
    char line[100];
    arquivo = fopen("C:/Users/dific/OneDrive/Desktop/eda_t1/eda_t1/clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    int campo1;
    float campo4;
    char campo2[50], campo3[50], campo5[50];
    while (fgets(line, 100, arquivo) != NULL) {
        

        int num_campos_lidos = sscanf(line, "%d;%[^;];%[^;];%f;%s", &campo1, campo2, campo3, &campo4, campo5);
        if (num_campos_lidos != 5) {
            printf("Erro na linha: %s", line);
        
        }
            inicio = inserircliente(inicio, campo1, campo2, campo3, campo5);
            deposito(inicio,campo1,campo4);
    }
    fclose(arquivo);

}




void ordenar(meio* inicio)
{
    if (inicio == NULL || inicio->seguinte_m == NULL)
    {
        return; // lista vazia ou com apenas um elemento
    }

    meio* novo_inicio = NULL;
    meio* atual = inicio;

    while (atual != NULL)
    {
        meio* prox = atual->seguinte_m;

        // insere o elemento atual na lista ordenada pelo campo "bateria"
        if (novo_inicio == NULL || atual->bateria > novo_inicio->bateria)
        {
            atual->seguinte_m = novo_inicio;
            novo_inicio = atual;
        }
        else
        {
            meio* anterior = novo_inicio;
            while (anterior->seguinte_m != NULL && anterior->seguinte_m->bateria >= atual->bateria)
            {
                anterior = anterior->seguinte_m;
            }
            atual->seguinte_m = anterior->seguinte_m;
            anterior->seguinte_m = atual;
        }

        atual = prox;
    }

    printf("Valores ordenados por bateria (ordem decrescente):\n");

    meio* p = novo_inicio;
    while (p != NULL)
    {
        printf("Codigo: %d, Tipo: %s, Bateria: %.2f, Custo: %.2f, Localizacao: %s, Estado: %d\n",
            p->codigo, p->tipo, p->bateria, p->custo, p->loc, p->estado);
        p = p->seguinte_m;
    }
}
 
void det_zona(meio* inicio)
{
    char zona[20];
    printf("Insira o geo-code");
    scanf_s("%19s",zona,20);

    while (inicio != NULL)
    {
        if (strcmp(inicio->loc, zona)==0) {
            printf("%d %s %.2f %.2f %s ", inicio->codigo, inicio->tipo, inicio->custo, inicio->bateria, inicio->loc);
            if (inicio->estado == 0)
            {
                printf("disponivel\n");
            }
            else {
                printf("ocupado");
            }
        }
        inicio = inicio->seguinte_m;
    }

}