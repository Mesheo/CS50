#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("Digite o seu nome: ");
    printf("Hello, %s\n", answer);
}
