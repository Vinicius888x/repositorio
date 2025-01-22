#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGURA_PADRAO 3
#define ALTURA_PADRAO 50
#define ESPACAMENTO_PADRAO 4

// estruturas e funções auxiliares
int verificar_codigo_barras(const char *linha, int largura_area, int inicio, int fim, char *codigo_barras) {
    int pos = 0;
    for (int i = inicio; i < fim; i += largura_area) {
        int soma = 0;
        for (int j = 0; j < largura_area; j++) {
            soma += linha[i + j] - '0';
        }
        if (soma > largura_area / 2) {
            codigo_barras[pos++] = '1';
        } else {
            codigo_barras[pos++] = '0';
        }
    }
    codigo_barras[pos] = '\0';
    return 1;
}

int extrair_identificador(const char *codigo_barras, char *identificador) {
    // aqui pega os 4 dígitos L-code e 4 dígitos R-code
    const char *l_codes[10] = {"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"};
    const char *r_codes[10] = {"1110010", "1100110", "1101100", "1000010", "1011100", "1001110", "1010000", "1000100", "1001000", "1110100"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if (strncmp(&codigo_barras[3 + i * 7], l_codes[j], 7) == 0) {
                identificador[i] = '0' + j;
                break;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if (strncmp(&codigo_barras[45 + i * 7], r_codes[j], 7) == 0) {
                identificador[i + 4] = '0' + j;
                break;
            }
        }
    }

    identificador[8] = '\0';
    return 1;
}

// Função principal
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo_pbm>\n", argv[0]);
        return 1;
    }

    const char *nome_arquivo = argv[1];
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    char tipo[3];
    int largura, altura;

    fscanf(arquivo, "%2s", tipo);
    if (strcmp(tipo, "P1") != 0) {
        fprintf(stderr, "Arquivo não é um PBM válido.\n");
        fclose(arquivo);
        return 1;
    }

    fscanf(arquivo, "%d %d", &largura, &altura);

    char *linha = malloc(largura + 1);
    char codigo_barras[100];
    char identificador[9];

    for (int i = 0; i < altura; i++) {
        fscanf(arquivo, "%s", linha);
        if (strstr(linha, "101")) {
            verificar_codigo_barras(linha, LARGURA_PADRAO, 3, largura - 3, codigo_barras);
            extrair_identificador(codigo_barras, identificador);
            printf("Identificador extraído: %s\n", identificador);
            break;
        }
    }

    free(linha);
    fclose(arquivo);
    return 0;
}
