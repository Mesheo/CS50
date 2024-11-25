#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height;

    // validando as entradas
    do{
        height = get_int("Digite a altura: ");
    }
    while (height<1);


    int spaces = height-1;
    int hashtags = 1;

    for(int row=0;row<height;row++){
        // printando os espacos
        for(int j =0 ; j<spaces; j++  ){
            printf(" ");
        }

        // printando as hashtags
        for(int i =0; i < hashtags; i++   ){
            printf("#");

        }

        // atualizando as variaveis
        spaces--;
        hashtags++;
        printf("\n");

    }
}
