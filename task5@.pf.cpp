#include <stdio.h>
#include <string.h>


void reverseString(char msg[]) {
    int i, j;
    char temp;
    j = strlen(msg) - 1;  

    for (i = 0; i < j; i++, j--) {
        temp = msg[i];
        msg[i] = msg[j];
        msg[j] = temp;
    }
}
void toggleBits(char msg[]) {
    int i;
    for (i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ (1 << 1);
        msg[i] = msg[i] ^ (1 << 4);  
    }
}


void encodeMessage(char msg[]) {
    reverseString(msg);
    toggleBits(msg);      
    printf("Encoded Message: %s\n", msg);
    getchar();
}


void decodeMessage(char msg[]) {
    toggleBits(msg);     
    reverseString(msg);  
    printf("Decoded Message: %s\n", msg);
}


int main() {
    char msg[200];
    int choice;

    do {
        printf("\n--- TCS Message System ---\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        

        if (choice == 1) {
            printf("Enter message to encode: ");
            gets(msg);   
            encodeMessage(msg);
        }
        else if (choice == 2) {
            printf("Enter message to decode: ");
            gets(msg);
            decodeMessage(msg);
        }
        else if (choice == 3) {
            printf("Exiting program...\n");
        }
        else {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
