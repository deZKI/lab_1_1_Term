//
// Created by Кирилл on 31.01.2023.
//

#include "Row.h"

void Row::SetName(const std::string &name) {
    Row::_name = name;
}

void Row::SetCode(const std::string &count) {
    Row::_count = count;
}

void Row::SetNom(const std::string &sales) {
    Row::_sales = sales;
}

void Row::SetCount(const std::string &m_percent) {
    Row::_m_percent = m_percent;
}
Row::Row(std::string &&name, std::string &&count, std::string &&sales, std::string&&m_percent) {
    std::swap(this->_name, name);
    std::swap(this->_count, count);
    std::swap(this->_m_percent, count);
    std::swap(this->_sales, sales);
}

Row::Row(Row &&s){
    std::swap(_name, s._name);
    std::swap(_count, s._count);
    std::swap(_m_percent, s._m_percent);
    std::swap(_sales, s._sales);
}

void Row::PrintR(){
    std::cout << "|" << std::setw(11) << _name << "|" << std::setw(27) << _count << "|" << std::setw(29) << _sales << "|"
              << std::setw(15) << _m_percent << "|" << std::endl;
    char s='-';
    std::cout<<"---------------------------------------------------------------------------------------\n";
}
Row::Row(){
    _name="unknown";
    _count="unknown";
    _sales="unknown";
    _m_percent="unknown";
}

Row::Row(const Row &s){
    _name=s._name;_count=s._count;_m_percent=s._m_percent;_sales=s._sales;
};


Row &Row::operator = (const Row &s){
    if (this!= &s){
        _name = s._name;
        _count = s._count;
        _m_percent = s._m_percent;
        _sales = s._sales;
    }
    return *this;
}
Row::~Row() {
    _name="";_count="";_sales="";_m_percent="";
}

Row::Row(std::string &name, std::string &count, std::string &sales, std::string &m_percent) {
    this->_name = name;
    this->_count = count;
    this->_sales = sales;
    this->_m_percent = m_percent;
}




