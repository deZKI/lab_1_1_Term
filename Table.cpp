//
// Created by Кирилл on 31.01.2023.
//

#include "Table.h"
void Table::Header(){
    std::cout<<"---------------------------------------------------------------------------------------\n";
    std::cout<<"|Фирмы - производители СКБД                                                           |\n";
    std::cout<<"---------------------------------------------------------------------------------------\n";
    std::cout<<"|Фирма       |Количество.продуктов      |Годовой объем продажи($)     |Часть рынка (%)|\n";
    std::cout<<"---------------------------------------------------------------------------------------\n";
}
void Table::End(){
    std::cout<<"|Примечание: по данным Gartner Group за 1999г                                         |\n";
    std::cout<<"---------------------------------------------------------------------------------------\n";
}
void Table::DeleteRow(){
    size_t n;
    std::cout<<"Input number of row which you need to delete: ";
    std::cin >> n;
    try{
        if (n>rows.size()-1) throw "n > number of rows";
        if (n<=0) throw "n<=0";
    }
    catch (const char* execption){
        std::cout <<"Mistake deletrow:" <<execption <<std::endl;
        DeleteRow();
    }
    rows.erase(rows.begin());
}

void Table::EditRow(){
    size_t n;
    std::cout<<"Input number of row: ";
    std::cin >> n;
    try{
        if (n>rows.size()-1) throw "n > number of rows";
        if (n<=0) throw "n<=0";
    }
    catch (const char* execption){
        std::cout <<"Mistake editTab: " <<execption <<std::endl;
        EditRow();
    }

    std::string s;

    std::cout<<"Input _name: ";
    std::cin>>s;
    rows[n-1].SetName(s);

    std::cout<<"Input _count: ";
    std::cin>>s;
    rows[n-1].SetCode(s);

    std::cout<<"Input _sales: ";
    std::cin>>s;
    rows[n-1].SetCount(s);

    std::cout<<"Input _m_percent: ";
    std::cin>>s;
    rows[n-1].SetNom(s);

}
void Table::EditCell(){
    std::string s;
    int r,col;
    std::cout<<"Input number of row: ";
    std::cin >> r;
    try{
        if (r>rows.size()) throw "r > number of rows";
        if (r<=0) throw "r<=0";
    }
    catch (const char* execption){
        std::cout <<"Mistake editRow: " <<execption <<std::endl;
        EditCell();
    }
    std::cout<<"Input number of col: ";
    std::cin >> col;
    try{
        if (col>4) throw "col > number of col";
        if (col<=0) throw "col<=0";
    }
    catch (const char* execption){
        std::cout <<"Mistake editRow: " <<execption <<std::endl;
        EditCell();
    }
    std::cout <<"Input value";
    std::cin >>s;
    switch (col) {
        case 1: rows[r-1].SetName(s);
            break;
        case 2:rows[r-1].SetCode(s);
            break;
        case 3:rows[r-1].SetCount(s);
            break;
        case 4:rows[r-1].SetNom(s);
            break;
    }
}
Table::Table(){//должна быть инициализация
    rows.push_back(Row("Oracle","1","2488000000","31.1"));//это rvalue
    rows.push_back(Row("IBM","3","2392000000","29.9"));
    rows.push_back(Row("Microsoft","2","1048000000","13.1"));
}
Table::Table(Row &first,Row &second,Row &third){
    rows.push_back(std::move(first)); //перемещение
    rows.push_back(std::move(second));
    rows.push_back(std::move(third));
}

Table::~Table(){//деструктор таблицы
    rows.clear();//очистка таблицы
}
void Table::AddRow(){
    std::string s;
    Row line;

    std::cout<<"Input _name: ";
    std::cin>>s;
    line.SetName(s);

    std::cout<<"Input _count: ";
    std::cin>>s;
    line.SetCode(s);

    std::cout<<"Input _sales: ";
    std::cin>>s;
    line.SetNom(s);

    std::cout<<"Input _m_percent: ";
    std::cin>>s;
    line.SetCount(s);
    rows.push_back(std::move(line));// работа конструктора перемещения move :lvalue->rvalue, c++11
}
void Table::PrintTable(){
    Header();
    for (auto &now:rows){
        now.PrintR();
    }
    End();
}
void Table::Manual(){
    std::cout <<"0 – exit\n"
              <<"1 – print table\n"
              <<"2 – remove row\n"
              <<"3 - add row\n"
              <<"4 - edit row\n"
              <<"5 - edit cell\n"
              <<"6 - print manual\n"
            ;}
