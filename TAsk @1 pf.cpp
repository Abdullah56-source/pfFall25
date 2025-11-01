#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100


oid addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Inventory full! Cannot add more books.\n");
        return;
    }

    int isbn;
    printf("Enter ISBN: ");
    scanf("%d", &isbn);

    
    for (int i = 0; i < *count; i++) {
        if (isbns[i] == isbn) {
            printf("Book with this ISBN already exists!\n");
            return;
        }
    }

    isbns[*count] = isbn;
    printf("Enter Title: ");
    scanf(" %[^\n]", titles[*count]);  
    printf("Enter Price: ");
    scanf("%f", &prices[*count]);
    printf("Enter Quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++;
    printf("? Book added successfully!\n");
}


void processSale(int isbns[], int quantities[], int count) {
    int isbn, qty, found = 0;

    if (count == 0) {
        printf("No books in inventory!\n");
        return;
    }

    printf("Enter ISBN to sell: ");
    scanf("%d", &isbn);

    for (int i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &qty);

            if (qty > quantities[i]) {
                printf("? Not enough stock! Only %d available.\n", quantities[i]);
            } else {
                quantities[i] -= qty;
                printf("? Sale processed. Remaining stock: %d\n", quantities[i]);
            }
            break;
        }
    }

    if (!found)
        printf("ISBN not found");
}


void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int found = 0;
    printf("\n========== LOW-STOCK REPORT (Qty < 5) ==========\n");
    printf("%-10s %-30s %-10s %-10s\n", "ISBN", "Title", "Price", "Qty");

    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("%-10d %-30s %-10.2f %-10d\n", isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found)
        printf("sufficient stock!\n");
}


int main() {
    int isbns[MAX_BOOKS];
    char titles[MAX_BOOKS][50];
    float prices[MAX_BOOKS];
    int quantities[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\n========== LIBERTY BOOKS INVENTORY ==========\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting system... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}





