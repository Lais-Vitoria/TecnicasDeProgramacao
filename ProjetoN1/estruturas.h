

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// subestrutura de aluno
typedef struct {
    char cidade[50];
    char estado[10];
} Endereco; 

// estrutura aluno
typedef struct {
    int matricula;
    char nome[100];
    float n1, n2;
    Endereco endereco;
} Aluno;

#endif
