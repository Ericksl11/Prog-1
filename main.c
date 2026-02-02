#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// linha vazia
void linha(){
    printf("\n");
}


/*Supondo que todo carro tem um modelo, marca, ano, cor e preço. Faça um programa
que leia as informações de 10 carros que uma concessionária possui para revenda e
imprima na tela o modelo, marca, cor e o ano dos carros que possuem preço abaixo de
R$ 80.000,00. Faça funções específicas a para leitura e impressão dos dados.*/


struct carros
{
    float ano_preco;
    char marc_model_cor[30];
};

struct carros mat[3][5];

void leitura_carros(struct carros mat[3][5]){
    for (int i = 0; i < 3; i++)
    {
        // Marca, mode, cor
        printf("Digite marca, modelo e cor do carro %d:\n", i+1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%s", &mat[i][j].marc_model_cor);
        }
        // Ano e preço
        printf("Digite o ano e preço do carro %d:\n", i+1);
        for (int k = 0; k < 2; k++)
        {
            scanf("%f", &mat[i][k].ano_preco);
        }
    }
    
}

void impress_carros(struct carros mat[3][5]){
    for (int i = 0; i < 3; i++)
    {
        linha();
        // Modelo
        printf("Marca do carro %d: %s\n", i+1, mat[i][0].marc_model_cor);
        // Marca
        printf("Modelo do carro %d: %s\n",i+1, mat[i][1].marc_model_cor);
        // Cor
        printf("Cor do carro %d: %s\n",i+1, mat[i][2].marc_model_cor);
        // Ano 
        printf("Ano do carro %d: %.0f\n",i+1 , mat[i][0].ano_preco);
        // Preço
        printf("Preço do carro %d: R$%.3f\n", i+1, mat[i][1].ano_preco);
        linha();
    }
    
}

int menu(int a){
    printf("MENU DE OPÇÕES");
    linha();
    printf("1- Se desejar filtrar o valor dos carros.");
    linha();
    printf("2- Se desejar escolher um carro.");
    linha();
    printf("3- Não deseja nenhuma das opções.");
    linha();
    scanf("%d", &a);
    return a;
}

float escolhas_menu(a, leitura_carros){
    float filter;
    float choice;
    switch (a)
    {
    case 1:
        printf("Qual o valor desejado para filtrar os carros?");
        scanf("%f", &filter);
        linha();
        return filter;
        break;
    case 2:
        printf("Qual o carro desejado?");
        printf("1- Carro %d: %s\n", mat[0][1].marc_model_cor);
        printf("2- Carro %d: %s\n", mat[1][1].marc_model_cor);
        printf("3- Carro %d: %s\n", mat[2][1].marc_model_cor);
        scanf("%f", &choice);
        linha();
        return choice;
        break;
    case 3:
        system("exit");
        break;
    
    default:
        break;
    }
}

void filtrar_carros(escolhas_menu, leitura_carros){
    
    for (int i = 0; i < 3; i++)
    {
        if (mat[i][1].ano_preco <= escolhas_menu)
        {
            printf("Carro %d: %s\n", i+1, mat[i][0].marc_model_cor);
            printf("Preço: R$%.3f\n", mat[i][1].ano_preco);
            linha();
        }
        
    }
    

    
    
}

void main (){

    system("cls");
    setlocale(LC_ALL, "Portuguese");
    
    struct carros {
        float ano_preco;
        char model_marc_cor[30]; 
    };

    struct carros matriz[3][5];

    int a;

    leitura_carros(matriz);
    
    impress_carros(matriz);

    int menu_choice = menu(a);

    // Consertar essa parte
    escolhas_menu(menu_choice, leitura_carros, matriz);
    
    printf("%.0f", escolhas_menu);

    linha();
}