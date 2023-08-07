//#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "Party.h"

using std::vector;
class Simulation;
class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    unsigned int getNumVerticesU() const;
    const Party &getParty(int partyId) const;
    Party &getPartyE(int partyId);
private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
#endif