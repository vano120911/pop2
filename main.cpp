#include "Bakery.h"
#include <iostream>

int main() {
    SmartArray db;
    db.load("bakery_db.bin");
    
    int choice = 0;
    while (true) {
        std::cout << "\n1. Show all products\n2. Add product\n3. Delete product\n4. Edit product\n5. Search by Name\n6. Search by Price\n7. Exit & Save\nChoice: ";
        std::cin >> choice;
        
        if (choice == 1) {
            db.print();
        } else if (choice == 2) {
            Product p;
            std::cout << "Enter Name Price Quantity: ";
            std::cin >> p;
            db.add(p);
        } else if (choice == 3) {
            int idx;
            std::cout << "Enter index: ";
            std::cin >> idx;
            db.remove(idx);
        } else if (choice == 4) {
            int idx;
            Product p;
            std::cout << "Enter index: ";
            std::cin >> idx;
            std::cout << "Enter new Name Price Quantity: ";
            std::cin >> p;
            db.edit(idx, p);
        } else if (choice == 5) {
            char n[32];
            std::cout << "Enter name: ";
            std::cin >> n;
            db.searchByName(n);
        } else if (choice == 6) {
            double p;
            std::cout << "Enter price: ";
            std::cin >> p;
            db.searchByPrice(p);
        } else if (choice == 7) {
            db.save("bakery_db.bin");
            break;
        }
    }
    return 0;
}