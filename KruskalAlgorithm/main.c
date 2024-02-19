#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "func.h"

int main(void) {
    int sizeGraph;
    if (scanf("%d", &sizeGraph) == -1) {
        printf("bad number of lines");
        return 0;
    }
    if (sizeGraph == 0) {
        printf("no spanning tree");
        return 0;
    }
    if (sizeGraph > 5000 || sizeGraph < 0) {
        printf("bad number of vertices");
        return 0;
    }
    int countEdge;
    if (scanf("%d", &countEdge) == -1) {
        printf("bad number of lines");
        return 0;
    }
    if (sizeGraph == 1 && countEdge == 0) {
        return 0;
    }
    if (countEdge < 0 || countEdge > sizeGraph * (sizeGraph + 1) / 2) {
        printf("bad number of edges");
        return 0;
    }
    if (countEdge < sizeGraph - 1) {
        printf("no spanning tree");
        return 0;
    }
    struct TTree* nodes = (struct TTree*)malloc((sizeGraph - 1) * sizeof(struct TTree));
    struct TEdges* edges = (struct TEdges*)malloc(countEdge * sizeof(struct TEdges));
    for (int i = 0; i < countEdge; ++i) {
        if (scanf("%d %d %d", &edges[i].StartPoint, &edges[i].EndPoint, &edges[i].Weight) < 3) {
            printf("bad number of lines");
            free(edges);
            free(nodes);
            return 0;
        }
        if (edges[i].Weight < 0) {
            printf("bad length");
            free(edges);
            free(nodes);
            return 0;   
        }
        if (edges[i].StartPoint > sizeGraph || edges[i].StartPoint < 0 || edges[i].EndPoint > sizeGraph || edges[i].EndPoint < 0) {
            printf("bad vertex");
            free(edges);
            free(nodes);
            return 0;
        }
    }
    qsort(edges, countEdge, sizeof(struct TEdges), cmp);
    int* parent = (int*)malloc(sizeGraph * sizeof(int));
    int* rank = (int*)malloc(sizeGraph * sizeof(int));
    for (int i = 0; i < sizeGraph; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
    int countEdges = 0;
    for (int i = 0; i < countEdge; ++i) {
        int start = Find(parent, edges[i].StartPoint - 1);
        int end = Find(parent, edges[i].EndPoint - 1);
        if (end != start) {
            nodes[countEdges].StartPoint = edges[i].StartPoint;
            nodes[countEdges].EndPoint = edges[i].EndPoint;
            Union(parent, rank, start, end );
            ++countEdges;
            if (countEdges == sizeGraph - 1) {
                break;
            }
        }
    }
    if (countEdges != sizeGraph - 1) {
        printf("no spanning tree");
    }
    else {
        for (int i = 0; i < sizeGraph - 1; ++i) {
            printf("%d %d\n", nodes[i].StartPoint, nodes[i].EndPoint);
        }
    }
    free(parent);
    free(rank);
    free(edges);
    free(nodes);
    return 0;
}
