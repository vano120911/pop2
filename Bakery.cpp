#include "Bakery.h"
#include <cstring>
#include <fstream>

Product::Product() : price(0), quantity(0) { 
    name[0] = '\0'; 
}

Product::Product(const char* n, double p, int q) : price(p), quantity(q) {
    strncpy(name, n, 31);
    name[31] = '\0';
}

const char* Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }

std::ostream& operator<<(std::ostream& os, const Product& p) {
    os << p.getName()<< " " << p.getPrice()<< " " << p.getQuantity();
    return os;
}

std::istream& operator>>(std::istream& is, Product& p) {
    is >> p.name >> p.price >> p.quantity;
    return is;
}

SmartArray::SmartArray() : capacity(2), size(0) { 
    data = new Product[capacity]; 
}

SmartArray::~SmartArray() { 
    delete[] data; 
}

void SmartArray::resize() {
    capacity *= 2;
    Product* newData = new Product[capacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void SmartArray::add(const Product& p) {
    if (size == capacity) resize();
    data[size++] = p;
}

void SmartArray::remove(int index) {
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
}

void SmartArray::edit(int index, const Product& p) {
    data[index] = p;
}

void SmartArray::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << i << ". " << data[i] << "\n";
    }
}

void SmartArray::searchByName(const char* n) const {
    for (int i = 0; i < size; ++i) {
        if (strcmp(data[i].getName(), n) == 0) {
            std::cout << i << ". " << data[i] << "\n";
        }
    }
}

void SmartArray::searchByPrice(double p) const {
    for (int i = 0; i < size; ++i) {
        if (data[i].getPrice() == p) {
            std::cout << i << ". " << data[i] << "\n";
        }
    }
}

void SmartArray::save(const char* filename) const {
    std::ofstream out(filename, std::ios::binary);
    out.write((char*)&size, sizeof(int));
    out.write((char*)data, size * sizeof(Product));
}

void SmartArray::load(const char* filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) return;
    in.read((char*)&size, sizeof(int));
    if (size > capacity) {
        delete[] data;
        capacity = size * 2;
        data = new Product[capacity];
    }
    in.read((char*)data, size * sizeof(Product));
}

Product& SmartArray::operator[](int index) { 
    return data[index]; 
}