#ifndef HEWAN_H_INCLUDED
#define HEWAN_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;


#define info_hewan(P) (P)->info_hewan
#define next_hewan(P) (P)->next_hewan
#define prev_hewan(P) (P)->prev_hewan
#define first_hewan(L) (L).first_hewan
#define jadwal(P) (P)->jadwal
#define kehewan(P) (P)->kehewan

struct hewan{
    string nama;
    string jenis;
    string habitat;
    int jumlah;
};

typedef struct elmList_hewan *address_hewan;

struct elmList_hewan{
    hewan info_hewan;
    address_hewan next_hewan;
    address_hewan prev_hewan;
};

struct List_hewan{
    address_hewan first_hewan;
};

void createList_hewan(List_hewan &L);
address_hewan alokasi_hewan(hewan x);
void dealokasi_hewan(address_hewan &P);
void insertFirst_hewan(List_hewan &L, address_hewan P);
void insertLast_hewan(List_hewan &L, address_hewan P);
address_hewan findElm_hewan(List_hewan L, string x);
void deleteFirst_hewan(List_hewan &L, address_hewan &P);
void deleteLast_hewan(List_hewan &L, address_hewan &P);
void printInfo_hewan(List_hewan L);
void insertAfter_hewan(address_hewan Prec, address_hewan P);
void deleteAfter_hewan(address_hewan Prec, address_hewan &P);
void editInfo_hewan(List_hewan L, address_hewan &P);
address_hewan input_hewan();
void deleteSearch_hewan(List_hewan &LM, address_hewan &P);
void data_hewan (List_hewan &L);




#endif // HEWAN_H_INCLUDED
