#include <stdio.h>
#include <string.h>

#define SIZE 4


int Product_Code[SIZE] = {1, 2, 3, 4};
int Quantity_In_Stock[SIZE] = {50, 10, 20, 8};
int Price_Per_Product[SIZE] = {100, 200, 300, 150};


char name[30];
long int cnic;
int totalBill = 0;


void customerInfo() {
    printf("\nEnter Customer Name: ");
    scanf("%s", name);
    printf("Enter CNIC (without dashes): ");
    scanf("%ld", &cnic);
}


void displayInventory() {
    printf("\n--- INVENTORY ---\n");
    printf("Code\tStock\tPrice\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%03d\t%d\t%d\n", Product_Code[i], Quantity_In_Stock[i], Price_Per_Product[i]);
    }
}


void updateInventory(int code, int qty) {
    for (int i = 0; i < SIZE; i++) {
        if (Product_Code[i] == code) {
            if (Quantity_In_Stock[i] >= qty) {
                Quantity_In_Stock[i] -= qty;
                printf("Inventory updated. Remaining stock: %d\n", Quantity_In_Stock[i]);
            } else {
                printf("Not enough stock available!\n");
            }
        }
    }
}


void addToCart() {
    int code, qty;
    displayInventory();
    printf("\nEnter product code to buy: ");
    scanf("%d", &code);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    for (int i = 0; i < SIZE; i++) {
        if (Product_Code[i] == code) {
            if (Quantity_In_Stock[i] >= qty) {
                int amount = qty * Price_Per_Product[i];
                totalBill += amount;
                printf("Added to cart! Amount: %d\n", amount);
                updateInventory(code, qty);
            } else {
                printf("Not enough stock!\n");
            }
            return;
        }
    }
    printf("Invalid product code!\n");
}

void displayBill() {
    char promo[20];
    float discount = 0, finalBill = totalBill;

    printf("\nTotal Bill (without discount): %d\n", totalBill);
    printf("Enter promo code if any: ");
    scanf("%s", promo);

    if (strcmp(promo, "Eid2025") == 0) {
        discount = totalBill * 0.25;
        finalBill = totalBill - discount;
        printf("Promo applied! 25%% discount.\n");
    } else {
        printf("Invalid or no promo code.\n");
    }

    printf("Final Bill: %.2f\n", finalBill);
}


void showInvoice() {
    printf("\n--- INVOICE ---\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %ld\n", cnic);
    printf("Total Bill: %d\n", totalBill);
    printf("-----------------\nThank you for shopping!\n");
}


int main() {
    int choice;
    customerInfo();

    do {
        printf("\n--- SUPERMARKET MENU ---\n");
        printf("1. Display Inventory\n");
        printf("2. Add Item to Cart\n");
        printf("3. Display Total Bill\n");
        printf("4. Show Invoice\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayInventory();
                break;
            case 2:
                addToCart();
                break;
            case 3:
                displayBill();
                break;
            case 4:
                showInvoice();
                break;
            case 5:
                printf("Exiting system... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
