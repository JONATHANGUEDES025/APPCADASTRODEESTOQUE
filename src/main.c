#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    char nome[50];
    int quantidade;
    double preco;
};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

double lerPreco() {
    char texto[30];

    scanf("%29s", texto);
    limparBuffer();

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == ',') {
            texto[i] = '.';
        }
    }

    return atof(texto);
}

double valorTotal(struct produto *estoque, int n) {
    double total = 0.0;

    for (int i = 0; i < n; i++) {
        total += estoque[i].quantidade * estoque[i].preco;
    }

    return total;
}

int main() {
    int n;

    printf("Digite a quantidade de produtos que deseja cadastrar: ");
    scanf("%d", &n);
    limparBuffer();

    if (n <= 0) {
        printf("Quantidade invalida.\n");
        printf("\nPressione ENTER para sair...");
        getchar();
        return 1;
    }

    struct produto *estoque = malloc(n * sizeof(struct produto));

    if (estoque == NULL) {
        printf("Erro ao alocar memoria.\n");
        printf("\nPressione ENTER para sair...");
        getchar();
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nQual o nome do produto %d:\n", i + 1);
        fgets(estoque[i].nome, sizeof(estoque[i].nome), stdin);

        estoque[i].nome[strcspn(estoque[i].nome, "\n")] = '\0';

        printf("Qual a quantidade do produto %d:\n", i + 1);
        scanf("%d", &estoque[i].quantidade);
        limparBuffer();

        printf("Qual o valor do produto %d:\n", i + 1);
        estoque[i].preco = lerPreco();
    }

    double total = valorTotal(estoque, n);

    printf("\n===== PRODUTOS CADASTRADOS =====\n");

    for (int i = 0; i < n; i++) {
        printf("Produto: %s | Quantidade: %d | Valor: R$ %.2f | Subtotal: R$ %.2f\n",
               estoque[i].nome,
               estoque[i].quantidade,
               estoque[i].preco,
               estoque[i].quantidade * estoque[i].preco);
    }

    printf("\nValor total em estoque: R$ %.2f\n", total);

    free(estoque);

    printf("\nPressione ENTER para sair...");
    getchar();

    return 0;
}