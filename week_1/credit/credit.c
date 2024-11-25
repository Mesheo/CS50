#include <cs50.h>
#include <stdio.h>

bool is_credit_card_valid(long ccn);
bool checksum(long ccn);
char* detect_card_brand(long ccn);
int get_length(long ccn);
int get_first_two_digits(long ccn);

int main(void)
{
    long credit_card_number = get_long_long("Credit card number: ");

    if (is_credit_card_valid(credit_card_number))
    {
        char* card_brand = detect_card_brand(credit_card_number);
        printf("%s", card_brand);
    }
    else
    {
        printf("INVALID\n");
    }
 }






char* detect_card_brand(long ccn)
{
    char* card_brand;
    int first_two_digits = get_first_two_digits(ccn);
    int ccn_length = get_length(ccn);

    if ( (first_two_digits == 34 || first_two_digits == 37) && ccn_length == 15 )
    {
        card_brand = "AMEX\n";
    }

    else if ( (first_two_digits >= 51 && first_two_digits <= 55) && ccn_length == 16)
    {
        card_brand = "MASTERCARD\n";
    }
    else if ( (first_two_digits / 10) == 4 && (ccn_length == 13 || ccn_length == 16))
    {
        card_brand = "VISA\n";
    }
    else
    {
        card_brand = "INVALID\n";
    }

    return card_brand;
}

int get_first_two_digits(long ccn)
{
    while (ccn > 100)
    {
        ccn = ccn / 10;
    }

    return ccn;
}

int get_length(long ccn)
{
    int length = 0;

    while (ccn != 0)
    {
        length += 1;
        ccn = ccn/10;
    }

    return length;
}


bool is_credit_card_valid(long ccn)
{
    bool validity = false;
    int alternate_digits_product_sum = 0;
    int other_digits_sum = 0;

    // 1. percorrendo os numeros de maneira alternada
    bool is_alternate_digit = false;
    while( ccn != 0)
    {
        int digit = ccn % 10;

        // 2. Multiplicando o digito por 2 e somando os digitos do resultado
        if (is_alternate_digit){
            int product = digit * 2;
            int sum_of_product_digits = (product % 10) + (product /10);

            alternate_digits_product_sum += sum_of_product_digits;
        }
        // 2.2 Somando os outros digitos
        else
        {
            other_digits_sum += digit;
        }

        ccn = ccn/10;
        is_alternate_digit = !is_alternate_digit;
    }

    // 3. verificando se a adição das duas somas e um valor terminado em zero
    if ( (alternate_digits_product_sum + other_digits_sum) % 10 == 0 )
    {
        validity = true;
    }

    return validity;
}
