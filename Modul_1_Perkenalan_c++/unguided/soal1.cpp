#include <iostream>
using namespace std;

float penjumlahan(float x, float y){
    return x + y;
}

float pengurangan(float x, float y){
    return x - y;
}

float perkalian(float x, float y){
    return x * y;
}

float pembagian(float x, float y){
    if (y != 0) {
        return x / y;
    } else {
        cout << "Error: Pembagian dengan 0 tidak diperbolehkan!" << endl;
        return 0; 
    }
}

int main(){
    float a, b;

    cout << "Masukkan angka pertama : ";
    cin >> a;
    cout << "Masukkan angka kedua : ";
    cin >> b;

    cout << "Hasil Penjumlahan : " << penjumlahan(a,b) << endl;
    cout << "Hasil Pengurangan : " << pengurangan(a,b) << endl;
    cout << "Hasil Perkalian   : " << perkalian(a,b) << endl;
    cout << "Hasil Pembagian   : " << pembagian(a,b) << endl;

    return 0;
}