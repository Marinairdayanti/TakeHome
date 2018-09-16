#include "jadwal.h"

void createList_jadwal(List_jadwal &L){
    first_jadwal(L)=NULL;
}

address_jadwal alokasi_jadwal(jadwal x){
    address_jadwal P=new elmList_jadwal;
    info_jadwal(P)=x;
    next_jadwal(P)=NULL;
    prev_jadwal(P)=NULL;
    return P;
}

void dealokasi_jadwal(address_jadwal &P){
    delete P;
}

void insertFirst_jadwal(List_jadwal &L, address_jadwal P){
    address_jadwal Q;
    if(first_jadwal(L)==NULL){
        first_jadwal(L)=P;
        next_jadwal(P)=first_jadwal(L);
    }
    else{
        Q=first_jadwal(L);
        while(next_jadwal(Q)!=first_jadwal(L)){
            Q=next_jadwal(Q);
        }
        next_jadwal(P)=first_jadwal(L);
        first_jadwal(L)=P;
        prev_jadwal(first_jadwal(L))=P;
        next_jadwal(Q)=P;
        prev_jadwal(P)=Q;
    }
}

void insertLast_jadwal(List_jadwal &L, address_jadwal P){
    address_jadwal Q;
    if(first_jadwal(L)==NULL){
        first_jadwal(L)=P;
        next_jadwal(P)=first_jadwal(L);
    }
    else{
        Q=first_jadwal(L);
        while(next_jadwal(Q)!=first_jadwal(L)){
            Q=next_jadwal(Q);
        }
        next_jadwal(Q)=P;
        next_jadwal(P)=first_jadwal(L);
        prev_jadwal(P)=Q;
        prev_jadwal(first_jadwal(L))=P;
    }
}

address_jadwal findElm_jadwal(List_jadwal L, string x){
    bool cek;
    address_jadwal P;
    if(first_jadwal(L)!=NULL){
        cek=false;
        P=first_jadwal(L);
        while((cek==false)&&(next_jadwal(P)!=first_jadwal(L))){
            if(info_jadwal(P).keluar == x){
                cek=true;
            }
            else{
                P=next_jadwal(P);
            }
        }
        if (cek == false){
            if(info_jadwal(P).keluar == x){
                cek=true;
            }
        }
    }
    if(cek==false){
        return NULL;
    }
    return P;
}

void deleteFirst_jadwal(List_jadwal &L, address_jadwal &P){
    address_jadwal Q;
    if(first_jadwal(L)!=NULL){
        Q=first_jadwal(L);
        while(next_jadwal(Q)!=first_jadwal(L)){
            Q=next_jadwal(Q);
        }
        P=first_jadwal(L);
        first_jadwal(L)=next_jadwal(first_jadwal(L));
        next_jadwal(P)=NULL;
        prev_jadwal(first_jadwal(L))=Q;
        next_jadwal(Q)=first_jadwal(L);
    }
}

void deleteLast_jadwal(List_jadwal &L, address_jadwal &P){
    address_jadwal Prec;
    if(first_jadwal(L)!=NULL){
        P=first_jadwal(L);
        do{
            Prec=P;
            P=next_jadwal(P);
        }while(next_jadwal(P)!=first_jadwal(L));
        next_jadwal(Prec)=first_jadwal(L);
        prev_jadwal(first_jadwal(L))=Prec;
    }
}

void deleteSearch_jadwal(List_jadwal &L, address_jadwal &P){
    address_jadwal Q, Prec;
    Q=first_jadwal(L);
    do{
        Q=next_jadwal(Q);
    }while (next_jadwal(Q)!=first_jadwal(L));
    //Q=next_jadwal(Q);
    if(P!=NULL){
        if(P==first_jadwal(L)){
            if(next_jadwal(P)==first_jadwal(L)){
                first_jadwal(L)=NULL;
            }
            else{
                deleteFirst_jadwal(L, P);
            //P=first_jadwal(L);
            }
        }else if(P==Q){
            deleteLast_jadwal(L, P);
           // P=Q;
        }else{
            Prec = prev_jadwal(P);
            deleteAfter_jadwal(Prec, P);
            //P=Prec;
        }
        //dealokasi_jadwal(P);
    }

}

void printInfo_jadwal(List_jadwal L){
    address_jadwal P;
    if(first_jadwal(L)==NULL){
        cout << "=================================================================" << endl;
        cout << "\t\t  Daftar Jadwal Kebun Binatang" << endl;
        cout << "=================================================================" << endl;
        cout<<endl;
        cout<<"\t\t  Belum Ada Jadwal yang Terdaftar\n"<<endl;
    }
    else{
        system("cls");
        cout << "=================================================================" << endl;
        cout << "\t\t  Daftar Jadwal Kebun Binatang" << endl;
        cout << "=================================================================" << endl;
        cout << "Masuk \t| Keluar\t" << endl;
        cout << "=================================================================" << endl;
        P=first_jadwal(L);
        while(next_jadwal(P)!=first_jadwal(L)){
            cout<<info_jadwal(P).masuk<<"\t| "<<info_jadwal(P).keluar;
            cout<<endl;
            P=next_jadwal(P);

        }
        cout<<info_jadwal(P).masuk<<"\t| "<<info_jadwal(P).keluar;
        cout<<"\n\n";
    }
}

void insertAfter_jadwal(address_jadwal Prec, address_jadwal P){
        next_jadwal(P)=next_jadwal(Prec);
        prev_jadwal(next_jadwal(Prec))=P;
        next_jadwal(Prec)=P;
        prev_jadwal(P)=Prec;
}

void deleteAfter_jadwal(address_jadwal Prec, address_jadwal &P){
        P=next_jadwal(Prec);
        prev_jadwal(next_jadwal(P))=next_jadwal(P);
        next_jadwal(Prec)=next_jadwal(P);
        next_jadwal(P)=NULL;
        prev_jadwal(P)=NULL;
}

void editInfo_jadwal(List_jadwal L, address_jadwal &P){
    cout<<"Masuk \t: ";
    cin.ignore();
    getline(cin,info_jadwal(P).masuk);
    cout<<"Keluar \t: ";
    getline(cin,info_jadwal(P).keluar);
}

address_jadwal input_jadwal(){
    jadwal x;
    cin.ignore();
    cout<<"Masuk \t: ";
    getline(cin,x.masuk);
    cout<<"Keluar \t: ";
    getline(cin,x.keluar);
    return alokasi_jadwal(x);
}

void data_jadwal (List_jadwal &L){
    jadwal jur;
    address_jadwal P;

    jur.masuk = "10-02-2018";
    jur.keluar = "17-02-2018";
    P = alokasi_jadwal(jur);
    insertLast_jadwal(L,P);

    jur.masuk = "17-07-2018";
    jur.keluar = "25-07-2018";
    P = alokasi_jadwal(jur);
    insertLast_jadwal(L,P);

    jur.masuk = "11-09-2018";
    jur.keluar = "18-09-2018";
    P = alokasi_jadwal(jur);
    insertLast_jadwal(L,P);

    jur.masuk = "02-01-2018";
    jur.keluar = "10-01-2018";
    P = alokasi_jadwal(jur);
    insertLast_jadwal(L,P);

    jur.masuk = "17-03-2018";
    jur.keluar = "21-03-2018";
    P = alokasi_jadwal(jur);
    insertLast_jadwal(L,P);

    jur.masuk = "01-02-2018";
    jur.keluar = "08-02-2018";
    P = alokasi_jadwal(jur);
    insertLast_jadwal(L,P);

    jur.masuk = "05-12-2018";
    jur.keluar = "12-12-2018";
    P = alokasi_jadwal(jur);
    insertLast_jadwal(L,P);
}
