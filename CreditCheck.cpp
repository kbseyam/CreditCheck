#include <iostream>
using namespace std;

string checkCard(long long cardNumber);

int main() {
    long long cardNum;
    cout << "Card number: ";
    cin >> cardNum;
    cout << checkCard(cardNum);
    return 0;
}

string checkCard(long long cardNumber) {        // long long == __int64
    long long tempNumCi = cardNumber;
    long long tempCardNum = cardNumber;         // Visa OR Mastercard OR AMEX
    long long tempNumAlg = cardNumber;
    int count = 0;                              // The number of card numbers
    int sum = 0;
    int companyId;
    string companyName;

    // Get number of card numbers
    while (tempCardNum > 0) {
        tempCardNum /= 10;
        count++;
    }

    // Get the first two digits of the card number
    while (tempNumCi > 100) {
        tempNumCi /= 10;
    }
    companyId = tempNumCi;

    // Find out the name of the company from the first two digits of the card number
    if (companyId > 50 && companyId < 56 && count == 16) {
        companyName = "MASTERCARD";
    } else if ((companyId == 34 || companyId == 37) && count == 15) {
        companyName = "AMEX";                    // AMEX == American Express
    } else if ((companyId / 10 == 4) && (count == 13 || count == 16)) {
        companyName = "VISA";
    } else {
        return "INVALID";
    }

    // Find out if the card is valid or not
    for (int i = 1; i <= count; i++) {
        long digit = tempNumAlg % 10;
        if (i % 2 == 0) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        tempNumAlg /= 10;
    }

    if (sum % 10 == 0) {
        return companyName;
    } else {
        return "INVALID";
    }

}
