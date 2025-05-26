#include <ctime>
#include <iostream>
#include "Belov_LR3-4_ClassProduct.cpp"
//добавить конструктор копирования и вывод всех объектов
using namespace std;
//Структура для описания пункта меню
struct MenuItem{
    string title; //название пункта меню
    function<void()> action; //Действие, выполняемое при выборе пункта
};
int main()
{
    map<int, MenuItem> menu = {
        {1,{"Создание дефолтного конструктора Product", createProDefault}},
        {2,{"Преобразование", createProName}},
         {3,{"Параметризованный", createProCoeff}},
         {4,{"Создание объекта с клавиатуры", createProCons}},
        {5,{"Показать все Product", showArrayPro}},
        {6,{"Сложение(объединение партий товаров)", calcValPro}},
        {7,{"Сравнение по цене", sravArrProduct}},
         {8,{"Сложение по цене", summArrProduct}},
         {9,{"Постфиксный и префиксный инкремент по цене", addPostAndPref}},
         {10,{"Присваивание", equalProduct}},
    };

    int choice = 0; //Хранение выбора пользователя

    cout<<"Меню: "<<endl;

    //Вывод всех пунктов меню
    for(const auto& item:menu)
    {
        cout<<"Task "<<item.first<<". "<<item.second.title<<endl;
    }
    cout<<"0. Выход"<<endl;//Выход из программы
    while(true)
    {
        EnterNumber(choice, "Введите номер пункта: ")();

        //Выход из программы, если выбран пункт 0
        if(choice==0)
        {
            cout<<"@ 2025 FirstName LastName"<<endl;
            break;
        }
        cout<<endl<<"=============Action:==========="<<endl;

        //Проверка, существует ли выбранный пунтк меню
        if(menu.find(choice)!= menu.end())
        {
            menu[choice].action(); //Выполнение действия, связанного с пунктом меню
        } else{
            cout<<"Некорректный ввод.";//Сообщение об ошибке если пункт не найден
        }
        cout<<endl;

    }
    return 0;//Завершение работы

}