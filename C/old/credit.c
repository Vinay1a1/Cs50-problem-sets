#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number= get_long("Number: ");
    long original = number;
    int sum = 0;
    int type= 0;
    long temp= number;
    long digit = 0;
    while (temp >= 100)
    {
        temp /= 10;
    }
// digit is 1st digit, temp is first 2
    digit = temp /10;


    int position = 0;
    while (number > 0)
    {
        int last_digit = number % 10;

        if (position % 2 == 1)
        {
            int product = last_digit * 2;
            sum += (product /10) + (product %10);
        }
        else
        {
            sum += last_digit;
        }

        number /= 10;
        position++;
    }
    for (; original >= 1; original/=10)
    {
        type++;
    }
 if (sum % 10 == 0)
    {

    if ((digit == 4) && (type == 13 || type == 16))
    {
        printf("VISA\n");
    }
    else if ((temp >= 51 && temp <= 55) && type == 16)
    {
        printf("MASTERCARD\n");
    }

    else if ((temp == 31 || temp == 37) && type == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
else{
    printf("INVALID\n");}

}

