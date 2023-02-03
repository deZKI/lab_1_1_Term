//
// Created by Кирилл on 31.01.2023.
//

#ifndef LAB_1_VASILEV_TABLE_H
#define LAB_1_VASILEV_TABLE_H

#include "Row.h"
#include <vector>
class Table {
private:
    std::vector<Row> rows;
    static void Header();
    static void End();
public:
    void DeleteRow();
    void EditRow();
    void EditCell();
    Table();
    Table(Row &first, Row &second, Row &third);
    ~Table();
    void AddRow();
    void PrintTable();
    void Manual();
};

#endif //LAB_1_VASILEV_TABLE_H
