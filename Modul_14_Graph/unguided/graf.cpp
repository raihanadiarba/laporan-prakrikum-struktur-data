#include "graf.h"
#include <iostream>
#include <queue>

namespace {
// Penanda status kunjungan untuk keterbacaan
constexpr int UNVISITED = 0;
constexpr int VISITED = 1;
}

void initGraph(Graph &G) {
    G.firstVertex = nullptr;
}

ptrVertex alokasiVertex(charInfo data) {
    ptrVertex V = new Vertex;
    V->id = data;
    V->status = UNVISITED;
    V->nextVertex = nullptr;
    V->firstIncidentEdge = nullptr;
    return V;
}

ptrEdge alokasiEdge(ptrVertex tujuan) {
    ptrEdge E = new Edge;
    E->destVertex = tujuan;
    E->nextEdge = nullptr;
    return E;
}

void addVertex(Graph &G, charInfo data) {
    ptrVertex V = alokasiVertex(data);
    
    if (G.firstVertex == nullptr) {
        G.firstVertex = V;
    } else {
        ptrVertex walker = G.firstVertex;
        for (; walker->nextVertex != nullptr; walker = walker->nextVertex) {}
        walker->nextVertex = V;
    }
}

ptrVertex searchVertex(Graph G, charInfo data) {
    for (ptrVertex p = G.firstVertex; p != nullptr; p = p->nextVertex) {
        if (p->id == data) return p;
    }
    return nullptr;
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
    for (ptrVertex v = G.firstVertex; v != nullptr; v = v->nextVertex) {
        std::cout << "[" << v->id << "] terhubung ke -> ";
        
        ptrEdge e = v->firstIncidentEdge;
        if (e == nullptr) std::cout << "(tidak ada)";
        
        while (e != nullptr) {
            std::cout << e->destVertex->id << " ";
            e = e->nextEdge;
        }
        std::cout << std::endl;
    }
}

void resetStatus(Graph G) {
    for (ptrVertex p = G.firstVertex; p != nullptr; p = p->nextVertex) {
        p->status = UNVISITED;
    }
}

void runDFS(ptrVertex V) {
    if (V->status == VISITED) return;

    V->status = VISITED;
    std::cout << V->id << " ";

    ptrEdge e = V->firstIncidentEdge;
    while (e != nullptr) {
        if (e->destVertex->status == UNVISITED) {
            runDFS(e->destVertex);
        }
        e = e->nextEdge;
    }
}

void executeDFS(Graph G, ptrVertex startV) {
    if (startV == nullptr) return;
    
    resetStatus(G);
    std::cout << "DFS Traversal: ";
    runDFS(startV);
    std::cout << std::endl;
}

void executeBFS(Graph G, ptrVertex startV) {
    if (startV == nullptr) return;

    resetStatus(G);
    std::cout << "BFS Traversal: ";

    std::queue<ptrVertex> q;

    startV->status = VISITED;
    q.push(startV);

    while (!q.empty()) {
        ptrVertex current = q.front();
        q.pop();
        std::cout << current->id << " ";

        for (ptrEdge e = current->firstIncidentEdge; e != nullptr; e = e->nextEdge) {
            if (e->destVertex->status == UNVISITED) {
                e->destVertex->status = VISITED;
                q.push(e->destVertex);
            }
        }
    }
    std::cout << std::endl;
}
