#include "Table.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "Russain");
    string c;
    bool over= false;
    Table t;
    t.PrintTable();
    t.Manual();
    while (!over) {
        std::cin >> c;
        if (c == "0") over = true;
        if (c == "1") t.PrintTable();
        if (c == "2") t.DeleteRow();
        if (c == "3") t.AddRow();
        if (c == "4") t.EditRow();
        if (c == "5") t.EditCell();
        if (c == "6") t.Manual();
    }
    std::cout << "Goodbey, World!" << std::endl;
    return 0;
}
