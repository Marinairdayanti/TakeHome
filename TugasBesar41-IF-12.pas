program IndustriLokal;
uses crt;
type produk = record
        nama_perusahaan: string;
        nama_produk: string;
        lulus_ujiBPOM: integer;
        sertifikasi_halal: integer;
        omset_perbulan: integer;
        dataproduk: array of produk


end;

var
a : array of produk;
n: integer;
procedure inputDataProduk(jmlProduk: integer;var dProduk:array of produk);
var
        i: integer;
BEGIN
        for i:=1 to jmlProduk-1 do
        begin
                write('Nama Perusahaan : ');readln(dProduk[i].nama_perusahaan);
                write('Nama Produk : ');readln(dProduk[i].nama_produk);
                write('Lulus uji BPOM : ');readln(dProduk[i].lulus_ujiBPOM);
                write('Sertifikasi Halal : ');readln(dProduk[i].sertifikasi_halal);
                write('Omset perBulan : ');readln(dProduk[i].omset_perbulan);
                writeln;
        end;
end;

procedure outputDataProduk(jmlProduk: integer;var dProduk:array of produk);
var
        i: integer;
BEGIN
        for i:=1 to jmlProduk do
        begin
                write('Nama Perusahaan : ');readln(dProduk[i].nama_perusahaan);
                write('Nama Produk : ');readln(dProduk[i].nama_produk);
                write('Lulus uji BPOM : ');readln(dProduk[i].lulus_ujiBPOM);
                write('Sertifikasi Halal : ');readln(dProduk[i].sertifikasi_halal);
                write('Omset perBulan : ');readln(dProduk[i].omset_perbulan);
                writeln;
        end;
        readln;
end;

function persentase(jmlProduk,sertifikasiHalal: integer): real;
var
        hasilpersen: integer;
BEGIN
        jmlProduk:=3;
        sertifikasiHalal:=0;
        while(sertifikasiHalal<>1)do
        begin
                writeln(sertifikasiHalal);

        persentase:=(sertifikasihalal/jmlProduk)*100;
        end;
end;

procedure perusahaan(jmlProduk,sertifikatHalal: integer);
var
        keripikRenyah,renyahAbadi,lagenda: integer;
        makananRingan,hiasan: string;
BEGIN
        jmlProduk:=3;
        keripikRenyah:=0;
        lagenda:=0;
        renyahAbadi:=0;
        sertifikatHalal:=1;
        while(keripikRenyah <> 1)do
        begin
               if(keripikRenyah <> sertifikatHalal) and (RenyahAbadi = sertifikatHalal) and (lagenda<>sertifikatHalal)then
                        writeln(keripikRenyah = sertifikatHalal);readln(makananRingan);
                                keripikRenyah:=keripikRenyah+1;
                        writeln(renyahAbadi<> sertifikatHalal);readln(makananRingan);
                                renyahAbadi:=renyahAbadi;
                        writeln(lagenda = sertifikatHalal);readln(hiasan);
                                lagenda:=lagenda+1;
        end;           {keripikRenyah:=1 and renyahAbadi:=0 and lagenda:=1}
        readln;
end;

procedure gajiProduk(jmlProduk:integer;dProduk: array of produk);
var
i,ujiBPOM: integer;
omzetTinggi,omzetRendah: longint;
lagenda,keripikRenyah,renyahAbadi: string;

BEGIN
clrscr;
        writeln('Gaji Produk : ');readln(n);
        setlength(a,n);
        for i:=0 to jmlProduk do
        begin
                write('data',i+1,':');readln(n);
        end;

        ujiBPOM:=0;
        omzetTinggi:=0;
        omzetRendah:=0;


        for i:=1 to n-1 do
        begin
                ujiBPOM:=ujiBPOM+1;
                if (2500000>omzetTinggi) then
                      writeln(omzetTinggi =2500000);readln(lagenda);
                        if (1500000<omzetRendah) then
                        writeln(omzetRendah =1500000);readln(renyahAbadi);
                         if(omzetTinggi<>2000000) and (omzetRendah = 2000000)then
                                writeln(omzetTinggi<>2000000);readln(keripikRenyah);
                                writeln(omzetRendah<> 2000000);readln(keripikRenyah);

        end;

        writeln('ujiBPOM : ',ujiBPOM);
        writeln('omzetTinggi : ',omzetTinggi);
        writeln('omzetRendah : ',omzetRendah);

readln;
end;

procedure mengurutkan(jmlProduk: integer);
var
n,i,j,x,y: integer;
dProduk,dProduk2: array [1..3] of integer;

begin
clrscr;
        write('Masukkan banyak produk: ');readln(n);
        for i:= 1 to n do
        Begin
                write('keripikRenyah : ');readln(dProduk[i]);
                write('renyahAbadi : ');readln(dProduk[i]);
                write('lagenda : ');readln(dProduk[i]);
                dProduk2[i]:=dProduk[i];
        end;
        writeln;

        for i:= 1 to n do
        begin
                for j:=1 to n do
                if dProduk[i]>dProduk[j] then
                begin
                        x:=dProduk[i];
                        dProduk[i]:=dProduk[j];
                        dProduk[j]:=x;
                end;
        end;
        writeln;
readln;

BEGIN
clrscr;
        n:=3;
        setlength(a,n);
        inputDataProduk;
        outputDataProduk;
        hasilpersen := persentase(sertifikasihalal/jmlProduk)*100;
        writeln('hasil persen :',hasilpersen);
        perusahaan;
        gajiProduk;
        mengurutkan;
readln;
END.

