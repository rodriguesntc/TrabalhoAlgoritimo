#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NUM_CARTAS 1000



typedef struct {
    int id;
    char primeiro_nome[20];
    char sobrenome[20];
    char time[20];
    int idade;
    int valor_mercado;
    int forca;
    int velocidade;
    int resistencia;
    int forca_vontade;
    char posicao[4];
    char machucado[4];
} CartaAtleta;

void gerar_cartas(CartaAtleta cartas[]);
void salvar_cartas(CartaAtleta cartas[]);
// trab 1 ^^

int main() {
    CartaAtleta cartas[NUM_CARTAS];
    gerar_cartas(cartas);
    salvar_cartas(cartas);
    printf("Cartas geradas e salvas com sucesso!\n");
    return 0;
}

void gerar_cartas(CartaAtleta cartas[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARTAS; i++) {
        cartas[i].id = i+1;
        // Gerar nome aleatório
        char nomes[10][20] = {"João", "Pedro", "Lucas", "Felipe", "André", "Luiz", "Marcos", "Rafael", "Leonardo", "Gustavo"};
        char sobrenomes[10][20] = {"Silva", "Santos", "Ferreira", "Oliveira", "Pereira", "Almeida", "Souza", "Nascimento", "Gomes", "Costa"};

      char posicoes [][4]={"Gol","Def","Mei","Ata"};
      char machucado [][4] = {"Sim", "Nao"};

      
        int indice_machucado = rand() % 2;
        int indice_nome = rand() % 10;
        int indice_sobrenome = rand() % 10;
        int indice_posicao = rand() % 4;
        strcpy(cartas[i].primeiro_nome, nomes[indice_nome]);
        strcpy(cartas[i].sobrenome, sobrenomes[indice_sobrenome]);
        strcpy(cartas[i].posicao, posicoes[indice_posicao]);
        strcpy(cartas[i].machucado, machucado[indice_machucado]);
      
        
        // Gerar time aleatório
      
        char times[10][20] = {"Brasil", "França", "Argentina", "Alemanha", "Itália", "Portugal", "Inglaterra", "Espanha", "Chile", "Bélgica"};
      
        int indice_time = rand() % 10;
      
        strcpy(cartas[i].time, times[indice_time]);
     
        // Gerar atributos aleatórios
        cartas[i].idade = rand() % 20 + 18;
        cartas[i].valor_mercado = rand() % 200000000;
        cartas[i].forca = rand() % 100 + 1;
        cartas[i].velocidade = rand() % 100 + 1;
        cartas[i].resistencia = rand() % 100 + 1;
        cartas[i].forca_vontade = rand() % 100 + 1;
        
    }
 


}
void salvar_cartas(CartaAtleta cartas[]) {
    FILE* arquivo = fopen("cartas.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo!\n");
        return;
    }
 
    fprintf(arquivo, "Bem vindo ao Chapéu!\n\nid,primeiro_nome,sobrenome,time,idade,valor_mercado,forca,velocidade,resistencia,forca_vontade, posicao\n\n");
  
    for (int i = 0; i < NUM_CARTAS; i++) {
        fprintf(arquivo, "%d/Nome:%s %s\n Seleção:%s\n Idade:%d\n Valor de Mercado:%d\n Força:%d\n Velocidade:%d\n Resistência:%d\n Força de vontade:%d\n Posição: %s\n Machucado:%s\n\n", cartas[i].id, cartas[i].primeiro_nome, cartas[i].sobrenome, cartas[i].time, cartas[i].idade, cartas[i].valor_mercado, cartas[i].forca, cartas[i].velocidade, cartas[i].resistencia, cartas[i].forca_vontade,cartas[i].posicao,cartas[i].machucado);
    }
    fclose(arquivo);
}



