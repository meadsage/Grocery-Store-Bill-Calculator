#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 3

struct Customer {
    int id;
    char name[50];
    char contactNumber[15];
};

int main() {
    struct Customer customers[MAX_CUSTOMERS];

    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        printf("Enter details for Customer %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &customers[i].id);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Contact Number: ");
        scanf("%s", customers[i].contactNumber);
        printf("\n");
    }

    printf("Customer Details:\n");
    printf("ID\tName\tContact Number\n");
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        printf("%d\t%s\t%s\n", customers[i].id, customers[i].name, customers[i].contactNumber);
    }

    return 0;
}
