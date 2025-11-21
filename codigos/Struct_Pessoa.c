#include <stdio.h>

struct Endereco
{
    char rua[30];
    int numero;
};

struct Pessoa
{
    char nome[20];
    int idade;
    struct Endereco endereco;
};

int main()
{
    struct Pessoa p1;

    printf("\nEntre com o nome: ");
    scanf("%s", p1.nome);

    printf("Entre com a idade: ");
    scanf("%d", &p1.idade);

    printf("Digite o nome da rua: ");
    scanf("%s", p1.endereco.rua);

    printf("Digite o numero da casa: ");
    scanf("%d", &p1.endereco.numero);

    printf("\nNome: %s \nIdade: %d \nEndereco: %s, Numero: %d", p1.nome, p1.idade, p1.endereco.rua, p1.endereco.numero);
}