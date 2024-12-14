# <h1 align="center">Laporan Praktikum Modul 14 <br>Graph</h1>

<p align="center">Raihan Adi Arba - 103112400071</p>

## Dasar Teori

Graph atau graf adalah struktur data non-linear yang terdiri dari sekumpulan simpul (node/vertex) dan sisi (edge) yang menghubungkan simpul-simpul tersebut. Graph digunakan untuk merepresentasikan hubungan antar objek, seperti jaringan sosial, peta jalan, atau jaringan komputer.

### Jenis-jenis Graph:

1. **Graph Berarah (Directed Graph)**: Edge memiliki arah dari satu node ke node lainnya.
2. **Graph Tidak Berarah (Undirected Graph)**: Edge tidak memiliki arah; hubungan bersifat dua arah.
3. **Graph Berbobot (Weighted Graph)**: Setiap edge memiliki nilai/bobot tertentu.
4. **Graph Tidak Berbobot (Unweighted Graph)**: Edge tidak memiliki bobot.

### Representasi Graph:

1. **Adjacency List**: Menggunakan linked list untuk menyimpan tetangga dari setiap node.
2. **Adjacency Matrix**: Menggunakan matriks untuk merepresentasikan hubungan antar node.

### Traversal Graph:

1. **DFS (Depth First Search)**: Penelusuran secara mendalam, menggunakan stack atau rekursi.
2. **BFS (Breadth First Search)**: Penelusuran secara melebar, menggunakan queue.

## Guided

### Implementasi Graph dengan Adjacency List

#### graf.h

```cpp
#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode *adrNode;
typedef ElmEdge *adrEdge;

struct ElmNode
{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge
{
    adrNode node;
    adrEdge next;
};

struct Graph
{
    adrNode first;
};

// PRIMITIF GRAPH
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);

void ConnectNode(Graph &G, infoGraph A, infoGraph B);

void PrintInfoGraph(Graph G);

// Traversal
void ResetVisited(Graph &G);
void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);

#endif
```

#### graf.cpp

```cpp
#include "graf.h"
#include <queue>
#include <stack>

void CreateGraph(Graph &G)
{
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X)
{
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N)
{
    adrEdge P = new ElmEdge;
    P->node = N;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph X)
{
    adrNode P = AllocateNode(X);
    P->next = G.first;
    G.first = P;
}

adrNode FindNode(Graph G, infoGraph X)
{
    adrNode P = G.first;
    while (P != NULL)
    {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph A, infoGraph B)
{
    adrNode N1 = FindNode(G, A);
    adrNode N2 = FindNode(G, B);

    if (N1 == NULL || N2 == NULL)
    {
        cout << "Node tidak ditemukan!\n";
        return;
    }

    // Buat edge dari N1 ke N2
    adrEdge E1 = AllocateEdge(N2);
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    // Karena undirected → buat edge balik
    adrEdge E2 = AllocateEdge(N1);
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G)
{
    adrNode P = G.first;
    while (P != NULL)
    {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL)
        {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void ResetVisited(Graph &G)
{
    adrNode P = G.first;
    while (P != NULL)
    {
        P->visited = 0;
        P = P->next;
    }
}

void PrintDFS(Graph &G, adrNode N)
{
    if (N == NULL)
        return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL)
    {
        if (E->node->visited == 0)
        {
            PrintDFS(G, E->node);
        }
        E = E->next;
    }
}

void PrintBFS(Graph &G, adrNode N)
{
    if (N == NULL)
        return;

    queue<adrNode> Q;
    Q.push(N);

    while (!Q.empty())
    {
        adrNode curr = Q.front();
        Q.pop();

        if (curr->visited == 0)
        {
            curr->visited = 1;
            cout << curr->info << " ";

            adrEdge E = curr->firstEdge;
            while (E != NULL)
            {
                if (E->node->visited == 0)
                {
                    Q.push(E->node);
                }
                E = E->next;
            }
        }
    }
}
```

#### main.cpp

```cpp
#include "graf.h"
#include <iostream>
using namespace std;

int main()
{
    Graph G;
    CreateGraph(G);

    // Tambah node
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');

    // Hubungkan node (graph tidak berarah)
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'C', 'E');

    cout << "=== Struktur Graph ===\n";
    PrintInfoGraph(G);

    cout << "\n=== DFS dari Node A ===\n";
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));

    cout << "\n\n=== BFS dari Node A ===\n";
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));

    cout << endl;
    return 0;
}
```

> ![Screenshot guided](output/Screenshot_Guided.png)

### Penjelasan Program:

Pada program guided ini, saya mengimplementasikan graph menggunakan teknik adjacency list. Intinya, graph yang saya buat adalah undirected graph; artinya kalau ada koneksi dari node A ke B, otomatis B juga terhubung ke A.

Programnya dibagi jadi 3 file utama. Pertama ada graf.h yang isinya deklarasi struct dan fungsi-fungsi. Di sini ada struct ElmNode buat nyimpan data node seperti info, status visited, pointer ke edge pertama, dan pointer ke node berikutnya. Ada juga ElmEdge buat nyimpen koneksi antar node.

Selanjutnya, di graf.cpp saya implementasikan semua fungsinya. Ada CreateGraph() buat inisialisasi graph kosong; AllocateNode() dan AllocateEdge() buat bikin node dan edge baru; InsertNode() buat nambahin node ke graph; FindNode() buat nyari node tertentu; dan ConnectNode() buat nyambungin dua node. Karena graph-nya undirected, ConnectNode() otomatis bikin edge dua arah. Ada juga PrintInfoGraph() buat nampilin struktur graph, plus fungsi-fungsi traversal: PrintDFS() (pakai rekursi) dan PrintBFS() (pakai queue).

Di main.cpp, saya bikin graph dengan 5 node (A sampai E). Setelah semua node ditambahkan, saya hubungkan dengan beberapa edge. Misalnya A terhubung ke B dan C, B ke D, dan C ke E. Setelah itu, program menampilkan struktur graph dalam bentuk adjacency list.

Untuk traversal DFS, algoritmanya jalan secara rekursif: kunjungi satu node, tandai sebagai visited, lalu lanjut ke tetangganya yang belum dikunjungi. Hasilnya A B D C E, karena DFS memprioritaskan penelusuran sedalam-dalamnya dulu sebelum backtrack.

Sedangkan BFS menggunakan queue: mulai dari node awal, masukkan semua tetangganya ke queue, lalu proses satu per satu secara berurutan. Hasilnya A B C D E, karena BFS memproses per level—melebar dulu baru ke level berikutnya.

## Unguided

### Implementasi Graph dengan 8 Vertex dan Traversal DFS & BFS

#### graf.h

```cpp
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using namespace std;

typedef char charInfo;
typedef struct Vertex *ptrVertex;
typedef struct Edge *ptrEdge;

struct Vertex {
    charInfo id;
    int status;
    ptrEdge firstIncidentEdge;
    ptrVertex nextVertex;
};

struct Edge {
    ptrVertex destVertex;
    ptrEdge nextEdge;
};

struct Graph {
    ptrVertex firstVertex;
};

void initGraph(Graph &G);
void addVertex(Graph &G, charInfo data);
void addEdge(ptrVertex v1, ptrVertex v2);
void showGraphData(Graph G);
void executeDFS(Graph G, ptrVertex startV);
void executeBFS(Graph G, ptrVertex startV);

ptrVertex searchVertex(Graph G, charInfo data);

#endif
```

#### graf.cpp

```cpp
#include "graf.h"
#include <iostream>

using namespace std;

struct NodeQ {
    ptrVertex val;
    NodeQ* next;
};

struct QueueList {
    NodeQ* head;
    NodeQ* tail;
};

void createQ(QueueList &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}

bool emptyQ(QueueList Q) {
    return (Q.head == NULL);
}

void enq(QueueList &Q, ptrVertex v) {
    NodeQ* baru = new NodeQ;
    baru->val = v;
    baru->next = NULL;

    if (emptyQ(Q)) {
        Q.head = baru;
        Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
}

ptrVertex deq(QueueList &Q) {
    if (emptyQ(Q)) return NULL;

    NodeQ* del = Q.head;
    ptrVertex out = del->val;

    Q.head = Q.head->next;
    if (Q.head == NULL) {
        Q.tail = NULL;
    }

    delete del;
    return out;
}

void initGraph(Graph &G) {
    G.firstVertex = NULL;
}

ptrVertex alokasiVertex(charInfo data) {
    ptrVertex V = new Vertex;
    V->id = data;
    V->status = 0;
    V->nextVertex = NULL;
    V->firstIncidentEdge = NULL;
    return V;
}

ptrEdge alokasiEdge(ptrVertex tujuan) {
    ptrEdge E = new Edge;
    E->destVertex = tujuan;
    E->nextEdge = NULL;
    return E;
}

void addVertex(Graph &G, charInfo data) {
    ptrVertex V = alokasiVertex(data);

    if (G.firstVertex == NULL) {
        G.firstVertex = V;
    } else {
        ptrVertex walker = G.firstVertex;
        for (; walker->nextVertex != NULL; walker = walker->nextVertex);
        walker->nextVertex = V;
    }
}

ptrVertex searchVertex(Graph G, charInfo data) {
    for (ptrVertex p = G.firstVertex; p != NULL; p = p->nextVertex) {
        if (p->id == data) return p;
    }
    return NULL;
}

void addEdge(ptrVertex v1, ptrVertex v2) {
    if (!v1 || !v2) return;

    ptrEdge eBaru1 = alokasiEdge(v2);
    eBaru1->nextEdge = v1->firstIncidentEdge;
    v1->firstIncidentEdge = eBaru1;

    ptrEdge eBaru2 = alokasiEdge(v1);
    eBaru2->nextEdge = v2->firstIncidentEdge;
    v2->firstIncidentEdge = eBaru2;
}

void showGraphData(Graph G) {
    for (ptrVertex v = G.firstVertex; v != NULL; v = v->nextVertex) {
        cout << "[" << v->id << "] terhubung ke -> ";

        ptrEdge e = v->firstIncidentEdge;
        if (e == NULL) cout << "(tidak ada)";

        while (e != NULL) {
            cout << e->destVertex->id << " ";
            e = e->nextEdge;
        }
        cout << endl;
    }
}

void resetStatus(Graph G) {
    for (ptrVertex p = G.firstVertex; p != NULL; p = p->nextVertex) {
        p->status = 0;
    }
}

void runDFS(ptrVertex V) {
    if (V->status == 1) return;

    V->status = 1;
    cout << V->id << " ";

    ptrEdge e = V->firstIncidentEdge;
    while (e != NULL) {
        if (e->destVertex->status == 0) {
            runDFS(e->destVertex);
        }
        e = e->nextEdge;
    }
}

void executeDFS(Graph G, ptrVertex startV) {
    if (startV == NULL) return;

    resetStatus(G);
    cout << "DFS Traversal: ";
    runDFS(startV);
    cout << endl;
}

void executeBFS(Graph G, ptrVertex startV) {
    if (startV == NULL) return;

    resetStatus(G);
    cout << "BFS Traversal: ";

    QueueList antrian;
    createQ(antrian);

    startV->status = 1;
    enq(antrian, startV);

    while (!emptyQ(antrian)) {
        ptrVertex current = deq(antrian);
        cout << current->id << " ";

        for (ptrEdge e = current->firstIncidentEdge; e != NULL; e = e->nextEdge) {
            if (e->destVertex->status == 0) {
                e->destVertex->status = 1;
                enq(antrian, e->destVertex);
            }
        }
    }
    cout << endl;
}
```

#### main.cpp

```cpp
#include "graf.h"
#include <iostream>

using namespace std;

int main() {
    Graph myGraph;
    initGraph(myGraph);

    char listV[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for(int i=0; i<8; i++){
        addVertex(myGraph, listV[i]);
    }

    ptrVertex vA = searchVertex(myGraph, 'A');
    ptrVertex vB = searchVertex(myGraph, 'B');
    ptrVertex vC = searchVertex(myGraph, 'C');
    ptrVertex vD = searchVertex(myGraph, 'D');
    ptrVertex vE = searchVertex(myGraph, 'E');
    ptrVertex vF = searchVertex(myGraph, 'F');
    ptrVertex vG = searchVertex(myGraph, 'G');
    ptrVertex vH = searchVertex(myGraph, 'H');

    addEdge(vA, vB); addEdge(vA, vC);
    addEdge(vB, vD); addEdge(vB, vE);
    addEdge(vC, vF); addEdge(vC, vG);
    addEdge(vD, vH); addEdge(vE, vH);
    addEdge(vF, vH); addEdge(vG, vH);

    showGraphData(myGraph);
    cout << endl;

    executeDFS(myGraph, vA);
    executeBFS(myGraph, vA);

    return 0;
}
```

> ![Screenshot unguided](output/Screenshot_Soal1.png)

### Penjelasan Program Unguided:

Untuk program unguided ini, saya bikin graph yang lebih kompleks dengan 8 vertex (A sampai H). Implementasinya sedikit berbeda dari guided, terutama di penamaan variabel dan cara kerja beberapa fungsinya.

Di graf.h, saya pakai struct Vertex yang punya field id, status buat tracking sudah dikunjungi atau belum, firstIncidentEdge sebagai pointer ke edge pertama, dan nextVertex buat nyambung ke vertex berikutnya. Struct Edge nyimpen pointer ke vertex tujuan dan pointer ke edge berikutnya.

Yang menarik di graf.cpp, saya bikin queue sendiri dari nol pakai linked list buat keperluan BFS. Ada struct NodeQ dan QueueList, lalu saya implementasikan fungsi-fungsi dasarnya: createQ() buat inisialisasi, emptyQ() buat ngecek kosong atau nggak, enq() buat masukin vertex, dan deq() buat ngeluarin vertex. Ini lebih menantang dibanding langsung pakai library queue dari STL, tapi bikin konsepnya lebih kebayang.

Untuk fungsi-fungsi graph: ada initGraph() buat inisialisasi; alokasiVertex() dan alokasiEdge() buat alokasi memori; addVertex() nambah vertex di akhir list; searchVertex() buat nyari vertex berdasarkan id; dan addEdge() yang nyambungin dua vertex secara dua arah. Fungsi showGraphData() dipakai buat nampilin adjacency list dari graph.

Di main.cpp, saya bikin graph dengan 8 vertex pakai loop. Terus saya cari semua vertex pakai searchVertex() dan hubungkan sesuai struktur yang diinginkan: A ke B dan C, B ke D dan E, C ke F dan G, sedangkan D, E, F, dan G semuanya terhubung ke H. Jadi H ini semacam titik pusat di level terakhir.

Ada beberapa perbedaan mendasar dibanding guided. Pertama, penamaan variabelnya lebih deskriptif (pakai ptrVertex dan ptrEdge). Kedua, saya bikin queue manual sendiri, bukan pakai library STL. Ketiga, vertex ditambahkan di akhir linked list, bukan di depan. Keempat, saya pakai field status alih-alih visited. Kelima, graph-nya lebih kompleks dengan 8 vertex dan lebih banyak edge.

Kalau dijalankan, program bakal nampilin struktur graph dulu, lalu hasil DFS dan BFS dari vertex A. DFS berjalan secara depth-first—masuk sedalam mungkin dulu sebelum backtrack. Sedangkan BFS berjalan level by level—proses semua vertex di satu level dulu sebelum lanjut ke level berikutnya. Jadi outputnya bakal beda walau graph yang di-traverse sama.

## Referensi

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
2. Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). Data Structures and Algorithms in C++ (2nd ed.). Wiley.
3. Sedgewick, R., & Wayne, K. (2011). Algorithms (4th ed.). Addison-Wesley Professional.
