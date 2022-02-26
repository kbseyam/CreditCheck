#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    // Get card number from user
    long card_num = get_long("Card number: ");

    // Declare variable
    long temp_num_ci = card_num;
    long temp_card_num = card_num;
    string company_name;                // Visa OR Mastercard OR AMEX
    long temp_num_alg = card_num;
    int count = 0;                      // The number of card numbers

    // Get the number of card numbers
    while (temp_card_num > 0) {
        temp_card_num = temp_card_num / 10;
        count++;
    }

    // Get the first two digits of the card number
    while (temp_num_ci > 100) {
        temp_num_ci = temp_num_ci / 10;
    }
    int company_id = temp_num_ci;


    // Find out the name of the company from the first two digits of the card number
    if (company_id > 50 && company_id < 56 && count == 16) {
        company_name = "MASTERCARD";
    } else if ((company_id == 34 || company_id == 37) && (count == 15)) {
        company_name = "AMEX";      // AMEX == American Express
    } else if ((company_id / 10 == 4) && (count == 13 || count == 16)) {
        company_name = "VISA";
    } else {
        company_name = "INVALID";
    }


    // Find out if the card is valid or not

    int sum = 0;

    temp_num_alg = card_num;

    for (int i = 1; i <= count; i++) {
        int digit = temp_num_alg % 10;

        if (i % 2 == 0) {
            digit *= 2;

            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;

        temp_num_alg /= 10;
    }

    // Print company name OR INVALID
    if (sum % 10 == 0) {
        printf("%s\n", company_name);
    }
    else {
        printf("INVALID\n");
    }

}
