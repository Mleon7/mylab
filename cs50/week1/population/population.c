#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("start_size: ");
    } while (start_size <= 8);
    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("end_size: ");
    } while (end_size <= start_size - 1);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int total = start_size;
    while (total < end_size)
    {
        total = total + (total / 3) - (total / 4);
        years += 1;
    }

    // TODO: Print number of years
    printf("Years: %d\n", years);
}
