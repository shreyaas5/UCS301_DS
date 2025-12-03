#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, wt;
};

struct Subset {
    int parent;
    int rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareEdge(Edge a, Edge b) {
    return a.wt < b.wt;
}

void KruskalMST(Edge edges[], int V, int E) {
    sort(edges, edges + E, compareEdge);

    Subset *subsets = new Subset[V];

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    cout << "Edges in MST:\n";
    int e = 0, i = 0;

    while (e < V - 1 && i < E) {
        Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        if (x != y) {
            cout << next.src << " -- " << next.dest << " == " << next.wt << "\n";
            Union(subsets, x, y);
            e++;
        }
    }

    delete[] subsets;
}
