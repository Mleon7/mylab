#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void decimalToBinary(int decimal, int binary[]);

int main(void)
{
    // TODO
    string text;

    text = get_string("text: ");

    for (int i = 0; text[i] != '\0'; i++)
    {
        int binary[BITS_IN_BYTE];
        // Decimal-to-Binary
        decimalToBinary(text[i], binary);
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            // printf("%d", binary[j]);
            print_bulb(binary[j]);
        }
        printf("\n");
    }
}

void decimalToBinary(int decimal, int binary[])
{
    if (decimal == 0)
    {
        binary[0] = 0;
        return;
    }

    for (int i = 7; i >= 0; i--)
    {
        if (decimal > 0)
        {
            binary[i] = decimal % 2;
            decimal = decimal / 2;
        }
        else
        {
            binary[i] = 0;
        }
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
