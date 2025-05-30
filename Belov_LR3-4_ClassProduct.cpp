#include "Belov_LR3-4_Methods.h"
#include <algorithm>
#include <numeric>

//при переопределении >> контролировать ввод - EnterNumber

// Конструктор по умолчанию
Product::Product() 
    : ProductName("NoName"), price(0.0), kolvo(0), ListIngridient({"None"}) {}

// Конструктор с одним параметром
Product::Product(const string & ProductName)
    : Product()  {this ->ProductName=ProductName;}

// Параметризованный конструктор
Product::Product(const string &ProductName, float price, int kolvo, vector<string> ListIngridient)
    : ProductName(ProductName), price(price), kolvo(kolvo), ListIngridient(ListIngridient) {}

// Конструктор копирования
Product::Product(const Product &ob)
    : Product(ob.ProductName, ob.price, ob.kolvo, ob.ListIngridient) {}

// Перегрузка оператора вывода
ostream& operator<<(ostream& mystream, const Product &obj) {
    mystream << "Название: " << obj.ProductName << "\nЦена: " << obj.price
             << "\nКоличество: " << obj.kolvo << "\nИнгредиенты: ";
    for (const auto& ingr : obj.ListIngridient) {
        mystream << ingr << " ";
    }
    return mystream;
}

// Перегрузка оператора ввода
istream& operator>>(istream& mystream, Product &obj) {
    EnterString(obj.ProductName,"Введите название товара: ")();
    EnterNumber(obj.price,"Введите цену: ")();
    EnterNumber(obj.kolvo,"Введите количество товара:")();
   
    cout<<"======================";

    obj.ListIngridient.clear();
    int ingrCount;
    EnterNumber(ingrCount,"Введите количество ингридиентов: ")();
    
    for (int i = 0; i < ingrCount; ++i) {
        string ingr;
        EnterString(ingr,"Ингредиент "+to_string (i + 1) + ": ")();
        obj.ListIngridient.push_back(ingr);
    }

    return mystream;
}

// Вычисление общей стоимости товара
float Product::calculateTotalCost() const {
    return price * kolvo;
}

// Перегрузка оператора сложения (объединение партий)
Product Product::operator&(const Product &b) {
    Product result = *this;
    result.ProductName= this->ProductName + "   " + b.ProductName;
    result.kolvo += b.kolvo;
        for (const auto& ingr : b.ListIngridient) {
            // if (find(result.ListIngridient.begin(), result.ListIngridient.end(), ingr) == result.ListIngridient.end()) {
                result.ListIngridient.push_back(ingr);
            }
        
    // }
    return result;
}

// Перегрузка оператора сравнения по цене
// bool Product::operator>(const Product &b) {
//     return this->price > b.price;
// }

// Перегрузка оператора сложения по цене (результат — сумма цен)
float Product::operator+(const Product &b) {
    return this->price + b.price;
}

// Префиксный инкремент (увеличивает цену)
Product& Product::operator++() {
    price += 1.0f;
    return *this;
}

// Постфиксный инкремент (увеличивает цену, но возвращает старое значение)
Product Product:: operator++(int) {
    Product temp = *this;
    this->price += 1.0f;
    return temp;
}

// Оператор присваивания
Product& Product::operator=(const Product& other) {
    if (this != &other) {
        ProductName = other.ProductName;
        price = other.price;
        kolvo = other.kolvo;
        ListIngridient = other.ListIngridient;
    }
    return *this;
}
