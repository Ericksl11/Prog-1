#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

// linha vazia
void linha(){
    printf("\n");
}

// QUESTAO A)
struct curso
{
    int codigo;
    char curso[30];  
};

struct endereco
{
    char cidade[30];
    char rua[30];
    int num;
    int cep;
};

struct aluno
{
    int matricula;
    char nome[30];
    struct curso curso;
    struct endereco endereco;
};

// QUESTAO B)
int print_menu(int menu){

    printf("MENU");
    linha();
    printf("1- Cadastrar novo aluno");
    linha();
    printf("2- Imprimir alunos cadastrados");
    linha();
    printf("3- Pesquisar aluno pela matricula");
    linha();
    printf("4- Contar alunos por curso");
    linha();
    printf("5- Salvar em arquivo");
    linha();
    printf("0- Sair");
    linha();
    scanf("%d", &menu);
    fflush(stdin);
    return menu;
}

// QUESTAO C)
void cadastro_aluno(struct aluno aluno[], int quant){
    quant;
    for (int i = 0 + quant; i < quant + 1; i++)
    {
        linha();
        printf("Digite o nome do aluno: ");
        fgets(aluno[i].nome, 30, stdin);
        
        printf("Digite a cidade do aluno: ");
        fgets(aluno[i].endereco.cidade, 30, stdin);
        
        printf("Digite a rua: ");
        fgets(aluno[i].endereco.rua, 30, stdin);
        
        printf("Digite o numero <Se nao houver = 0> : ");
        scanf("%d", &aluno[i].endereco.num);
        fflush(stdin);
        
        printf("Digite o cep: ");
        scanf("%d", &aluno[i].endereco.cep);
        fflush(stdin);
        
        printf("Digite a matricula do aluno: ");
        scanf("%d", &aluno[i].matricula);
        fflush(stdin);
        
        printf("Digite o código do curso: ");
        scanf("%d", &aluno[i].curso.codigo);
        fflush(stdin);
        
        printf("Digite o nome do curso: ");
        fgets(aluno[i].curso.curso, 30, stdin);
        
        linha();
    }
    
}

// QUESTAO D)
void printf_aluno_curso(struct aluno aluno[], int quant){
    quant;
    for (int i = 0; i < quant; i++)
    {
        linha();
        printf("Aluno: %s", aluno[i].nome);
        printf("Curso: %s", aluno[i].curso.curso);
        linha();
    }
    
}  

// QUESTAO E)
void find_aluno(struct aluno aluno[], int a, int quant){
    
    quant;

    printf("Digite a matricula do aluno que deseja encontrar: ");
    scanf("%d", &a);
    fflush(stdin);

    for (int i = 0; i < quant; i++)
    {
        if (aluno[i].matricula == a)
        {
            printf("Aluno encontrado: %s", aluno[i].nome);
            linha();
        }
        
    }
    
}

// QUESTAO F) consertar
void cont_alunos(struct aluno aluno[],char curso_escolhido[], int quant, int cont){
    
    cont=0;

    printf("De qual curso deseja saber a quantidade de alunos? ");
    fgets(curso_escolhido, 30, stdin);

    for (int i = 0 + quant; i < quant + 1; i++)
    {
        if (strcmp(aluno[i].curso.curso, curso_escolhido) == 0)
        {
            cont ++;
            
        }
    }
    printf("Quantidade de alunos no curso %s: %d", curso_escolhido, cont);
    linha();
}

void print_cadastro (struct aluno aluno[]){
    // Exibindo os dados cadastrados
    for (int i = 0; i < 2; i++){
        printf("Aluno: %s", aluno[i].nome);
        printf("Cidade do aluno: %s", aluno[i].endereco.cidade);
        printf("Rua: %s", aluno[i].endereco.rua);
        printf("Numero: %d", aluno[i].endereco.num);
        linha();
        printf("Cep: %d", aluno[i].endereco.cep);
        linha();
        printf("Matricula: %d", aluno[i].matricula);
        linha();
        printf("Codigo do curso: %d", aluno[i].curso.codigo);
        linha();
        printf("Curso: %s", aluno[i].curso.curso);
        linha();
        printf("Aluno cadastrado com sucesso!!");
        linha();
    }
}



void main (){

    struct aluno aluno[4];
    int matricula;
    int menu;
    int quant = 0;
    int cont=0;
    char curso_escolhido[30];

    system("cls");
    setlocale(LC_ALL, "Portuguese");
    
// Menu
while (menu != 0)
{        
    menu = print_menu(menu);
    
    switch (menu)
    {
    case 1:
        cadastro_aluno(aluno, quant);
        quant++;
    break;

    case 2:
        printf_aluno_curso(aluno, quant);
    break;

    case 3:
        find_aluno(aluno, matricula, quant);
    break;

    case 4:
        cont_alunos(aluno, curso_escolhido, quant, cont);   
    break;

    case 5: 
        printf("Adicionar!");
    break;
    
    default:
    break;
    }
    
}

    linha();
}