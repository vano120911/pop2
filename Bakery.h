#ifndef BAKERY_H
#define BAKERY_H

#include <iostream>

class Product {
    char name[32];
    double price;
    int quantity;

public:
    Product();
    Product(const char* n, double p, int q);
    
    const char* getName() const;
    double getPrice() const;
    int getQuantity() const;

    friend std::ostream& operator<<(std::ostream& os, const Product& p);
    friend std::istream& operator>>(std::istream& is, Product& p);
};

class SmartArray {
    Product* data;
    int capacity;
    int size;
    void resize();

public:
    SmartArray();
    ~SmartArray();
    
    void add(const Product& p);
    void remove(int index);
    void edit(int index, const Product& p);
    void print() const;
    void searchByName(const char* n) const;
    void searchByPrice(double p) const;
    
    void save(const char* filename) const;
    void load(const char* filename);
    
    Product& operator[](int index);
};

#endif