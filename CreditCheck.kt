import java.util.*
import kotlin.properties.Delegates

private lateinit var companyName: String
private var companyId by Delegates.notNull<Int>()

fun main() {
    val scanner = Scanner(System.`in`)

    // Get card number from user
    print("Card number: ")
    val cardNum = scanner.nextLong()

    println(checkCard(cardNum))

}

fun checkCard(cardNumber: Long): String {
    var tempNumCi = cardNumber
    var tempCardNum = cardNumber            // Visa OR Mastercard OR AMEX
    var tempNumAlg = cardNumber
    var count = 0                           // The number of card numbers
    var sum = 0

    // Get the number of card numbers
    while (tempCardNum > 0) {
        tempCardNum /= 10
        count++
    }

    // Get the first two digits of the card number
    while (tempNumCi > 100) {
        tempNumCi /= 10
    }
    companyId = tempNumCi.toInt()

    // Find out the name of the company from the first two digits of the card number
    companyName = if (companyId in 51..55 && count == 16) {
        "MASTERCARD"
    } else if ((companyId == 34 || companyId == 37) && count == 15) {
        "AMEX"                // AMEX == American Express
    } else if (companyId / 10 == 4 && (count == 13 || count == 16)) {
        "VISA"
    } else {
        return ("INVALID")
    }

    // Find out if the card is valid or not
    for (i in 1..count) {
        var digit =tempNumAlg % 10
        if (i % 2 == 0) {
            digit *= 2
            if (digit > 9) {
                digit -= 9
            }
        }

        sum += digit.toInt()
        tempNumAlg /= 10
    }

    return if (sum % 10 == 0) {
        companyName
    } else "INVALID"

}
