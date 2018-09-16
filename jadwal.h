#ifndef JADWAL_H_INCLUDED
#define JADWAL_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;



#define info_jadwal(P) (P)->info_jadwal
#define next_jadwal(P) (P)->next_jadwal
#define prev_jadwal(P) (P)->prev_jadwal
#define first_jadwal(L) (L).first_jadwal
#define kejadwal(P) (P)->kejadwal

struct jadwal{
    string masuk;
    string keluar;
};

typedef struct elmList_jadwal *address_jadwal;

struct elmList_jadwal{
    jadwal info_jadwal;
    address_jadwal next_jadwal;
    address_jadwal prev_jadwal;
};

struct List_jadwal{
    address_jadwal first_jadwal;
};

void createList_jadwal(List_jadwal &L);
address_jadwal alokasi_jadwal(jadwal x);
void dealokasi_jadwal(address_jadwal &P);
void insertFirst_jadwal(List_jadwal &L, address_jadwal P);
void insertLast_jadwal(List_jadwal &L, address_jadwal P);
address_jadwal findElm_jadwal(List_jadwal L, string x);
void deleteFirst_jadwal(List_jadwal &L, address_jadwal &P);
void deleteLast_jadwal(List_jadwal &L, address_jadwal &P);
void printInfo_jadwal(List_jadwal L);
void insertAfter_jadwal(address_jadwal Prec, address_jadwal P);
void deleteAfter_jadwal(address_jadwal Prec, address_jadwal &P);
address_jadwal input_jadwal();
void editInfo_jadwal(List_jadwal L, address_jadwal &P);
void data_jadwal (List_jadwal &L);
void deleteSearch_jadwal(List_jadwal &L, address_jadwal &P);



#endif // JADWAL_H_INCLUDED
