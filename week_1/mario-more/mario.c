#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height;

    // validando as entradas
    do{
        height = get_int("Digite a altura: ");
    }
    while (height<1);

    int spaces_left = height-1;
    int hashtags_left = 1;

    int spaces_right = height-1;
    int hashtags_right = 1;

    for(int row=0;row<height;row++){
        // LEFT SIDE
        // printando os espacos da esquerda
        for(int j =0 ; j < spaces_left; j++  ){
            printf(" ");
        }
        // printando as hashtags da esquerda
        for(int i =0; i < hashtags_left; i++   ){
            printf("#");

        }
        printf("  ");

        // RIGHT SIDE
        // printando as hashtags da direita
        for(int i =0; i < hashtags_right; i++   ){
            printf("#");

        }
        // // printando os espacos da direita
        // for(int j =0 ; j < spaces_right; j++  ){
        //     printf(" ");
        // }


        // atualizando as variaveis
        spaces_left--;
        hashtags_left++;
        spaces_right--;
        hashtags_right++;
        
        printf("\n");

    }
}
