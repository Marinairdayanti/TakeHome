#include <iostream>
#include "relasi.h"

using namespace std;

int main()
{
    List_hewan LM;
    List_jadwal LJ;
    List_relasi LR;
    address_hewan PM;
    address_jadwal PJ;
    address_relasi PR;
    createList_hewan(LM);
    createList_jadwal(LJ);
    createList_relasi(LR);
    menu(LM,LJ,LR);


    return 0;
}
