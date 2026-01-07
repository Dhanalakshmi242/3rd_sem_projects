#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
    struct Product *next;
};

struct Product *head = NULL;

void addProduct() {
    struct Product *newNode = (struct Product*)malloc(sizeof(struct Product));

    printf("Enter Product ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Product Name: ");
    scanf("%s", newNode->name);

    printf("Enter Quantity: ");
    scanf("%d", &newNode->quantity);

    printf("Enter Price: ");
    scanf("%f", &newNode->price);

    newNode->next = head;
    head = newNode;

    printf("Product Added Successfully\n");
}

void displayProducts() {
    struct Product *temp = head;
    if (temp == NULL) {
        printf("Inventory Empty\n");
        return;
    }

    while (temp != NULL) {
        printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n\n",
               temp->id, temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

void searchProduct() {
    int id;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    struct Product *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Product Found\n");
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\n",
                   temp->name, temp->quantity, temp->price);
            return;
        }
        temp = temp->next;
    }
    printf("Product Not Found\n");
}

void updateQuantity() {
    int id, qty;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    struct Product *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter New Quantity: ");
            scanf("%d", &qty);
            temp->quantity = qty;
            printf("Quantity Updated\n");
            return;
        }
        temp = temp->next;
    }
    printf("Product Not Found\n");
}

void deleteProduct() {
    int id;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    struct Product *temp = head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product Not Found\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Product Deleted\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Add Product\n2.Display Products\n3.Search Product\n4.Update Quantity\n5.Delete Product\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateQuantity(); break;
            case 5: deleteProduct(); break;
            case 6: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
