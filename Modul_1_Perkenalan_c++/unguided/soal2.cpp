#include <iostream>
using namespace std;

string satuan(int x){
    switch (x) {
        case 0: return "nol";
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
        default: return "";
    }
}

int main(){
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
        return 0;
    }

    string hasil;
    if (angka == 0) {
        hasil = "nol";
    } else if (angka == 10) {
        hasil = "sepuluh";
    } else if (angka == 11) {
        hasil = "sebelas";
    } else if (angka >= 12 && angka < 20) {
        hasil = satuan(angka % 10) + " belas";
    } else if (angka >= 20 && angka < 100) {
        int p = angka / 10;
        int s = angka % 10;
        hasil = satuan(p) + " puluh";
        if (s != 0) hasil += " " + string(satuan(s));
    } else if (angka == 100) {
        hasil = "seratus";
    } else { 
        hasil = satuan(angka);
    }

    cout << angka << " : " << hasil << endl;
    return 0;
}