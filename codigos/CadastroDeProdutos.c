#include <stdio.h>
#include <stdlib.h>

struct CadastroDeProdutos
{
    char nome[50];
    float preco;
    int QtdEstoque;

};


int main()
{
    int QtdProduto, i;

    printf("\nEntre com a quantidade de produto: ");
    scanf("%d", &QtdProduto);

   struct CadastroDeProdutos *produto = malloc(QtdProduto * sizeof(int));

    if(produto == NULL)
    {
        printf("ERRO AO ALOCAR MEMORIA!\n");
        return 1;
    }

    for ( i = 0; i < QtdProduto; i++)
    {
        printf("Entre com o nome do produto[%d]: ", i + 1);
        scanf(" %[^\n]", produto[i].nome);

        printf("Digite o preco do produto[%d]: ", i + 1);
        scanf("%f", &produto[i].preco);

        printf("Digite a quantidade em estoque[%d]: ", i + 1);
        scanf("%d", &produto[i].QtdEstoque);

    }

    printf("\n  Lista de produtos cadastrados");
    
    for ( i = 0; i < QtdProduto; i++)
    {
        printf("\n%d - Nome:  %s | Preco: %0.2f | QtdEstoque: %d  ", i + 1 , produto[i].nome, produto[i].preco, produto[i].QtdEstoque);
    }
    
    free(produto);
    
}  

