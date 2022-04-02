#include <iostream>
#include <cstring>
#include <fstream>

class Product{
private:
    char name[16];
    double price;
public:
    Product(){
        setName("");
        setPrice(0);
    }

    Product(const char* name, double price){
        setName(name);
        setPrice(price);
    }

    void setName(const char* name){
        strcpy(this->name, name);
    }
    void setPrice(double price){
        this->price = price;
    }

    const char* getName() const{ 
        return this->name;
    }
    double getPrice() const{
        return this->price;
    }

    Product& operator=(const Product& other){
        if(this != &other){
            setName(other.getName());
            setPrice(other.getPrice());
        }
    }

    void print() const{
        std::cout << this->name << std::endl;
    }
};

const int CAPACITY = 20;
class Store{
private:
    Product products[CAPACITY];
    int productsCount;

public:
    Store(Product products[], int productsCount){
        setProducts(products, productsCount);
        setProductsCount(productsCount);
    }

    void setProducts(Product products[], int productsCount){
        for(int i = 0; i < productsCount; i++){
            this->products[i] = products[i];
        }
    }
    void setProductsCount(int productsCount){
        this->productsCount = productsCount;
    }
    Product getProducts(int index) const {
        return this->products[index];
    }
    int getProductsCount() const{
        return this->productsCount;
    }

    void addProduct(const Product& product){
        products[this->productsCount] = product;
        this->productsCount++;
    }

    void removeProduct(const Product& product){
        int index;
        for(int i = 0; i < this->productsCount; i++){
            if(strcmp(products[i].getName(), product.getName()) == 0)
                index = i;
        }

        for(int i = index; i < this->productsCount - 1; i++){
            this->products[i] = this->products[i + 1]; 
        }
        this->productsCount--;
    }

    void writeInFile(const char *filename){
        std::ofstream outFile(filename, std::ios::binary);
        if (!outFile.is_open()){
            std::cout << "Cannot open file!" << std::endl;
            return;
        }
        if (!outFile){
            std::cout << "Invalid operstion!" << std::endl;
            return;
        }

        outFile.write((char *)&this->products, sizeof(products));
        outFile.close();
    }

    void readInFile(const char *filename){
        std::ifstream inFile(filename, std::ios::binary);
        if (!inFile.is_open()){
            std::cout << "Cannot open file!" << std::endl;
            return;
        }
        if (!inFile){
            std::cout << "Invalid operstion!" << std::endl;
            return;
        }

        inFile.read((char*) &this->products, sizeof(products));
        inFile.close();
    }
};

int main(){
    Product products[3];
    products[0].setName("milk");
    products[0].setPrice(2.30);
    products[1].setName("eggs");
    products[1].setPrice(1.89);
    products[2].setName("orange juice");
    products[2].setPrice(2.10);

    Product p;
    p.setName("bread");
    p.setPrice(1.65);
    Store store(products, 3);

    store.addProduct(p);

    for(int i = 0; i < store.getProductsCount(); i++){
        store.getProducts(i).print();
    }
    std::cout << store.getProductsCount() << std::endl;

    store.removeProduct(products[2]);

       for(int i = 0; i < store.getProductsCount(); i++){
        store.getProducts(i).print();
    }
    std::cout << store.getProductsCount() << std::endl;

    store.writeInFile("store.bin");
    store.readInFile("store.bin");

    Product productsTest[3];
    for(int i = 0; i < 3; i++){
        productsTest[i].print();
    }

    Store storeTest(productsTest, 3);

    storeTest.readInFile("store.bin");
    for(int i = 0; i < storeTest.getProductsCount(); i++){
        storeTest.getProducts(i).print();
    }

}