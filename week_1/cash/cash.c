#include <stdio.h>
#include <cs50.h>

int calculating_quarters(int change){
        return change / 25;
    }
int calculating_dimes(int change){
        return change / 10;
    }
int calculating_nickels(int change){
        return change / 5;
    }

int main(void){
    int change;
    do{
        change = get_int("Quantidade de troco: ");
    } while (change <= 0);

    int quarters_quantity = calculating_quarters(change);
    change = change - (25 * quarters_quantity);

    int dimes_quantity = calculating_dimes(change);
    change = change - (10 * dimes_quantity);

    int nickels_quantity = calculating_nickels(change);
    change = change - (5 * nickels_quantity);

    int pennies_quantity = change;

    int total_coins = quarters_quantity + dimes_quantity + nickels_quantity + pennies_quantity;
    printf("%i \n", total_coins);
}
