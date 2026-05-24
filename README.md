# Contador de Estoque em C

Este projeto é um programa simples desenvolvido em linguagem C para cadastrar produtos em estoque, calcular o subtotal de cada item e exibir o valor total armazenado.

O sistema permite que o usuário informe a quantidade de produtos que deseja cadastrar, registre nome, quantidade e preço de cada produto, e ao final visualize uma lista completa com os produtos cadastrados e o valor total do estoque.

## Funcionalidades

- Cadastro de múltiplos produtos
- Leitura do nome do produto
- Registro da quantidade em estoque
- Registro do preço unitário
- Aceita valores com vírgula ou ponto no preço
- Cálculo do subtotal de cada produto
- Cálculo do valor total do estoque
- Uso de alocação dinâmica de memória
- Liberação correta da memória utilizada

## Tecnologias utilizadas

- Linguagem C
- Biblioteca `stdio.h`
- Biblioteca `stdlib.h`
- Biblioteca `string.h`

## Estrutura do projeto

```text
contador-estoque-c/
│
├── README.md
├── .gitignore
├── src/
│   └── main.c
│
└── build/