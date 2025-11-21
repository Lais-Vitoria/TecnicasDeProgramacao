#include <stdio.h> // diretiva de pre processamento

int main() {// função principal de c

int a = 10; // Declara a variavel do tipo inteiro com o valor 10;
int *p; // declara um ponteiro do tipo inteiro;

p = &a; // armazena o endereço de memoria da varialvel a;

printf("%d\n", a); // imprimi o valor 10 ;
printf("%p\n", (void*)p); // imprimi o endereço de memoria armazenado em p
printf("%d\n", *p); // imprimi o valor apontado por p

*p = 20; // a variavel apontado por p recebe o valor 20;
printf("%d\n", a);// imprimi o valor modificado 20;

return 0;// Indica que o programa encerrou corretamente;
}




