
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt or decrypt a message
void processMessage(char message[], int shift, int choice) {

    for (int i = 0; message[i] != '\0'; i++) {

        char ch = message[i];

        if (isupper(ch)) {

            if (choice == 1)
                message[i] = (ch - 'A' + shift) % 26 + 'A';
            else
                message[i] = (ch - 'A' - shift + 26) % 26 + 'A';

        }
        else if (islower(ch)) {

            if (choice == 1)
                message[i] = (ch - 'a' + shift) % 26 + 'a';
            else
                message[i] = (ch - 'a' - shift + 26) % 26 + 'a';

        }
    }
}

int main() {

    char message[200];
    int choice, shift;

    printf("=================================\n");
    printf("   TEXT ENCRYPTION TOOL\n");
    printf("=================================\n");

    while (1) {

        printf("\n1. Encrypt Message\n");
        printf("2. Decrypt Message\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        if (choice == 3) {
            printf("Thank you for using the tool!\n");
            break;
        }

        if (choice != 1 && choice != 2) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        printf("Enter your message: ");
        scanf(" %199[^\n]", message);

        printf("Enter shift value (0-25): ");
        if (scanf("%d", &shift) != 1) {
            printf("Invalid shift value!\n");
            return 1;
        }

        if (shift < 0 || shift > 25) {
            printf("Shift must be between 0 and 25!\n");
            continue;
        }

        processMessage(message, shift, choice);

        if (choice == 1)
            printf("\nEncrypted Message: %s\n", message);
        else
            printf("\nDecrypted Message: %s\n", message);
    }

    return 0;
}
