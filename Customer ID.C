#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 15
#define MAX_PASSWORD_LENGTH 20
#define FILE_NAME "customers.txt"

struct Customer {
    int id;
    char name[MAX_NAME_LENGTH];
    char contactNumber[MAX_CONTACT_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void writeCustomersToFile(struct Customer customers[], int count);
int readCustomersFromFile(struct Customer customers[], int maxCount);
int findCustomerById(struct Customer customers[], int count, int id);
int findCustomerByName(struct Customer customers[], int count, const char *name);
int authenticateCustomer(struct Customer customers[], int count, int id, const char *password);
void registerNewCustomer(struct Customer customers[], int *customerCount);

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    int customerCount = 0;
    int choice;

    customerCount = readCustomersFromFile(customers, MAX_CUSTOMERS);

    printf("Welcome! Please choose an option:\n");
    printf("1. Existing Customer\n");
    printf("2. New Customer\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int id;
        char password[MAX_PASSWORD_LENGTH];

        printf("Enter your Customer ID: ");
        scanf("%d", &id);
        printf("Enter your Password: ");
        scanf("%s", password);

        if (authenticateCustomer(customers, customerCount, id, password)) {
            printf("Login successful! Welcome back!\n");
        } else {
            printf("Invalid ID or Password. Please try again.\n");
        }
    } else if (choice == 2) {
        registerNewCustomer(customers, &customerCount);
        writeCustomersToFile(customers, customerCount);
    } else {
        printf("Invalid choice. Please restart the program.\n");
    }

    return 0;
}

void writeCustomersToFile(struct Customer customers[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%d %s %s %s\n", customers[i].id, customers[i].name, customers[i].contactNumber, customers[i].password);
    }
    fclose(file);
}

int readCustomersFromFile(struct Customer customers[], int maxCount) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return 0;
    }
    int count = 0;
    while (fscanf(file, "%d %s %s %s", &customers[count].id, customers[count].name, customers[count].contactNumber, customers[count].password) == 4 && count < maxCount) {
        count++;
    }
    fclose(file);
    return count;
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
        if (strcmp(customers[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

int authenticateCustomer(struct Customer customers[], int count, int id, const char *password) {
    for (int i = 0; i < count; ++i) {
        if (customers[i].id == id && strcmp(customers[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void registerNewCustomer(struct Customer customers[], int *customerCount) {
    struct Customer newCustomer;
    int idUsed, nameUsed;

    printf("Enter details for the new customer:\n");

    do {
        printf("ID: ");
        scanf("%d", &newCustomer.id);
        idUsed = findCustomerById(customers, *customerCount, newCustomer.id);
        if (idUsed) {
            printf("Error: This ID is already in use. Please enter a different ID.\n");
        }
    } while (idUsed);

    do {
        printf("Name: ");
        scanf("%s", newCustomer.name);
        nameUsed = findCustomerByName(customers, *customerCount, newCustomer.name);
        if (nameUsed) {
            printf("Error: This name is already in use. Please enter a different name.\n");
        }
    } while (nameUsed);

    printf("Contact Number: ");
    scanf("%s", newCustomer.contactNumber);

    printf("Password: ");
    scanf("%s", newCustomer.password);

    customers[*customerCount] = newCustomer;
    (*customerCount)++;
}
