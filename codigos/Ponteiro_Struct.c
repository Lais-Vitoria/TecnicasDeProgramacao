#include <stdio.h>
#include <string.h>

struct Livro{
    char titulo[20];
    int ano_publicacao;

};

void Fadicionar_livro(struct Livro *Livro1){
    
    strcpy(Livro1->titulo, "Lumem");
    Livro1->ano_publicacao = 2021;

}

int main()
{
    struct Livro L1;

    Fadicionar_livro(&L1);

    printf("\nO Livro %s foi publicado em %d.", L1.titulo, L1.ano_publicacao);

    return 0;
}