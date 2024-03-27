#include <stdio.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int stock;
    float price;
};

void displayMenu(struct Item items[], int size);
void processOrder(struct Item items[], int size);

int main() {
    struct Item items[MAX_ITEMS] = {
        {1, "Bananas (per dozen)", 10, 54},
        {2, "Coca-Cola (1 L)", 15, 90},
        {3, "Eggs (per dozen)", 20, 130}
    };

    int numItems = 3;

    displayMenu(items, numItems);
    processOrder(items, numItems);

    return 0;
}

void displayMenu(struct Item items[], int size) {
    printf("Available Items:\n");
    printf("ID\tName\t\t\t\tStock\tPrice\n");
    for (int i = 0; i < size; ++i) {
        printf("%d\t%-25s\t%d\t%.2f\n", items[i].id, items[i].name, items[i].stock, items[i].price);
    }
}

void processOrder(struct Item items[], int size) {
    int itemId, quantity;
    float total = 0.0;

    printf("\nEnter item ID and quantity (0 to finish):\n");
    while (1) {
        printf("Item ID: ");
        scanf("%d", &itemId);
        if (itemId == 0)
            break;

        printf("Quantity: ");
        scanf("%d", &quantity);

        int found = 0;
        for (int i = 0; i < size; ++i) {
            if (items[i].id == itemId) {
                found = 1;
                if (items[i].stock >= quantity) {
                    total += items[i].price * quantity;
                    items[i].stock -= quantity;
                } else {
                    printf("Insufficient stock for %s.\n", items[i].name);
                }
                break;
            }
        }
        if (!found)
            printf("Item with ID %d not found.\n", itemId);
    }

    float discount = 0.1 * total;
    total -= discount;

    printf("\nTotal (after 10%% discount): Rs.%.1f \n", total);
}
