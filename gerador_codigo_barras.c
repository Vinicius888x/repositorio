#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LARGURA_PADRAO 3
#define ALTURA_PADRAO 50
#define ESPACAMENTO_PADRAO 4
#define NOME_ARQUIVO_PADRAO "codigo_de_barras.pbm"


int calcular_digito_verificador(const char *identificador) {
    int soma = 0;
    for (int i = 0; i < 7; i++) {
        int digito = identificador[i] - '0';
        soma += (i % 2 == 0) ? digito * 3 : digito;
    }
    int proximo_multiplo = ((soma + 9) / 10) * 10;
    return proximo_multiplo - soma;
}

void gerar_imagem_pbm(const char *codigo_barras, int largura_area, int altura, int espacamento_lateral, const char *nome_arquivo) {
    int largura_total = (3 + 28 + 5 + 28 + 3) * largura_area + 2 * espacamento_lateral;
    int altura_total = altura + 2 * espacamento_lateral;

    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        fprintf(stderr, "Erro ao criar o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    fprintf(arquivo, "P1\n");
    fprintf(arquivo, "%d %d\n", largura_total, altura_total);

    for (int y = 0; y < altura_total; y++) {
        for (int x = 0; x < largura_total; x++) {
            if (y < espacamento_lateral || y >= altura_total - espacamento_lateral ||
                x < espacamento_lateral || x >= largura_total - espacamento_lateral) {
                fprintf(arquivo, "0 "); // Espaçamento
            } else {
                int pos = (x - espacamento_lateral) / largura_area;
                if (codigo_barras[pos] == '1') {
                    fprintf(arquivo, "1 ");
                } else {
                    fprintf(arquivo, "0 ");
                }
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Arquivo %s gerado com sucesso.\n", nome_arquivo);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <identificador> [espacamento] [largura] [altura] [nome_arquivo]\n", argv[0]);
        return 1;
    }

    const char *identificador = argv[1];
    if (strlen(identificador) != 8 || !isdigit(identificador[0])) {
        fprintf(stderr, "Identificador inválido. Deve conter exatamente 8 dígitos numéricos.\n");
        return 1;
    }

    int digito_verificador = calcular_digito_verificador(identificador);
    if (digito_verificador != identificador[7] - '0') {
        fprintf(stderr, "Dígito verificador inválido.\n");
        return 1;
    }

    int espacamento = (argc > 2) ? atoi(argv[2]) : ESPACAMENTO_PADRAO;
    int largura = (argc > 3) ? atoi(argv[3]) : LARGURA_PADRAO;
    int altura = (argc > 4) ? atoi(argv[4]) : ALTURA_PADRAO;
    const char *nome_arquivo = (argc > 5) ? argv[5] : NOME_ARQUIVO_PADRAO;

    // lembrar de substituir pela lógica real
    const char *codigo_barras = "0000000000000000000";

    gerar_imagem_pbm(codigo_barras, largura, altura, espacamento, nome_arquivo);

    return 0;
}
