#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int countVowels(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o' ||
            ch == 'A' || ch == 'I' || ch == 'U' || ch == 'E' || ch == 'O')
        {
            count++;
        }
    }
    return count;
}

int countConsonants(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            if (ch != 'a' && ch != 'i' && ch != 'u' && ch != 'e' && ch != 'o' &&
                ch != 'A' && ch != 'I' && ch != 'U' && ch != 'E' && ch != 'O')
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    char letter;
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i, numMonths;
    printf("============================\n");
    printf("Program pencarian nama bulan\n");
    printf("============================\n");

    printf("Masukkan huruf (A-Z): ");
    scanf(" %c", &letter);

    if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z') && getchar() == '\n')
    {
        bool found = false;
        printf("Bulan-bulan yang awalannya adalah '%c':\n", letter);

        for (i = 0; i < 12; i++)
        {
            if (months[i][0] == letter || months[i][0] == letter + 32 || months[i][0] == letter - 32)
            {
                printf("%s\n", months[i]);
                found = true;
            }
        }

        if (!found)
        {
            printf("Tidak ada bulan yang berawalan dengan huruf %c.\n", letter);
        }
        else
        {
            printf("Pilih bulan dari daftar di atas: ");
            scanf("%d", &numMonths);

            if (numMonths >= 1 && numMonths <= 12)
            {
                char selectedLetter = letter;
                char *selectedMonth = NULL;

                // mengecek pilihan bulan
                for (i = 0; i < 12; i++)
                {
                    if (months[i][0] == selectedLetter || months[i][0] == selectedLetter + 32 || months[i][0] == selectedLetter - 32)
                    {
                        if (numMonths == 1)
                        {
                            selectedMonth = months[i];
                            break;
                        }
                        numMonths--;
                    }
                }

                if (selectedMonth != NULL)
                {
                    int vowels = countVowels(selectedMonth);
                    int consonants = countConsonants(selectedMonth);
                    printf("Jumlah huruf vokal di '%s': %d\n", selectedMonth, vowels);
                    printf("Jumlah huruf non-vokal di '%s': %d\n", selectedMonth, consonants);
                }
                else
                {
                    printf("Tidak ada bulan yang sesuai dengan pilihan Anda.\n");
                }
            }
            else
            {
                printf("Pilihan bulan tidak valid.\n");
            }
        }
    }
    else
    {
        printf("Input tidak valid. Harap masukkan huruf (A-Z).\n");
    }

    return 0;
}
