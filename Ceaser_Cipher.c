#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], int shift);
void decrypt(char text[], int shift);

int main()
{
    //Here we can enter total of 399 character long message.
    char text[400];
    int shift;

    printf("Enter the message: ");
    // fgets reads the entire message even with spaces but scanf stops at spaces.
    fgets(text, sizeof(text), stdin);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    // To encrypt the text it will automatically modifies the text as per the given function criteria.
    encrypt(text, shift);
    printf("\nEncrypted: %s\n", text);

    // To decrypt the text it will automatically modifies the text as per the given function criteria.
    decrypt(text, shift);
    printf("Decrypted: %s\n", text);
    return 0;
}

void encrypt(char text[], int shift)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (isupper(c))
        {
            /* c will be changed to it's ascii value and 'A' has value of 65 now after subtraction of ascii values we will add shift and modulus of it by 26 to get the possition and at the end adding the ascii value of 'A' i.e, 65 to get the ascii value of that uppercase shifted letter. */

            text[i] = ((c - 'A' + shift) % 26) + 'A';
        }
        else if (islower(c))
        {
            text[i] = ((c - 'a' + shift) % 26) + 'a';
        }
    }
}

void decrypt(char text[], int shift)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        /* Why + 26?? because if if we subtract shift the number obtained might be negative hence we add 26 and then get a modulus and then we can get the shifted letter after adding ascii value of 'a' or 'A'. */
        char c = text[i];
        if (isupper(c))
        {
            text[i] = ((c - 'A' - shift + 26) % 26) + 'A';
        }
        else if (islower(c))
        {
            text[i] = ((c - 'a' - shift + 26) % 26) + 'a';
        }
    }
}