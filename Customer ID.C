#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 3

struct Customer {
    int id;
    char *name;
    char contactNumber[15];
};

int findCustomerById(struct Customer customers[], int count, int id);
int findCustomerByName(struct Customer customers[], int count, const char *name);

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    char buffer[50];
    int idUsed, nameUsed;

    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        customers[i].name = NULL;

        printf("Enter details for Customer %d:\n", i + 1);

        do {
            printf("ID: ");
            scanf("%d", &customers[i].id);
            idUsed = findCustomerById(customers, i, customers[i].id);
            if (idUsed) {
                printf("Error: This ID is already in use. Please enter a different ID.\n");
            }
        } while (idUsed);

        do {
            printf("Name: ");
            scanf("%s", buffer);
            nameUsed = findCustomerByName(customers, i, buffer);
            if (nameUsed) {
                printf("Error: This name is already in use. Please enter a different name.\n");
            }
        } while (nameUsed);

        customers[i].name = (char *)malloc(strlen(buffer) + 1);
        strcpy(customers[i].name, buffer);

        printf("Contact Number: ");
        scanf("%s", customers[i].contactNumber);
        printf("\n");
    }

    printf("Customer Details:\n");
    printf("ID\tName\t\tContact Number\n");
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        printf("%d\t%s\t\t%s\n", customers[i].id, customers[i].name, customers[i].contactNumber);
    }

    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        free(customers[i].name);
    }

    return 0;
}

int findCustomerById(struct Customer customers[], int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (customers[i].id == id) {
            return 1;
        }
    }
    return 0;
}

int findCustomerByName(struct Customer customers[], int count, const char *name) {
    for (int i = 0; i < count; ++i) {
        if (customers[i].name != NULL && strcmp(customers[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}
