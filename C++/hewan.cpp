#include "hewan.h"

void createList_hewan(List_hewan &L){
    first_hewan(L)=NULL;
}

address_hewan alokasi_hewan(hewan x){
    address_hewan P=new elmList_hewan;
    info_hewan(P)=x;
    next_hewan(P)=NULL;
    prev_hewan(P)=NULL;
    return P;
}

void dealokasi_hewan(address_hewan &P){
    delete P;
}

void insertFirst_hewan(List_hewan &L, address_hewan P){
    address_hewan Q;
    if(first_hewan(L)==NULL){
        first_hewan(L)=P;
        next_hewan(P)=first_hewan(L);
    }
    else{
        Q=first_hewan(L);
        while(next_hewan(Q)!=first_hewan(L)){
            Q=next_hewan(Q);
        }
        next_hewan(P)=first_hewan(L);
        first_hewan(L)=P;
        prev_hewan(first_hewan(L))=P;
        next_hewan(Q)=P;
        prev_hewan(P)=Q;
    }
}

void insertLast_hewan(List_hewan &L, address_hewan P){
    address_hewan Q;
    if(first_hewan(L)==NULL){
        first_hewan(L)=P;
        next_hewan(P)=first_hewan(L);
    }
    else{
        Q=first_hewan(L);
        while(next_hewan(Q)!=first_hewan(L)){
            Q=next_hewan(Q);
        }
        next_hewan(Q)=P;
        next_hewan(P)=first_hewan(L);
        prev_hewan(P)=Q;
        prev_hewan(first_hewan(L))=P;
    }
}

address_hewan findElm_hewan(List_hewan L, string x){
    bool cek;
    address_hewan P;
    if(first_hewan(L)!=NULL){
        cek=false;
        P=first_hewan(L);
        while((cek==false)&&(next_hewan(P)!=first_hewan(L))){
            if(info_hewan(P).nama == x){
                cek=true;
            }
            else{
                P=next_hewan(P);
            }
        }
        if (cek == false){
            if(info_hewan(P).nama == x){
                cek=true;
            }
        }
    }
    if(cek!=true){
        return NULL;
    }
    return P;
}

void deleteFirst_hewan(List_hewan &L, address_hewan &P){
    address_hewan Q;
    if(first_hewan(L)!=NULL){
        Q=first_hewan(L);
        while(next_hewan(Q)!=first_hewan(L)){
            Q=next_hewan(Q);
        }
        P=first_hewan(L);
        first_hewan(L)=next_hewan(first_hewan(L));
        next_hewan(P)=NULL;
        prev_hewan(first_hewan(L))=Q;
        next_hewan(Q)=first_hewan(L);
    }
}

void deleteLast_hewan(List_hewan &L, address_hewan &P){
    address_hewan Prec;
    if(first_hewan(L)!=NULL){
        P=first_hewan(L);
        do{
            Prec=P;
            P=next_hewan(P);
        }while(next_hewan(P)!=first_hewan(L));
        next_hewan(Prec)=first_hewan(L);
        prev_hewan(first_hewan(L))=Prec;
    }
}

void printInfo_hewan(List_hewan L){
    address_hewan P;
    if(first_hewan(L)==NULL){
        cout << "========================================================================================================================" << endl;
        cout << "\t\t\t\t\t\t  Daftar Hewan" << endl;
        cout << "========================================================================================================================" << endl;
        cout<<endl;
        cout<<"\t\t\t\t\tBelum Ada Hewan yang Terdaftar\n"<<endl;
    }
    else{
        cout << "========================================================================================================================" << endl;
        cout << "\t\t\t\t\t\t  Daftar Hewan" << endl;
        cout << "========================================================================================================================" << endl;
        cout << "Nama Hewan \t\t| Jenis \t| Habitat" << endl;
        cout << "========================================================================================================================" << endl;
        P=first_hewan(L);
        while(next_hewan(P)!=first_hewan(L)){
            cout<<info_hewan(P).nama<<"\t| ";
            cout<<info_hewan(P).jenis<<"\t| "<<info_hewan(P).habitat;
            cout<<endl;
            P=next_hewan(P);

        }
        cout<<info_hewan(P).nama<<"\t| ";
            cout<<info_hewan(P).jenis<<"\t| "<<info_hewan(P).habitat;
        cout<<"\n\n";
    }
}

void insertAfter_hewan(address_hewan Prec, address_hewan P){
        next_hewan(P)=next_hewan(Prec);
        prev_hewan(next_hewan(Prec))=P;
        next_hewan(Prec)=P;
        prev_hewan(P)=Prec;
}

void deleteAfter_hewan(address_hewan Prec, address_hewan &P){
        P=next_hewan(Prec);
        prev_hewan(next_hewan(P))=prev_hewan(P);
        next_hewan(Prec)=next_hewan(P);
        next_hewan(P)=NULL;
        prev_hewan(P)=NULL;
}

void deleteSearch_hewan(List_hewan &LM, address_hewan &P){
    address_hewan Q, Prec;
    Q=first_hewan(LM);
    do{
        Q=next_hewan(Q);
    }while (next_hewan(Q)!=first_hewan(LM));
    //Q=next_buku(Q);
    if(P!=NULL){
        if(P==first_hewan(LM)){
            if(next_hewan(P)==first_hewan(LM)){
                first_hewan(LM)=NULL;
            }
            else{
                deleteFirst_hewan(LM, P);
                //P=first_buku(LM);
            }
        }else if(P==Q){
            deleteLast_hewan(LM, P);
            //P=Q;
        }else{
            Prec = prev_hewan(P);
            deleteAfter_hewan(Prec, P);
            //P=Prec;
        }
        //dealokasi_buku(P);
    }
}

void editInfo_hewan(List_hewan L, address_hewan &P){
    cin.ignore();
    cout<<"Nama Hewan\t\t: ";
    getline(cin,info_hewan(P).nama);
    cout<<"Jenis \t\t: ";
    getline(cin,info_hewan(P).jenis);
    cout<<"Penerbit \t\t: ";
    getline(cin,info_hewan(P).habitat);
}

address_hewan input_hewan(){
    hewan x;
    cin.ignore();
    cout<<"Nama Hewan\t\t\t: ";
    getline(cin,x.nama);
    cout<<"Jenis \t\t: ";
    getline(cin,x.jenis);
    cout<<"Habitat\t\t: ";
    getline(cin,x.habitat);

    return alokasi_hewan(x);
}

void data_hewan (List_hewan &L){
    hewan mb;
    address_hewan P;

    mb.nama = "GAJAH";
    mb.jenis = "MAMALIA";
    mb.habitat = "DARAT";
    P = alokasi_hewan(mb);
    insertLast_hewan(L,P);

    mb.nama = "ORANG UTAN";
    mb.jenis = "MAMALIA";
    mb.habitat = "DARAT\t";
    P = alokasi_hewan(mb);
    insertLast_hewan(L,P);

    mb.nama = "SALMON";
    mb.jenis = "PISCES";
    mb.habitat = "AIR";
    P = alokasi_hewan(mb);
    insertLast_hewan(L,P);

    mb.nama = "BURUNG MERAK";
    mb.jenis = "AVES";
    mb.habitat = "DARAT\t";
    P = alokasi_hewan(mb);
    insertLast_hewan(L,P);

    mb.nama = "KANGGURU";
    mb.jenis = "MAMALIA";
    mb.habitat = "DARAT\t";
    P = alokasi_hewan(mb);
    insertLast_hewan(L,P);

    mb.nama = "KATAK";
    mb.jenis = "AMPHIBIA";
    mb.habitat = "DARAT DAN AIR\t";
    P = alokasi_hewan(mb);
    insertLast_hewan(L,P);

    mb.nama = "KADAL";
    mb.jenis = "REPTILIA";
    mb.habitat = "DARAT\t";
    P = alokasi_hewan(mb);
    insertLast_hewan(L,P);
}
