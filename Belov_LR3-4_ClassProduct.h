#ifndef BELOV_LR3_4_CLASSPRODUCT_H
#define BELOV_LR3_4_CLASSPRODUCT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product
{
    string ProductName;
    float price;
    int kolvo;
    vector<string>ListIngridient;

    public:
    //Конструкторы 
    Product();//конструктор
    //параметризованный конструктор 
    Product(const string &ProductName);
    //параметризованный конструктор
    Product(const string &ProductName,float price,int kolv,vector<string>ListIngridient);
    Product(const Product &ob);//конструктор копирования

    ~Product()//деструктор
    { }

    //set-методы
    void setProductName(const string& ProductName){this->ProductName=ProductName; }
    void setprice(const float& price){this->price=price; }
    void setkolvo(const int& kolvo){this->kolvo=kolvo; }
    void setListIngridient(vector<string>& ListIngridient){this->ListIngridient=ListIngridient; }

    //get-методы
    string getProductName() const{return ProductName; }
    float getprice() const{return price; }
    int getkolvo() const{return kolvo; }
    vector<string> getListIngridient() const{return ListIngridient; }

    //Объявление операторов для ClassProduct.cpp
    float calculateTotalCost() const;
    Product operator&(const Product &b);
    bool operator>(const Product &b);
    float operator+(const Product &b);
    Product &operator++();
    Product operator++(int); 

    friend ostream& operator<<(ostream& mystream, const Product &obj);
    friend istream& operator>>(istream& mystream, Product &obj);



};

#endif