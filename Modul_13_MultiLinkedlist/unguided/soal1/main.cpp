#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    listinduk parentList;
    address parentNode;
    address_anak childNode;

    CreateList(parentList);

    cout << "Demo Multi Linked List" << endl;

    cout << "\n1) Tambah pegawai" << endl;
    parentNode = alokasi(1);
    insertLast(parentList, parentNode);

    parentNode = alokasi(2);
    insertLast(parentList, parentNode);

    parentNode = alokasi(3);
    insertLast(parentList, parentNode);

    cout << "\n2) Tambah anak untuk pegawai 1" << endl;
    parentNode = findElm(parentList, 1);
    if (parentNode != Nil) {
        childNode = alokasiAnak(101);
        insertLastAnak(parentNode->lanak, childNode);

        childNode = alokasiAnak(102);
        insertLastAnak(parentNode->lanak, childNode);

        childNode = alokasiAnak(103);
        insertLastAnak(parentNode->lanak, childNode);
    }

    cout << "\n3) Tambah anak untuk pegawai 2" << endl;
    parentNode = findElm(parentList, 2);
    if (parentNode != Nil) {
        childNode = alokasiAnak(201);
        insertLastAnak(parentNode->lanak, childNode);

        childNode = alokasiAnak(202);
        insertLastAnak(parentNode->lanak, childNode);
    }

    cout << "\n4) Tampilkan data" << endl;
    printInfo(parentList);

    cout << "\n5) Hapus anak 102 dari pegawai 1" << endl;
    parentNode = findElm(parentList, 1);
    if (parentNode != Nil) {
        delPAnak(parentNode->lanak, 102);
    }
    printInfo(parentList);

    cout << "\n6) Hapus pegawai 1 beserta anaknya" << endl;
    delP(parentList, 1);
    printInfo(parentList);

    cout << "\n7) Jumlah data" << endl;
    cout << "Pegawai: " << nbList(parentList) << endl;
    parentNode = findElm(parentList, 2);
    if (parentNode != Nil) {
        cout << "Anak pegawai 2: " << nbListAnak(parentNode->lanak) << endl;
    }

    cout << "\n8) Hapus semua data" << endl;
    delAll(parentList);
    printInfo(parentList);

    return 0;
}
