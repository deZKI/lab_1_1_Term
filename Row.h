//
// Created by Кирилл on 31.01.2023.
//

#ifndef LAB_1_VASILEV_ROW_H
#define LAB_1_VASILEV_ROW_H
#include <string>
#include <iostream>
#include <iomanip>
class Row {
public:
    Row();
    Row(std::string &name, std::string &count, std::string &sales, std::string &m_percent);
    Row(std::string &&name, std::string &&count, std::string &&sales, std::string &&m_percent);
    Row(Row &&s);
    Row(const Row &s);
    ~Row();
    void SetName(const std::string &name);
    void SetCode(const std::string &count);
    void SetNom(const std::string &sales);
    void SetCount(const std::string &m_percent);
    void PrintR();
    Row &operator = (const Row &s);
private:
    std::string _name;
    std::string _count;
    std::string _sales;
    std::string _m_percent;
};
#endif //LAB_1_VASILEV_ROW_H
