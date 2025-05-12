#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <numeric>
#include <functional>
#include <vector>
#include "Belov_LR3-4_ClassProduct.h"
using namespace std;

vector<Product> VC_Product;

//функция проверки корректности вводимых данных для целых чисел
bool UserInput(string input)
{
    //если строка пустая - ввод некорректен
    if(input.empty()) return false;
    //попытаться
    try{
        //преобразование введенного значения в тип int
        int number = stoi(input);
        if(number<0) return false;
    }
    catch(...) //если возникла ошибка в блоке try
    {
        return false;
    }
    return true;
}
//вспомогательная функция для ввода целых чисел 
function<void()> EnterNumber(int& varLink, string label){
    return [&varLink, label](){
        string raw_input;
        cout<<label<<" ";
        getline(cin,raw_input);

        while(!UserInput(raw_input)){
            cout<<label<<" ";
            getline(cin,raw_input);
        }
        varLink=stoi(raw_input);
    };
    
}
//функция проверки корректности вводимых данных для float
bool UserInputFloat(string input)
{
    //если строка пустая - ввод некорректен
    if(input.empty()) return false;
    //попытаться
    try{
        //преобразование введенного значения в тип int
        int number = stof(input);
        if(number<0) return false;
    }
    catch(...) //если возникла ошибка в блоке try
    {
        return false;
    }
    return true;
}
//вспомогательная функция для ввода дробных чисел(float)
function<void()> EnterNumber(float& varLink, string label){
    return [&varLink, label](){
        string raw_input;
        cout<<label<<" ";
        getline(cin,raw_input);

        while(!UserInputFloat(raw_input)){
            cout<<label<<" ";
            getline(cin,raw_input);
        }
        varLink=stof(raw_input);
    };
    
}
//вспомогательная функция для ввода строк
function<void()> EnterString(string&varLink,string label){
    return[&varLink,label](){
        cout<<label<<" ";
        getline(cin,varLink);
    };
}
//1)Пункт вызов createProDefault
void createProDefault()
{
    Product product;
    cout<<"default product " << product;
    VC_Product.push_back(product);
}
//5)отображение всех продуктов showArrayPro
void showArrayPro()
{
    cout<<"\n======================\n";
    for(const auto& product:VC_Product)
    {
        cout<<"\nПродукт по списку: "<<product;
        cout<<"\n--------------------------\n";
    }
    cout<<"\n=======================\n";
}
//2)Пункт вызова createProDeg
void createProName()
{
    string name;
    EnterString(name,"Введите имя: ")();
    Product product(name);
    cout<<"Выводим имя: "<<product;
    VC_Product.push_back(product);
}
//3)Пункт вызова createProCoeff
void createProCoeff(){
    string name;
    EnterString(name,"Введите имя: ")();
    float price;
    EnterNumber(price,"Введите цену: ")();
    int kolvo;
    EnterNumber(kolvo,"Введите кол-во: ")();
    int ingrCount;
    EnterNumber(ingrCount,"Введите количество ингридиентов: ")();
    vector<string>ListIngridient;
    for (int i = 0; i < ingrCount; ++i) {
        string ingr;
        EnterString(ingr,"Ингредиент "+to_string (i + 1) + ": ")();
        ListIngridient.push_back(ingr);
    }
    Product product(name,price,kolvo,ListIngridient);
    VC_Product.push_back(product);

}
//4)Пункт вызова createProCons
void createProCons(){
    Product product;
    cin>>product;
    VC_Product.push_back(product);
}
//6)Пункт вызова calcValPro
void calcValPro(){
    showArrayPro();
    int n1;
    EnterNumber(n1,"Введите номер продукта: ")();
    int n2;
    EnterNumber(n2,"Введите номер продукта: ")();
    Product product=VC_Product[n1]&VC_Product[n2];
    cout << product << endl;
    VC_Product.push_back(product);
}
//7)Пункт вызова sravArrProduct
void sravArrProduct(){
    showArrayPro();
    int n1;
    EnterNumber(n1,"Введите номер продукта: ")();
    int n2;
    EnterNumber(n2,"Введите номер продукта: ")();
    if(n1<VC_Product.size()&& n2<VC_Product.size()){
    if(VC_Product[n1]>VC_Product[n2])
    {
        cout<<n1<<" > "<<n2<<endl;
    }
    if(VC_Product[n1]<VC_Product[n2])
    {
        cout<<n1<<" < "<<n2<<endl;
    }
    if(VC_Product[n1]>=VC_Product[n2])
    {
        cout<<n1<<" >= "<<n2<<endl;
    }
    if(VC_Product[n1]<=VC_Product[n2])
    {
        cout<<n1<<" <= "<<n2<<endl;
    }
    if(VC_Product[n1]==VC_Product[n2])
    {
        cout<<n1<<" == "<<n2<<endl;
    }
    if(VC_Product[n1]!=VC_Product[n2])
    {
        cout<<n1<<" != "<<n2<<endl;
    }
}
else
{
    cout<<"error"<<endl;
}
}
//8)Пункт вызова sumArrProduct
void summArrProduct(){
    showArrayPro();
    int n1;
    EnterNumber(n1,"Введите номер продукта: ")();
    int n2;
    EnterNumber(n2,"Введите номер продукта: ")();
    float price=VC_Product[n1]+VC_Product[n2];
    cout << price << endl;
    
}
//9)Пункт вызова addPostAndPref
void addPostAndPref(){

}
//10)Пункт вызова addProduct
void addProduct(){

}

//реализация всего что вызывается в menu 
