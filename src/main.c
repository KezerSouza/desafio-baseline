#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENV_FILE "../config.env"
#define MAX_LINE 256

int lerQuantidade() {
    FILE *f = fopen(ENV_FILE, "r");
    if (!f) {
        fprintf(stderr, "Erro: nao foi possivel abrir %s\n", ENV_FILE);
        exit(1);
    }

    char linha[MAX_LINE];
    while (fgets(linha, sizeof(linha), f)) {
        // Remove newline
        linha[strcspn(linha, "\r\n")] = '\0';

        char *eq = strchr(linha, '=');
        if (!eq) continue;

        *eq = '\0';
        char *chave = linha;
        char *valor = eq + 1;

        if (strcmp(chave, "QUANTIDADE_DE_NUMEROS") == 0) {
            int qtd = atoi(valor);
            fclose(f);
            return qtd;
        }
    }

    fclose(f);
    fprintf(stderr, "Erro: QUANTIDADE_DE_NUMEROS nao encontrada no config.env\n");
    exit(1);
}

int main() {
    int quantidade = lerQuantidade();

    if (quantidade <= 0) {
        fprintf(stderr, "Erro: QUANTIDADE_DE_NUMEROS deve ser maior que zero.\n");
        return 1;
    }

    printf("=== Somador ===\n");
    printf("Somando %d numero(s).\n\n", quantidade);

    double soma = 0.0;
    for (int i = 1; i <= quantidade; i++) {
        double num;
        printf("Digite o %do numero: ", i);
        if (scanf("%lf", &num) != 1) {
            fprintf(stderr, "Erro: entrada invalida.\n");
            return 1;
        }
        soma += num;
    }

    printf("\nResultado: %.2f\n", soma);
    return 0;
}
