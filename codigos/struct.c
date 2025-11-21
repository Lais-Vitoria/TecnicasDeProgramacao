#include <stdio.h> // diretiva de pre processamento;

struct Pessoa {// define uma estrutura do tipo 'Pessoa';
    char nome[50];// difine o membro da estrutura tipo caracter;
    int idade;// define o membro da estrutura tipo inteiro;
};


int main() // função principal do programa;
{
    struct Pessoa p1 = {"Alice", 25}; // declara a varialvel do tipo pessoa e armazena o nome e a idade na struct;
    struct Pessoa *ptr = &p1;// armazena o enderenço de memoria da strcut;

    printf("%s tem %d anos\n", ptr->nome, ptr->idade); // imprime o nome da variavel 'nome' e a idade;
    ptr->idade = 30; // redefine a idade para 30;
    printf("%s agora tem %d anos\n", p1.nome, p1.idade);// imprime o nome e a nova idade;

    return 0;// indica que o programa encerrou corretamente;
}