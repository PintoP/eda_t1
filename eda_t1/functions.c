#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include <float.h>
#include <stdbool.h>

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
    printf("6)Atualizar localização do veiculo \n");
    printf("7)Defenições de grafo");
    printf("0)Sair\n");
    scanf_s("%d", op);
}

void menu_grafo(int* op)
{
    printf("Menu: \n");
    printf("1)Adicionar vertice \n");
    printf("2)editar vertice \n");
    printf("3)Remover vertice \n");
    printf("4)Imprimir vertices \n");
    printf("5)criar aresta \n");
    printf("6)remover aresta\n");
    printf("7)imprimir arestas");
    printf("0)Sair\n");
    scanf_s("%d", op);
}

void menu_cliente(int* op, cliente* inicio, int niff, float g_saldo, char g_nome[])
{
    void obter_dados(inicio, niff, g_saldo, g_nome);
    printf("Nome:%s   Saldo:%f \n",g_nome,g_saldo);
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

void obter_dados(cliente* inicio, int niff,float g_saldo,char g_nome[])
{
    while (inicio != NULL)
    {
        if (inicio->nif == niff)
        {
            g_saldo = inicio->saldo;
            g_nome = inicio->nome;
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
        printf("%d %s %.2f %.2f %s ",inicio->codigo, inicio->tipo, inicio->custo, inicio->bateria, inicio->loc_abp);
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
        novo->estado = 0;
        strcpy(novo->loc_abp,"indisponovel");
        novo->seguinte_m = inicio;
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

aluguer* alugar(aluguer* inicio,cliente* inicio2, int niff,int veic)
{
    double saldo = 0, veic_custo=0;

    if (saldo-veic_custo>=0)
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
    }

    //verificar se o veic esta ocupado
    //se tem saldo sufeciente para alugar
    //registar aluguer
    //subtrarir o custo no saldo
    //por o veiculo ocupado

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
void atualizarLocalizacao(meio* veiculos, int numVeiculos, int idVeiculo, const char* localizacao) {
        while(veiculos != NULL){
            if (veiculos->codigo == idVeiculo) {
                strcpy(veiculos->loc_abp, localizacao);
                break;
            }
            veiculos = veiculos->seguinte_m;
        }
    
}




/*********** ABP funções *************/
ABP* criarGrafo() {
    ABP* g = (ABP*)malloc(sizeof(ABP));
    g->num_vertices = 8;
    g->num_arestas = 0;
    g->vertices = NULL;

    char nomes[8][50] = {
        "///latir.grandao.senha",
        "///manga.pregar.chama",
        "///joia.bombom.abalar",
        "///alho.ervas.touro",
        "///capim.vime.urubu",
        "///deseja.volto.chia",
        "///gavetão.tingido.mundão",
        "///falho.puxa.refrigerando"
    };

    char local_meios[8][50] = {
      "Igreja_Nosso_Senhor_dos_Navegantes",
      "Mc_Donalds",
      "Escola_Jose_Regio",
      "Parque_de_Jogos",
      "Praca_Jose_Regio",
      "Forte_Sao_Joao",
      "BIblioteca_Municipal",
      "Parque_da_Cidade"
    };

    for (int i = 0; i < g->num_vertices; i++) {
        vertice* novoVertice = (vertice*)malloc(sizeof(vertice));
        novoVertice->id = i;
        strcpy(novoVertice->nome, nomes[i]);
        strcpy(novoVertice->local_meio, local_meios[i]);
        novoVertice->arestas = NULL;
        novoVertice->seguinte = NULL;

        if (g->vertices == NULL) {
            g->vertices = novoVertice;
        }
        else {
            vertice* atual = g->vertices;
            while (atual->seguinte != NULL) {
                atual = atual->seguinte;
            }
            atual->seguinte = novoVertice;
        }
    }

    return g;
}
/*************************************************************************************************************************/
aresta* criarConexao() {
    aresta* listaArestas = NULL;
    int conexoes[12][3] = {
        {0, 1, 9},
        {0, 2, 7},
        {1, 2, 12},
        {1, 4, 6},
        {2, 3, 8},
        {2, 6, 15},
        {3, 4, 19},
        {3, 5, 10},
        {4, 5, 7},
        {4, 7, 11},
        {5, 6, 16},
        {6, 7, 13}
    };
    for (int i = 0; i < 12; i++) {
        int id_origem = conexoes[i][0];
        int id_destino = conexoes[i][1];
        int kms = conexoes[i][2];

        aresta* novaAresta = (aresta*)malloc(sizeof(aresta));
        novaAresta->id_origem = id_origem;
        novaAresta->id_destino = id_destino;
        novaAresta->km = kms;
        novaAresta->proxima = NULL;

        // Adiciona a nova aresta à lista de arestas
        if (listaArestas == NULL) {
            listaArestas = novaAresta;
        }
        else {
            aresta* atual = listaArestas;
            while (atual->proxima != NULL) {
                atual = atual->proxima;
            }
            atual->proxima = novaAresta;
        }
    }

    return listaArestas;
}
/******************************************************************************************************/
void associarArestas(ABP* grafo, aresta* listaArestas) {
    vertice* verticeAtual = grafo->vertices;

    // Percorre cada vértice do grafo
    while (verticeAtual != NULL) {
        aresta* arestaAtual = listaArestas;

        // Percorre a lista de arestas
        while (arestaAtual != NULL) {
            // Verifica se a aresta tem origem no vértice atual
            if (arestaAtual->id_origem == verticeAtual->id) {
                // Cria uma nova aresta e associa ao vértice atual
                aresta* novaAresta = (aresta*)malloc(sizeof(aresta));
                novaAresta->id_origem = arestaAtual->id_origem;
                novaAresta->id_destino = arestaAtual->id_destino;
                novaAresta->km = arestaAtual->km;
                novaAresta->proxima = verticeAtual->arestas;
                verticeAtual->arestas = novaAresta;
            }

            arestaAtual = arestaAtual->proxima;
        }

        verticeAtual = verticeAtual->seguinte;
    }
}
/******************************************************/
void encontrarLocalMeios(ABP* grafo, char* nome) {
    // Procura o nome fornecido no grafo
    vertice* vertice_atual = grafo->vertices;
    while (vertice_atual != NULL) {
        if (strcmp(vertice_atual->nome, nome) == 0) {
            printf("%s\n", vertice_atual->local_meio);
            return;
        }
        vertice_atual = vertice_atual->seguinte;
    }

    // Se o nome não for encontrado, exibe uma mensagem de erro
    printf("Nome \"%s\" não encontrado no grafo.\n", nome);
}

/*******************************************************/

void imprimir_info_veiculo(const char* localizacao, meio* veiculos)
{
    meio* atual = veiculos;

    while (atual != NULL)
    {
        if (strcmp(localizacao, atual->loc_abp) == 0)
        {
            printf("Tipo: %s || ", atual->tipo);
            printf("Bateria: %.2f || ", atual->bateria);
            printf("Custo: %.2f\n", atual->custo);
        }

        atual = atual->seguinte_m;
    }
}
/**********************************************************/
void encontrarVerticesAlcancaveis(ABP* grafo, int id_vertice, int kms_maximos,meio* meioos) {
    vertice* vertice_origem = NULL;

    // Encontra o vértice de origem com o ID fornecido
    vertice* vertice_atual = grafo->vertices;
    while (vertice_atual != NULL) {
        if (vertice_atual->id == id_vertice) {
            vertice_origem = vertice_atual;
            break;
        }
        vertice_atual = vertice_atual->seguinte;
    }

    // Verifica se o vértice de origem foi encontrado
    if (vertice_origem == NULL) {
        printf("Vértice de origem não encontrado.\n");
        return;
    }

    printf("Vértices alcançáveis sem ultrapassar %d km:\n", kms_maximos);

    // Inicializa uma lista para armazenar os vértices alcançáveis
    int* visitado = (int*)calloc(grafo->num_vertices, sizeof(int));
    int* vertices_alcancaveis = (int*)malloc(grafo->num_vertices * sizeof(int));
    int contador_alcancaveis = 0;

    // Inicializa uma pilha para percorrer o grafo em profundidade
    int* pilha = (int*)malloc(grafo->num_vertices * sizeof(int));
    int* kms_acumulados = (int*)malloc(grafo->num_vertices * sizeof(int));
    int topo = 0;

    // Marca o vértice de origem como visitado e o adiciona à pilha
    visitado[id_vertice] = 1;
    pilha[topo] = id_vertice;
    kms_acumulados[topo] = 0;
    topo++;

    // Percorre o grafo em profundidade
    while (topo > 0) {
        int id_atual = pilha[--topo];
        int kms_atual = kms_acumulados[topo];
        vertice_atual = grafo->vertices;

        // Encontra o vértice correspondente ao ID atual
        while (vertice_atual != NULL && vertice_atual->id != id_atual) {
            vertice_atual = vertice_atual->seguinte;
        }

        // Verifica as arestas do vértice atual
        aresta* aresta_atual = vertice_atual->arestas;
        while (aresta_atual != NULL) {
            int id_destino = aresta_atual->id_destino;
            int km_aresta = aresta_atual->km;

            int km_total = kms_atual + km_aresta;

            // Verifica se o vértice de destino já foi visitado e se a distância é menor ou igual ao limite de quilômetros
            if (!visitado[id_destino] && km_total <= kms_maximos) {
                visitado[id_destino] = 1;
                pilha[topo] = id_destino;
                kms_acumulados[topo] = km_total;
                topo++;
                vertices_alcancaveis[contador_alcancaveis++] = id_destino;
            }

            aresta_atual = aresta_atual->proxima;
        }
    }

    // Imprime o vértice de origem
// Imprime o vértice de origem
    encontrarLocalMeios(grafo, vertice_origem->nome);
    imprimir_info_veiculo(vertice_origem->nome, meioos);
    printf("\n");

    // Imprime os vértices alcançáveis
    for (int i = 0; i < contador_alcancaveis; i++) {
        int id_vertice = vertices_alcancaveis[i];
        vertice_atual = grafo->vertices;

        // Encontra o vértice correspondente ao ID atual
        while (vertice_atual != NULL && vertice_atual->id != id_vertice) {
            vertice_atual = vertice_atual->seguinte;
        }

        if (vertice_atual != NULL) {
            encontrarLocalMeios(grafo, vertice_atual->nome);
            imprimir_info_veiculo(vertice_atual->nome, meioos);
            printf("\n");
        }
    }


    // Libera a memória alocada
    free(visitado);
    free(vertices_alcancaveis);
    free(pilha);
    free(kms_acumulados);
}

/*funções para manipular o grafo*/
void atualizarVertices(vertice* vertices) {
    FILE* arquivo = fopen("abp.txt", "w");
    FILE* arquivo_bin = fopen("abp.bin", "wb");

    if (arquivo == NULL || arquivo_bin == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    vertice* novoVertice = vertices;
    while (novoVertice != NULL) {
        fprintf(arquivo, "%d %s %s\n", novoVertice->id, novoVertice->local_meio, novoVertice->nome);
        fwrite(novoVertice, sizeof(vertice), 1, arquivo_bin);
        novoVertice = novoVertice->seguinte;
    }
    fclose(arquivo);
    fclose(arquivo_bin);
}

ABP* carregarGrafo() {
    int id;
    char local_meio[50];
    char nome[50];
    char linha[100];

    ABP* g = (ABP*)malloc(sizeof(ABP));
    g->num_vertices = 0;
    g->num_arestas = 0;
    g->vertices = NULL;

    FILE* arquivo = fopen("abp.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return g;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%d %s %s\n", &id, local_meio, nome) == 3) {
            vertice* novoVertice = (vertice*)malloc(sizeof(vertice));
            novoVertice->id = id;
            strcpy(novoVertice->local_meio, local_meio);
            strcpy(novoVertice->nome, nome);
            novoVertice->arestas = NULL;
            novoVertice->seguinte = NULL;

            if (g->vertices == NULL) {
                g->vertices = novoVertice;
            }
            else {
                vertice* atual = g->vertices;
                while (atual->seguinte != NULL) {
                    atual = atual->seguinte;
                }
                atual->seguinte = novoVertice;
            }
            g->num_vertices++;
        }
    }
    fclose(arquivo);
    return g;
}


aresta* carregarAresta() {
    int id_origem, id_destino, kms;

    // Abre o ficheiro em modo leitura
    FILE* arquivo = fopen("arestas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Falha ao abrir o arquivo.\n");
        return NULL;
    }
    aresta* lista_arestas = NULL;
    // Lê os valores do ficheiro e cria as arestas      
    while (fscanf(arquivo, "%d %d %d", &id_origem, &id_destino, &kms) == 3) {
        // Cria uma nova aresta
        aresta* nova_aresta = (aresta*)malloc(sizeof(aresta));
        if (nova_aresta == NULL) {
            fclose(arquivo);
            return lista_arestas;
        }

        nova_aresta->id_origem = id_origem;
        nova_aresta->id_destino = id_destino;
        nova_aresta->km = kms;
        nova_aresta->proxima = NULL;

        // Adiciona a aresta à lista ligada
        if (lista_arestas == NULL) {
            lista_arestas = nova_aresta;
        }
        else {
            aresta* atual = lista_arestas;
            while (atual->proxima != NULL) {
                atual = atual->proxima;
            }
            atual->proxima = nova_aresta;
        }
    }
    // Fecha o ficheiro
    fclose(arquivo);
    return lista_arestas;
}

/****/
vertice* buscarVertice(ABP* g, int id) {
    g = carregarGrafo();
    vertice* atual = g->vertices;
    while (atual != NULL) {
        if (atual->id == id) {
            return atual;
        }
        atual = atual->seguinte;
    }
    return NULL; // Retorna NULL se o vértice não for encontrado
}
/******************************************************************************************************/
void criarVertice(ABP* g) {
    char nome[50];
    char local_meio[50];

    // Solicitar o nome do vértice ao usuário
    printf("Digite o geocodigo do vertice: ");
    scanf("%s", nome);

    printf("\nDigite o local do vertice: ");
    scanf("%s", local_meio);

    // Criar um novo vértice
    vertice* novoVertice = (vertice*)malloc(sizeof(vertice));
    novoVertice->id = g->num_vertices;
    strcpy(novoVertice->nome, nome);
    strcpy(novoVertice->local_meio, local_meio);

    novoVertice->arestas = NULL;
    novoVertice->seguinte = NULL;
    // Adicionar o novo vértice ao grafo
    if (g->vertices == NULL) {
        g->vertices = novoVertice;
    }
    else {
        vertice* atual = g->vertices;
        while (atual->seguinte != NULL) {
            atual = atual->seguinte;
        }
        atual->seguinte = novoVertice;
    }
    g->num_vertices++;
    // Escrever os vértices atualizados no arquivo
    atualizarVertices(g->vertices);
    printf("\nNovo vertice criado com sucesso!\n");
}
/******************************************************************************************************/
void editarVertice(ABP* g) {
    int id;
    char novoNome[50];
    char novoLocal[50];

    g = carregarGrafo();

    // Solicitar o ID do vértice a ser editado
    printf("\nDigite o ID do vertice a ser editado: ");
    scanf("%d", &id);

    // Procurar o vértice com o ID fornecido
    vertice* atual = g->vertices;
    while (atual != NULL) {
        if (atual->id == id) {
            break;
        }
        atual = atual->seguinte;
    }

    if (atual == NULL) {
        system("clear || cls");
        printf("\nVertice com o ID %d nao encontrado.", id);
        getchar();
        return;
    }

    // Solicitar o novo geocodigo do vértice ao usuário
    printf("\nDigite o novo geocodigo do vertice: ");
    scanf("%s", novoNome);

    // Atualizar o geocodigo do vértice
    strcpy(atual->nome, novoNome);

    // Solicitar o novo local do vértice ao usuário
    printf("\nDigite o novo local do vertice: ");
    scanf("%s", novoLocal);

    // Atualizar o local do vértice
    strcpy(atual->local_meio, novoLocal);

    // Escrever os vértices atualizados no arquivo
    atualizarVertices(g->vertices);

    printf("\nVertice editado com sucesso!\n");
}

void removerVertice(ABP* g) {

    int id;
    g = carregarGrafo();
    // Solicitar o ID do vértice a ser removido
    printf("\nDigite o ID do vertice a ser removido: ");
    scanf("%d", &id);
    // Verificar se o vértice existe
    vertice* atual = g->vertices;
    vertice* anterior = NULL;
    while (atual != NULL) {
        if (atual->id == id) {
            break;
        }
        anterior = atual;
        atual = atual->seguinte;
    }
    if (atual == NULL) {
        system("clear || cls");
        printf("\nVertice com o ID %d nao encontrado.", id);
        getchar();
        return;
    }
    // Remover o vértice da lista de vértices
    if (anterior == NULL) {
        // O vértice a ser removido é o primeiro da lista
        g->vertices = atual->seguinte;
    }
    else {
        // O vértice a ser removido está no meio ou no final da lista
        anterior->seguinte = atual->seguinte;
    }

    // Escrever os vértices atualizados no arquivo
    atualizarVertices(g->vertices);

    system("clear || cls");
    printf("\nVertice removido com sucesso!\n");
    getchar();
}

void imprimirVertices(ABP* g) {
    printf("Localizacoes:\n\n");
    printf("%s | %s | %s\n", "ID", "Local", "Nome");
    printf("----------------------------------\n");

    vertice* v = g->vertices;
    while (v != NULL) {
        printf("%d | %s | %s\n", v->id, v->local_meio, v->nome);
        v = v->seguinte;
    }
}

/**********************************************************************************************/
void criarAresta(ABP* g) {
    int id_origem, id_destino, kms;

    g = carregarGrafo();

    // Obter as entradas do usuário
    printf("\nDigite o ID da localizacao de origem: ");
    scanf("%d", &id_origem);

    printf("Digite o ID da localizacao de destino: ");
    scanf("%d", &id_destino);

    // Verificar se os IDs de origem e destino existem nos vértices do grafo
    vertice* vertice_origem = buscarVertice(g, id_origem);
    vertice* vertice_destino = buscarVertice(g, id_destino);
    if (vertice_origem == NULL || vertice_destino == NULL) {
        printf("\nErro: IDs de origem e/ou destino invalidos.\n");
        getchar();
        return;
    }

    // Verificar se o ID de origem é igual ao ID de destino
    if (id_origem == id_destino) {
        printf("\nErro: O ID de origem nao pode ser igual ao ID de destino.\n");
        getchar();
        return;
    }

    printf("Digite a distancia: ");
    scanf("%d", &kms);

    // Criar uma nova aresta
    aresta* nova_aresta = (aresta*)malloc(sizeof(aresta));
    if (nova_aresta == NULL) {
        printf("Erro: Falha ao alocar memoria para a nova conexao.\n");
        return;
    }
    nova_aresta->id_origem = id_origem;
    nova_aresta->id_destino = id_destino;
    nova_aresta->km = kms;
    nova_aresta->proxima = NULL;

    // Abrir o arquivo em modo de append
    FILE* arquivo = fopen("arestas.txt", "a");
    FILE* arquivo_bin = fopen("arestas.bin", "ab");

    if (arquivo == NULL || arquivo_bin == NULL) {
        printf("Erro: Falha ao abrir o arquivo.\n");
        free(nova_aresta);
        return;
    }

    // Escrever a aresta no arquivo
    fprintf(arquivo, "%d %d %d\n", nova_aresta->id_origem, nova_aresta->id_destino, nova_aresta->km);
    fwrite(nova_aresta, sizeof(aresta), 1, arquivo_bin);

    // Fechar o arquivo
    fclose(arquivo);
    fclose(arquivo_bin);

    printf("\nConexao das localizacoes criada com sucesso!\n");
    getchar();
}

void removerAresta(aresta* a) {

    int id_origem, id_destino;
    a = carregarAresta();
    if (a == NULL) {
        printf("Erro: Lista de conexoes vazia.\n");
        getchar();
        return;
    }

    printf("\nDigite o ID da localizacao de origem: ");
    scanf("%d", &id_origem);

    printf("\nDigite o ID da localizacao de destino: ");
    scanf("%d", &id_destino);

    aresta* anterior = NULL;
    aresta* atual = a;

    // Atravessa a lista para encontrar a aresta a ser removida
    while (atual != NULL) {
        if (atual->id_origem == id_origem && atual->id_destino == id_destino) {
            // Aresta encontrada, remove-a da lista 
            if (anterior == NULL) {
                a = atual->proxima;
            }
            else {
                anterior->proxima = atual->proxima;
            }

            // Liberta a memória ocupada pela aresta
            free(atual);
            printf("\nConexao removida com sucesso.\n");
            getchar();

            // Atualiza o ficheiro
            atualizarAresta(a);
            return;
        }
        anterior = atual;
        atual = atual->proxima;
    }

    printf("\nErro: Conexao nao encontrada.\n");
    getchar();
}

/**************************************************************************************/
void imprimirAresta(aresta* a) {
    a = carregarAresta();
    printf("\nLista de conexoes:\n\n");

    printf("+---------+---------+--------+\n");
    printf("| Origem  | Destino |  km    |\n");
    printf("+---------+---------+--------+\n");

    aresta* atual = a;
    while (atual != NULL) {
        printf("|%5d    |%5d    |%5d   |\n", atual->id_origem, atual->id_destino, atual->km);
        atual = atual->proxima;
    }

    printf("+---------+---------+--------+\n");
}

void atualizarAresta(aresta* a) {
    // Abrir o arquivo em modo de escrita
    FILE* arquivo = fopen("arestas.txt", "w");
    FILE* arquivo_bin = fopen("arestas.bin", "wb");

    if (arquivo == NULL || arquivo_bin == NULL) {
        printf("Erro: Falha ao abrir o arquivo.\n");
        return;
    }

    // Escreve as arestas da lista no ficheiro
    aresta* atual = a;
    while (atual != NULL) {
        fprintf(arquivo, "%d %d %d\n", atual->id_origem, atual->id_destino, atual->km);
        fwrite(atual, sizeof(aresta), 1, arquivo_bin);
        atual = atual->proxima;
    }

    // Fecha o ficheiro
    fclose(arquivo);
    fclose(arquivo_bin);
}