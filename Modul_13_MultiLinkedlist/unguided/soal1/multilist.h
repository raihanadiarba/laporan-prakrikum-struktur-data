#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef int infotypeanak;
typedef int infotypeinduk;
typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak {
    address_anak first;
    address_anak last;
};

struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak;
    address next;
    address prev;
};

struct listinduk {
    address first;
    address last;
};

bool ListEmpty(listinduk parentList);
bool ListEmptyAnak(listanak childList);

void CreateList(listinduk &parentList);
void CreateListAnak(listanak &childList);


address alokasi(infotypeinduk value);
address_anak alokasiAnak(infotypeanak value);
void dealokasi(address &node);
void dealokasiAnak(address_anak &node);

address findElm(listinduk parentList, infotypeinduk value);
address_anak findElmAnak(listanak childList, infotypeanak value);

void insertFirst(listinduk &parentList, address node);
void insertLast(listinduk &parentList, address node);

void insertFirstAnak(listanak &childList, address_anak node);
void insertLastAnak(listanak &childList, address_anak node);

void delFirst(listinduk &parentList, address &node);
void delLast(listinduk &parentList, address &node);
void delP(listinduk &parentList, infotypeinduk value);

void delFirstAnak(listanak &childList, address_anak &node);
void delLastAnak(listanak &childList, address_anak &node);
void delPAnak(listanak &childList, infotypeanak value);

void printInfo(listinduk parentList);
void printInfoAnak(listanak childList);
int nbList(listinduk parentList);
int nbListAnak(listanak childList);
void delAll(listinduk &parentList);

#endif
