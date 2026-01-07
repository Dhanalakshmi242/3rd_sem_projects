import java.util.Scanner;

class Product {
    int id;
    String name;
    int quantity;
    double price;
    Product next;

    Product(int id, String name, int quantity, double price) {
        this.id = id;
        this.name = name;
        this.quantity = quantity;
        this.price = price;
        this.next = null;
    }
}

public class InventoryManagement {

    // ANSI Colors
    static final String RESET = "\u001B[0m";
    static final String BLUE = "\u001B[34m";
    static final String GREEN = "\u001B[32m";
    static final String RED = "\u001B[31m";
    static final String YELLOW = "\u001B[33m";
    static final String CYAN = "\u001B[36m";

    static Product head = null;
    static Scanner sc = new Scanner(System.in);

    // Add Product
    static void addProduct() {
        System.out.print("Enter Product ID: ");
        int id = sc.nextInt();

        System.out.print("Enter Product Name: ");
        String name = sc.next();

        System.out.print("Enter Quantity: ");
        int qty = sc.nextInt();

        System.out.print("Enter Price: ");
        double price = sc.nextDouble();

        Product newProduct = new Product(id, name, qty, price);
        newProduct.next = head;
        head = newProduct;

        System.out.println(GREEN + "✔ Product added successfully." + RESET);
    }

    // Display Products
    static void displayProducts() {
        if (head == null) {
            System.out.println(RED + "Inventory is empty." + RESET);
            return;
        }

        Product temp = head;
        System.out.println(BLUE + "\n--- Inventory List ---" + RESET);

        while (temp != null) {
            System.out.println(CYAN + "ID: " + temp.id);
            System.out.println("Name: " + temp.name);
            System.out.println("Quantity: " + temp.quantity);
            System.out.println("Price: ₹" + temp.price);

            if (temp.quantity < 5) {
                System.out.println(YELLOW + "⚠ Low Stock Warning!" + RESET);
            }

            System.out.println("----------------------------");
            temp = temp.next;
        }
    }

    // Search Product
    static void searchProduct() {
        System.out.print("Enter Product ID to search: ");
        int id = sc.nextInt();

        Product temp = head;
        while (temp != null) {
            if (temp.id == id) {
                System.out.println(GREEN + "✔ Product Found" + RESET);
                System.out.println("Name: " + temp.name);
                System.out.println("Quantity: " + temp.quantity);
                System.out.println("Price: ₹" + temp.price);
                return;
            }
            temp = temp.next;
        }
        System.out.println(RED + "✖ Product not found." + RESET);
    }

    // Update Quantity
    static void updateQuantity() {
        System.out.print("Enter Product ID: ");
        int id = sc.nextInt();

        Product temp = head;
        while (temp != null) {
            if (temp.id == id) {
                System.out.print("Enter new quantity: ");
                temp.quantity = sc.nextInt();
                System.out.println(GREEN + "✔ Quantity updated." + RESET);
                return;
            }
            temp = temp.next;
        }
        System.out.println(RED + "✖ Product not found." + RESET);
    }

    // Update Price
    static void updatePrice() {
        System.out.print("Enter Product ID: ");
        int id = sc.nextInt();

        Product temp = head;
        while (temp != null) {
            if (temp.id == id) {
                System.out.print("Enter new price: ");
                temp.price = sc.nextDouble();
                System.out.println(GREEN + "✔ Price updated." + RESET);
                return;
            }
            temp = temp.next;
        }
        System.out.println(RED + "✖ Product not found." + RESET);
    }

    // Delete Product
    static void deleteProduct() {
        System.out.print("Enter Product ID to delete: ");
        int id = sc.nextInt();

        Product temp = head, prev = null;

        while (temp != null && temp.id != id) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == null) {
            System.out.println(RED + "✖ Product not found." + RESET);
            return;
        }

        if (prev == null)
            head = temp.next;
        else
            prev.next = temp.next;

        System.out.println(GREEN + "✔ Product deleted." + RESET);
    }

    // Total Inventory Value
    static void totalInventoryValue() {
        double total = 0;
        Product temp = head;

        while (temp != null) {
            total += temp.quantity * temp.price;
            temp = temp.next;
        }

        System.out.println(BLUE + "Total Inventory Value: ₹" + total + RESET);
    }

    // Main Menu
    public static void main(String[] args) {
        int choice;

        do {
            System.out.println(BLUE + "\n=== Inventory Management System ===" + RESET);
            System.out.println("1. Add Product");
            System.out.println("2. Display Products");
            System.out.println("3. Search Product");
            System.out.println("4. Update Quantity");
            System.out.println("5. Update Price");
            System.out.println("6. Delete Product");
            System.out.println("7. Total Inventory Value");
            System.out.println("8. Exit");
            System.out.print("Enter choice: ");

            choice = sc.nextInt();

            switch (choice) {
                case 1 -> addProduct();
                case 2 -> displayProducts();
                case 3 -> searchProduct();
                case 4 -> updateQuantity();
                case 5 -> updatePrice();
                case 6 -> deleteProduct();
                case 7 -> totalInventoryValue();
                case 8 -> System.out.println(CYAN + "Exiting program..." + RESET);
                default -> System.out.println(RED + "Invalid choice!" + RESET);
            }
        } while (choice != 8);
    }
}
