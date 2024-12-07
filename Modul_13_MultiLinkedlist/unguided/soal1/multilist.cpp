#include "multilist.h"
#include <iostream>
using namespace std;

bool ListEmpty(listinduk parentList) {
    return parentList.first == Nil;
}

bool ListEmptyAnak(listanak childList) {
    return childList.first == Nil;
}

void CreateList(listinduk &parentList) {
    parentList.first = Nil;
    parentList.last = Nil;
}

void CreateListAnak(listanak &childList) {
    childList.first = Nil;
    childList.last = Nil;
}

address alokasi(infotypeinduk value) {
    address node = new elemen_list_induk;
    if (node != Nil) {
        node->info = value;
        CreateListAnak(node->lanak);
        node->next = Nil;
        node->prev = Nil;
    }
    return node;
}

address_anak alokasiAnak(infotypeanak value) {
    address_anak node = new elemen_list_anak;
    if (node != Nil) {
        node->info = value;
        node->next = Nil;
        node->prev = Nil;
    }
    return node;
}

void dealokasi(address &node) {
    delete node;
    node = Nil;
}

void dealokasiAnak(address_anak &node) {
    delete node;
    node = Nil;
}

address findElm(listinduk parentList, infotypeinduk value) {
    address curr = parentList.first;
    while (curr != Nil) {
        if (curr->info == value) {
            return curr;
        }
        curr = curr->next;
    }
    return Nil;
}

address_anak findElmAnak(listanak childList, infotypeanak value) {
    address_anak curr = childList.first;
    while (curr != Nil) {
        if (curr->info == value) {
            return curr;
        }
        curr = curr->next;
    }
    return Nil;
}

void insertFirst(listinduk &parentList, address node) {
    if (ListEmpty(parentList)) {
        parentList.first = node;
        parentList.last = node;
    } else {
        node->next = parentList.first;
        parentList.first->prev = node;
        parentList.first = node;
    }
}

void insertLast(listinduk &parentList, address node) {
    if (ListEmpty(parentList)) {
        parentList.first = node;
        parentList.last = node;
    } else {
        parentList.last->next = node;
        node->prev = parentList.last;
        parentList.last = node;
    }
}

void insertFirstAnak(listanak &childList, address_anak node) {
    if (ListEmptyAnak(childList)) {
        childList.first = node;
        childList.last = node;
    } else {
        node->next = childList.first;
        childList.first->prev = node;
        childList.first = node;
    }
}

void insertLastAnak(listanak &childList, address_anak node) {
    if (ListEmptyAnak(childList)) {
        childList.first = node;
        childList.last = node;
    } else {
        childList.last->next = node;
        node->prev = childList.last;
        childList.last = node;
    }
}

void delFirst(listinduk &parentList, address &node) {
    if (!ListEmpty(parentList)) {
        node = parentList.first;
        if (parentList.first == parentList.last) {
            parentList.first = Nil;
            parentList.last = Nil;
        } else {
            parentList.first = parentList.first->next;
            parentList.first->prev = Nil;
            node->next = Nil;
        }
    }
}

void delLast(listinduk &parentList, address &node) {
    if (!ListEmpty(parentList)) {
        node = parentList.last;
        if (parentList.first == parentList.last) {
            parentList.first = Nil;
            parentList.last = Nil;
        } else {
            parentList.last = parentList.last->prev;
            parentList.last->next = Nil;
            node->prev = Nil;
        }
    }
}

void delP(listinduk &parentList, infotypeinduk value) {
    address target = findElm(parentList, value);
    if (target != Nil) {
        address_anak child;
        while (!ListEmptyAnak(target->lanak)) {
            delFirstAnak(target->lanak, child);
            dealokasiAnak(child);
        }

        if (target == parentList.first) {
            delFirst(parentList, target);
        } else if (target == parentList.last) {
            delLast(parentList, target);
        } else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
        dealokasi(target);
    }
}

void delFirstAnak(listanak &childList, address_anak &node) {
    if (!ListEmptyAnak(childList)) {
        node = childList.first;
        if (childList.first == childList.last) {
            childList.first = Nil;
            childList.last = Nil;
        } else {
            childList.first = childList.first->next;
            childList.first->prev = Nil;
            node->next = Nil;
        }
    }
}

void delLastAnak(listanak &childList, address_anak &node) {
    if (!ListEmptyAnak(childList)) {
        node = childList.last;
        if (childList.first == childList.last) {
            childList.first = Nil;
            childList.last = Nil;
        } else {
            childList.last = childList.last->prev;
            childList.last->next = Nil;
            node->prev = Nil;
        }
    }
}

void delPAnak(listanak &childList, infotypeanak value) {
    address_anak target = findElmAnak(childList, value);
    if (target != Nil) {
        if (target == childList.first) {
            delFirstAnak(childList, target);
        } else if (target == childList.last) {
            delLastAnak(childList, target);
        } else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
        dealokasiAnak(target);
    }
}

void printInfoAnak(listanak childList) {
    if (ListEmptyAnak(childList)) {
        cout << "-";
    } else {
        address_anak curr = childList.first;
        while (curr != Nil) {
            cout << curr->info;
            if (curr->next != Nil) cout << ", ";
            curr = curr->next;
        }
    }
}

void printInfo(listinduk parentList) {
    if (ListEmpty(parentList)) {
        cout << "List kosong" << endl;
    } else {
        address curr = parentList.first;
        while (curr != Nil) {
            cout << "Pegawai " << curr->info << ": ";
            printInfoAnak(curr->lanak);
            cout << endl;
            curr = curr->next;
        }
    }
}

int nbList(listinduk parentList) {
    int count = 0;
    address curr = parentList.first;
    while (curr != Nil) {
        count++;
        curr = curr->next;
    }
    return count;
}

int nbListAnak(listanak childList) {
    int count = 0;
    address_anak curr = childList.first;
    while (curr != Nil) {
        count++;
        curr = curr->next;
    }
    return count;
}

void delAll(listinduk &parentList) {
    address node;
    while (!ListEmpty(parentList)) {
        delFirst(parentList, node);
        address_anak child;
        while (!ListEmptyAnak(node->lanak)) {
            delFirstAnak(node->lanak, child);
            dealokasiAnak(child);
        }
        dealokasi(node);
    }
}
