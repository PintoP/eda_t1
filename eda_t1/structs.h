#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LINE_LENGTH 100

typedef struct registo
{
	int codigo;
	char tipo[50];
	float bateria;
	float custo;
	char loc[50];
	int estado;//1-opcupado      0-disponivel

	struct registo* seguinte_m;
} meio;
void listarmeio(meio* inicio);
int prox_cod(meio* inicio, int* cod);
meio* inserirmeio(meio* inicio, int cod, char tipo[], float custo, float bateria);
meio* removermeio(meio* inicio, int cod);
void ordenar(meio* inicio);
void det_zona(meio* inicio);

typedef struct registo2 {
	int nif;
	char palavra_passe[50];
	char nome[50];
	char morada[50];
	float saldo;
	struct registo2* seguinte;
} cliente;

cliente* inserircliente(cliente* inicio,int nif,char palavra_passe[],char nome[],char morada[]);
void listarclientes(cliente* inicio);
int existecliente(cliente* inicio, int nif);
int c_confirmaconta(cliente* inicio, int nif,char palavra_passe[]);
cliente* removercliente(cliente* inicio, int nif);
void obter_dados(cliente* inicio, int niff, float g_saldo, char g_nome[]);

void deposito(cliente* inicio, int nif, float n);
typedef struct registo3
{
	int nif_g;
	char nome_g[50];
	char palavra_passe_g[50];
	struct registo3* seguinte_g;
}gestor;
gestor* inserirgestor(gestor* inicio,int nif_g,char palavra_passe_g[],char nome[]);
int existegestor(gestor* inicio, int nif);
void listargestor(gestor* inicio);

typedef struct registo4
{
	int nif_a;
	int veiculo_cod;
	struct registo4* seguinte_a;
}aluguer;
void listaraluguer(aluguer* inicio);
aluguer* alugar(aluguer* inicio, int nidd, int codd);

/*funções a parte*/
void estetica(char frase[]);
void armazena(cliente* inicio,gestor* inicio2,meio* inicio3,aluguer* inicio4);
void armazenabin(cliente* inicio,gestor* inicio2,meio* inicio3,aluguer* inicio4);
void ler_contas(cliente* inicio, gestor* inicio2, meio* inicio3);







/*abp*/
typedef struct registo5
{
	int numero;
	char nome[50];
	struct registo5* esquerda;
	struct registo5* direita;
}ABP;