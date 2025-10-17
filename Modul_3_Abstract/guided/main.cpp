#include "mahasiswa.h"
#include <iostream>
using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "\nRata-rata    = " << rata2(mhs) << endl;
    return 0;
}
