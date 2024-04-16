#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 15

struct Item {
    int id;
    char *name;
    int stock;
    float price;
};

int main() {
    struct Item items[MAX_ITEMS] = {
        {1, strdup("Bananas (per dozen)"), 10, 54.0f},
        {2, strdup("Coca-Cola (1 L)"), 15, 90.0f},
        {3, strdup("Eggs (per dozen)"), 20, 130.0f},
        {4, strdup("Bread (per loaf)"), 25, 40.0f},
        {5, strdup("Water (1 L bottle)"), 30, 20.0f},
        {6, strdup("Milk (1 L)"), 22, 45.0f},
        {7, strdup("Butter (500 g)"), 15, 160.0f},
        {8, strdup("Cheese (500 g)"), 20, 200.0f},
        {9, strdup("Apples (per kg)"), 30, 120.0f},
        {10, strdup("Oranges (per dozen)"), 20, 80.0f},
        {11, strdup("Chicken (per kg)"), 15, 220.0f},
        {12, strdup("Mutton (per kg)"), 10, 300.0f},
        {13, strdup("Fish (per kg)"), 25, 250.0f},
        {14, strdup("Chocolate (100 g)"), 50, 60.0f},
        {15, strdup("Pasta (500 g)"), 35, 75.0f}
    };
    int numItems = 15;

    printf("Stock Information:\n");
    printf("ID\tName\t\t\t\tStock\tPrice\n");
    for (int i = 0; i < numItems; ++i) {
        printf("%d\t%-25s\t%d\t%.2f\n", items[i].id, items[i].name, items[i].stock, items[i].price);
    }

    for (int i = 0; i < numItems; ++i) {
        free(items[i].name);
    }

    return 0;
}
