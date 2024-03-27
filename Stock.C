#include <stdio.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int stock;
    float price;
};

int main() {
    struct Item items[MAX_ITEMS] = {
        {1, "Bananas (per dozen)", 10, 54},
        {2, "Coca-Cola (1 L)", 15, 90},
        {3, "Eggs (per dozen)", 20, 130}
    };

    int numItems = 3;

    return 0;
}
