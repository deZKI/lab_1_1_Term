#include "Table.h"
#include <stdlib.h>
using namespace std;
int main() {
    string c;
    bool over=1;
    Table t;
    t.PrintTable();
    t.Manual();
    while (over!=0) {
        std::cin >> c;
        if (c == "0") over = 0;
        if (c == "1") t.PrintTable();
        if (c == "2") t.DeleteRow();
        if (c == "3") t.AddRow();
        if (c == "4") t.EditRow();
        if (c == "5") t.EditCell();
        if (c == "6") t.Manual();
    }
    //Table a(std::move(t));//передаю rvalue cсылку поэтому операция перемещения
    std::cout << "Goodbey, World!" << std::endl;
    return 0;



}
