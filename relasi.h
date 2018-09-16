#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "jadwal.h"
#include "hewan.h"
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;



#define next_relasi(P) (P)->next_relasi
#define prev_relasi(P) (P)->prev_relasi
#define first_relasi(L) (L).first_relasi

typedef struct elmList_relasi *address_relasi;

struct elmList_relasi{
    address_relasi next_relasi;
    address_relasi prev_relasi;
    address_jadwal kejadwal;
    address_hewan kehewan;
};

struct List_relasi{
    address_relasi first_relasi;
};

void createList_relasi(List_relasi &L);
address_relasi alokasi_relasi();
void dealokasi_relasi(address_relasi &P);
void insertFirst_relasi(List_relasi &L, address_relasi P);
void insertLast_relasi(List_relasi &L, address_relasi P);
address_relasi find_relasi(List_relasi L, string x, string y);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void print_relasi(List_relasi L);
void insertAfter_relasi(address_relasi Prec, address_relasi P);
void deleteAfter_relasi(address_relasi Prec, address_relasi &P);
void menu(List_hewan LM, List_jadwal LJ, List_relasi LR);
void input_relasi(List_hewan LM, List_jadwal LJ, List_relasi &LR);
void deleteSearch_relasi(List_relasi &L, address_relasi &P);
void delete_buku(List_relasi &LR, List_hewan &LM, address_hewan &PM);
void delete_jadwal(List_relasi &LR, List_jadwal &LJ, address_jadwal &PJ);
void search_hewan(List_hewan LM, List_relasi LR, address_hewan P);
void search_jadwal(List_jadwal LJ, List_relasi LR, address_jadwal PJ);
void data_relasi (List_relasi &L, List_hewan LM, List_jadwal LJ);
void delete_relasi(List_relasi &L, address_relasi &P);
address_hewan hitunghewan(List_hewan LM, List_relasi LR);

#endif // RELASI_H_INCLUDED
