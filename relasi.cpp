#include "relasi.h"

void createList_relasi(List_relasi &L){
    first_relasi(L)=NULL;
}

address_relasi alokasi_relasi(address_hewan PM, address_jadwal PJ){
    address_relasi P = new elmList_relasi;
    kejadwal(P)= PJ;
    kehewan(P)=PM;
    next_relasi(P)= NULL;
    return P;
}

void dealokasi_relasi(address_relasi &P){
    delete P;
}

void insertFirst_relasi(List_relasi &L, address_relasi P){
    if(first_relasi(L)==NULL){
        first_relasi(L)=P;
        next_relasi(first_relasi(L))=first_relasi(L);
        prev_relasi(first_relasi(L))=first_relasi(L);
    }
    else{
    	address_relasi Q=prev_relasi(first_relasi(L));
    	if(next_relasi(first_relasi(L))==first_relasi(L)){
            next_relasi(P)=first_relasi(L);
            prev_relasi(P)=Q;
            next_relasi(Q)=P;
            prev_relasi(Q)=P;
            first_relasi(L)=P;
    	}
        else{
            next_relasi(P)=first_relasi(L);
            prev_relasi(P)=Q;
            prev_relasi(first_relasi(L))=P;
            next_relasi(Q)=P;
            first_relasi(L)=P;
        }
    }
}

void insertLast_relasi(List_relasi &L, address_relasi P){
    if(first_relasi(L)==NULL){
        first_relasi(L)=P;
        next_relasi(first_relasi(L))=first_relasi(L);
        prev_relasi(first_relasi(L))=first_relasi(L);
    }
    else{
        address_relasi Q=prev_relasi(first_relasi(L));
        prev_relasi(P)=Q;
        prev_relasi(first_relasi(L))=P;
        next_relasi(P)=first_relasi(L);
        next_relasi(Q)=P;
    }
}

address_relasi findElm_relasi(List_relasi L, address_hewan PM, address_jadwal PJ){
    address_relasi P = first_relasi(L);
    bool found = false;
    if (first_relasi(L) != NULL){
        while ((next_relasi(P)!=NULL)&&(found == false)){
            if (kehewan(P) == PM&& kejadwal(P) == PJ){
                found = true;
                return P;
            }else{
                P=next_relasi(P);
            }
        }
    }
    else{
        P=NULL;
    }
    return P;
}

void deleteFirst_relasi(List_relasi &L, address_relasi &P){
    if(first_relasi(L)!=NULL){
        P=first_relasi(L);
    	if(next_relasi(first_relasi(L))==first_relasi(L)){
    		first_relasi(L)=NULL;
		}
		else{
            address_relasi Q=prev_relasi(first_relasi(L));
	        first_relasi(L)=next_relasi(P);
	        prev_relasi(first_relasi(L))=Q;
	        next_relasi(Q)=first_relasi(L);
	        next_relasi(P)=NULL;
	        prev_relasi(P)=NULL;
        }
    }
    else{
        cout<<"Data kosong"<<endl;
    }
}

void deleteLast_relasi(List_relasi &L, address_relasi &P){
        if(first_relasi(L)!=NULL){
    	if(next_relasi(first_relasi(L))==first_relasi(L)){
    		P=first_relasi(L);
    		createList_relasi(L);
		}
		else{
		    address_relasi Q=prev_relasi(prev_relasi(first_relasi(L)));
	        P=next_relasi(Q);
	        next_relasi(Q)=first_relasi(L);
	        prev_relasi(first_relasi(L))=Q;
	        next_relasi(P)=NULL;
	        prev_relasi(P)=NULL;
    	}
    }
    else{
        cout<<"Data kosong"<<endl;
    }
}

void print_relasi(List_relasi L){
    address_relasi P;
    if (first_relasi(L) == NULL){
        cout << "=========================================================================" << endl;
        cout << "\t\t  Jadwal Masuk Kebun Binatang" << endl;
        cout << "=========================================================================" << endl;
        cout<<endl;
        cout<<"\t      Belum Ada Pengunjung Yang Masuk\n"<<endl;
    }
    else{
        cout << "=========================================================================" << endl;
        cout << "\t\t  Jadwal Masuk Kebun Binatang" << endl;
        cout << "=========================================================================" << endl;
        cout << "Tanggal Masuk \t| Tanggal Keluar \t| Nama Hewan \t\t|" << endl;
        cout << "=========================================================================" << endl;
        P = first_relasi(L);
        while (next_relasi(P) != first_relasi(L)){
            cout<<info_jadwal(kejadwal(P)).masuk<<"\t\t|"<<info_jadwal(kejadwal(P)).keluar<<"\t\t|"<<info_hewan(kehewan(P)).nama;
            cout<<endl;
            P = next_relasi(P);
        }
        cout<<info_jadwal(kejadwal(P)).masuk<<"\t\t|"<<info_jadwal(kejadwal(P)).keluar<<"\t\t|"<<info_hewan(kehewan(P)).nama;
        cout<<endl;
    }
}

void insertAfter_relasi(List_relasi &L, address_relasi prec, address_relasi &P){
    if (first_relasi(L) == NULL){
        first_relasi(L) = P;
     }
     else{
         next_relasi(P) = next_relasi(prec);
         next_relasi(prec) = P;
     }
}

void deleteAfter_relasi(address_relasi Prec, address_relasi &P){
    P=next_relasi(Prec);
    prev_relasi(next_relasi(P))=prev_relasi(P);
    next_relasi(Prec)=next_relasi(P);
    next_relasi(P)=NULL;
    prev_relasi(P)=NULL;
}

void delete_relasi(List_relasi &L, address_relasi &P){
    address_relasi Q, Prec;
    if(P!=NULL){
        Q=first_relasi(L);
        do{
            Q=next_relasi(Q);
        }while (next_relasi(Q)!= first_relasi(L));
        //Q=next_relasi(Q);
        if(P==first_relasi(L)){
             if(next_relasi(P)==first_relasi(L)){
                first_relasi(L)=NULL;
            }
            else{
                deleteFirst_relasi(L, P);
                //P=first_relasi(L);
            }
        }
        else if(P==Q){
            deleteLast_relasi(L, P);
            //P=Q;
        }
        else{
            Prec = prev_relasi(P);
            deleteAfter_relasi(Prec, P);
            //P=Prec;
        }
        //dealokasi_relasi(P);
    }
}

void deleteSearch_relasi(List_relasi &L, address_relasi &P){
    address_relasi Q, Prec;
    if(P!=NULL){
        Q=first_relasi(L);
        while (next_relasi(Q)!= first_relasi(L)){
            Q=next_relasi(Q);
        }
        Q=next_relasi(Q);
        if(P==first_relasi(L)){
            if(next_relasi(P)==first_relasi(L)){
                first_relasi(L)=NULL;
            }
            else{
                deleteFirst_relasi(L, P);
                P=first_relasi(L);
            }
        }
        else if(P==Q){
            deleteLast_relasi(L, P);
            P=Q;
        }
        else{
            Prec = prev_relasi(P);
            deleteAfter_relasi(Prec, P);
            P=Prec;
        }
        //dealokasi_relasi(P);
    }
}

void delete_hewan(List_relasi &LR, List_hewan &LM, address_hewan &PM){
    address_relasi P=first_relasi(LR);
    if(first_relasi(LR)!=NULL){
       do{
            if(kehewan(P)==PM){
                deleteSearch_relasi(LR, P);
            }
            P=next_relasi(P);
        } while(next_relasi(P)!=first_relasi(LR));
        if(kehewan(P)==PM){
            deleteSearch_relasi(LR, P);
        }
    }
    deleteSearch_hewan(LM, PM);

}

void delete_jadwal(List_relasi &LR, List_jadwal &LJ, address_jadwal &PJ){
    address_relasi P=first_relasi(LR);
    if(first_relasi(LR)!=NULL){
        do{
            if(kejadwal(P)==PJ){
                deleteSearch_relasi(LR, P);
            }
            P=next_relasi(P);
        }while(next_relasi(P)!=first_relasi(LR));
        if(kejadwal(P)==PJ){
            deleteSearch_relasi(LR, P);
        }
    }

    deleteSearch_jadwal(LJ, PJ);
}

void input_relasi(List_hewan LM, List_jadwal LJ, List_relasi &LR){
    address_hewan PM;
    address_jadwal PJ;
    address_relasi PR;
    hewan mdicari;
    jadwal jdicari;
    printInfo_hewan(LM);
    cout<<"Nama Hewan : ";
    cin.ignore();
    getline(cin,mdicari.nama);
    PM=findElm_hewan(LM,mdicari.nama);
    if (PM!=NULL){
        system("cls");
        printInfo_jadwal(LJ);
        cout<<"Nama Hewan : "<<mdicari.nama<<endl;
         cout<<"Jadwal : ";
        getline(cin, jdicari.keluar);
        PJ=findElm_jadwal(LJ, jdicari.keluar);
        if (PJ!=NULL){
            PR=alokasi_relasi(PM,PJ);
            insertLast_relasi(LR,PR);
            cout<<endl;
            cout<<" Hewan Berhasil dikunjungi"<<endl;
        }
        else{
            cout<<endl;
            cout<<"Jadwal Tidak Tersedia"<<endl;
        }
    }
    else{
        cout<<"Hewan Tidak ditemukan"<<endl;
    }
}

address_relasi find_relasi(List_relasi L, string x, string y){
    bool cek;
    address_relasi P;
    if(first_relasi(L)!=NULL){
        cek=false;
        P=first_relasi(L);
        while((cek==false)&&(next_relasi(P)!=first_relasi(L))){
            if(info_hewan(kehewan(P)).nama == x){
                if(info_jadwal(kejadwal(P)).keluar == y){
                    cek=true;
                    return P;
                }
            }
            else{
                P=next_relasi(P);
            }
        }
        if (cek == false){
            if(info_hewan(kehewan(P)).nama == x){
                if(info_jadwal(kejadwal(P)).keluar == y){
                    cek=true;
                }
            }
        }
    }
    if(cek!=true){
        return P=NULL;
    }
    return P;
}

void menu (List_hewan LM, List_jadwal LJ, List_relasi LR) {
    int pil;
    hewan mdicari;
    jadwal jdicari;
    address_hewan PM;
    address_jadwal PJ;
    address_relasi PR;
    data_hewan (LM);
    data_jadwal (LJ);
    data_relasi(LR, LM, LJ);
    do {
        system("cls");
        cout << "***************************************************" << endl;
        cout << "\t  KEBUN BINATANG BANDUNG " << endl;
        cout << "==================================================" << endl;
        cout << " -- INPUT -- " << endl;
        cout << "1.  Menambahkan Hewan Baru" << endl;
        cout << "2.  Menambahkan Jadwal Masuk" << endl;
        cout << "3.  Melakukan Masuk" << endl;
        cout << " -- VIEW -- " << endl;
        cout << "4.  Menampilkan Jadwal Masuk dan Hewannya" << endl;
        cout << "5.  Jadwal Masuk untuk Melihat Hewan" << endl;
        cout << "6.  Jadwal Masuk untuk Melihat Hewan dengan Deadline Hari Ini" << endl;
        cout << "7.  Kebun Binatang dengan Jadwal Masuk Paling Sedikit" << endl;
        cout << " -- DELETE -- " << endl;
        cout << "8.  Menghapus Suatu Data Hewan" << endl;
        cout<<endl;
        cout << "0.  Exit " << endl;
        cout<<endl;
        cout << "Masukkan Pilihan : ";
        cin >> pil;
        switch(pil){
        case 1:
            system("CLS");
            cout << "==================================================" << endl;
            cout << "\t\tMenambahkan Hewan Baru" << endl;
            cout << "==================================================" << endl;
            PM=input_hewan();
            insertLast_hewan(LM,PM);
            cout<<endl;
            cout<<"Hewan Berhasil ditambahkan"<<endl;
            cout<<endl;
            system("pause");
            break;
        case 2:
            system("CLS");
            cout << "==================================================" << endl;
            cout << "\t\tMenambahkan Jadwal Masuk " << endl;
            cout << "==================================================" << endl;
            PJ=input_jadwal();
            insertLast_jadwal(LJ,PJ);
            cout<<endl;
            cout<<"Jadwal Berhasil ditambahkan"<<endl;
            cout<<endl;
            system("pause");
            break;
        case 3:
            system("cls");
            input_relasi(LM,LJ,LR);
            cout<<endl;
            system("pause");
            break;
        case 4:
            system("CLS");
            print_relasi(LR);
            system("PAUSE");
            break;
        case 5:
            system("cls");
            printInfo_hewan(LM);
            cout<<"Masukkan Nama Hewan: ";
            cin.ignore();
            getline(cin,mdicari.nama);
            PM=findElm_hewan(LM, mdicari.nama);
            if(PM!=NULL){
                cout<<endl;
                search_hewan(LM, LR, PM);
                cout<<endl;
            }
            else{
                cout<<"\nHewan Tidak ditemukan\n"<<endl;
            }
            system("pause");
            break;
        case 6:
            system("cls");
            printInfo_jadwal(LJ);
            cout<<"Tanggal Hari Ini: ";
            cin.ignore();
            getline(cin,jdicari.keluar);
            PJ=findElm_jadwal(LJ, jdicari.keluar);
            if(PJ!=NULL){
                cout<<endl;
                cout<<"Hewan yang Memiliki Deadline Pada "<<jdicari.keluar<<" : "<<endl;
                search_jadwal(LJ, LR, PJ);
                cout<<endl;
            }
            else{
                cout<<"\nJadwal Tiadk Ditemukan\n"<<endl;
            }
            system("pause");
            break;
        case 7:
            system("CLS");
            PM = hitunghewan(LM, LR);
            cout<<"Hewan yang Dilihat Paling Sedikit\t: "<< info_hewan(PM).nama<<endl;
            cout<<"Banyaknya Hewan yang DiLIHAT\t\t: "<<info_hewan(PM).jumlah<<"\n\n";
            system("PAUSE");
            break;
        case 8:
            system("Cls");
            printInfo_hewan(LM);
            cout<<"Masukkan Hewan yang Dihapus: ";
            cin.ignore();
            getline(cin,mdicari.nama);
            PM=findElm_hewan(LM,mdicari.nama);
            if(PM!=NULL){
                delete_hewan(LR, LM, PM);
                cout<<endl;
                cout<<"Data Hewan Berhasil Dihapus"<<endl;
                cout<<endl;
            }
            else{
                cout<<endl;
                cout<<"Data Hewan tidak ditemukan"<<endl;
                cout<<endl;
            }
            system("PAUSE");
            break;
        case 0:
            cout<<"\nTerimakasih Telah Menggunakan Aplikasi Kebun Binatang Bandung\n"<<endl;
            system("PAUSE");
            break;
        default:
            cout<<endl;
            cout << "Angka yang anda masukkan salah, silakan masukkan angka dari 0 - 13" << endl;
            cout<<endl;
            system("PAUSE");
            break;
        }
    }while (pil!=0);
}

void search_hewan(List_hewan LM, List_relasi LR, address_hewan PM){
    address_relasi PR=first_relasi(LR);
    int i=0;
    while (next_relasi(PR) != first_relasi(LR)){
        if(info_hewan(PM).nama == info_hewan(kehewan(PR)).nama){
            i++;
            cout<<"Dilihat Pada Tanggal : "<<info_jadwal(kejadwal(PR)).keluar<<endl;
        }
        PR = next_relasi(PR);
    }
    if(info_hewan(PM).nama == info_hewan(kehewan(PR)).nama){
            i++;
            cout<<"Dilihat Pada Tanggal : "<<info_jadwal(kejadwal(PR)).keluar<<endl;
        }
    if(i==0){
        cout<<"Hewan Ini Belum Dilihat"<<endl;
    }
}

void search_jadwal(List_jadwal LJ, List_relasi LR, address_jadwal PJ){
    address_relasi PR=first_relasi(LR);
    int i=0;
    while (next_relasi(PR) != first_relasi(LR)){
        if(info_jadwal(PJ).keluar == info_jadwal(kejadwal(PR)).keluar){
            i++;
            cout<<i<<". "<<info_hewan(kehewan(PR)).nama<<endl;
        }
        PR = next_relasi(PR);
    }
    if(info_jadwal(PJ).keluar == info_jadwal(kejadwal(PR)).keluar){
            i++;
            cout<<i<<". "<<info_hewan(kehewan(PR)).nama<<endl;
    }
    if(i==0){
        cout<<"Hari Ini Tidak Ada Deadline Keluar"<<endl;
    }
}

address_hewan hitunghewan(List_hewan LM, List_relasi LR){
    address_relasi PR=first_relasi(LR);
    address_hewan PM=first_hewan(LM);
    do{
        info_hewan(PM).jumlah = 0;
        PM = next_hewan(PM);
    }while (next_hewan(PM) != first_hewan(LM));

    PM=first_hewan(LM);
    do{
        do{
            if(info_hewan(PM).nama == info_hewan(kehewan(PR)).nama){
                info_hewan(PM).jumlah++;
            }
            PR = next_relasi(PR);
        }while(next_relasi(PR) != first_relasi(LR));
        PM = next_hewan(PM);
    } while (next_hewan(PM) != first_hewan(LM));

    PM=first_hewan(LM);
    int mins = info_hewan(PM).jumlah;
    do{
        if(info_hewan(PM).jumlah < mins){
            mins = info_hewan(PM).jumlah;
        }
        PM = next_hewan(PM);
    }while (next_hewan(PM) != first_hewan(LM));

    PM=first_hewan(LM);
    do{
        if(info_hewan(PM).jumlah == mins){
            return PM;
        }
        PM = next_hewan(PM);
    }while (next_hewan(PM) != first_hewan(LM));
}

void data_relasi (List_relasi &L, List_hewan LM, List_jadwal LJ){
    address_relasi P;

    address_hewan PM;
    address_jadwal PJ;

    PM=findElm_hewan(LM, "GAJAH");
    PJ=findElm_jadwal(LJ, "08-02-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "ORANG UTAN");
    PJ=findElm_jadwal(LJ, "08-02-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "SALMON");
    PJ=findElm_jadwal(LJ, "08-02-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "GAJAH");
    PJ=findElm_jadwal(LJ, "08-02-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "KADAL");
    PJ=findElm_jadwal(LJ, "17-02-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "GAJAH");
    PJ=findElm_jadwal(LJ, "17-02-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "SALMON");
    PJ=findElm_jadwal(LJ, "25-07-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "KADAL");
    PJ=findElm_jadwal(LJ, "17-02-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "KANGGURU");
    PJ=findElm_jadwal(LJ, "25-07-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "BURUNG MERAK");
    PJ=findElm_jadwal(LJ, "18-09-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "BURUNG MERAK");
    PJ=findElm_jadwal(LJ, "08-02-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_hewan(LM, "SALMON");
    PJ=findElm_jadwal(LJ, "12-12-2018");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);
}
