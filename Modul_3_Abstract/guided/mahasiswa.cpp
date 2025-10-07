#include "mahasiswa.h"
#include <iostream>
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM    : ";
    cin >> m.nim;

    cout << "Input Nilai1 : ";
    cin >> m.nilai1;

    cout << "Input Nilai2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}
