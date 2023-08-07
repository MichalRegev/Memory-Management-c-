//#pragma once
#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include "Agent.h"
#include "Graph.h"
using std::string;
using std::vector;

class Graph;
class Party;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    Graph &getGraph();
    const vector<Agent> &getAgents() const;
    vector<Agent> &getAgentsE() ;
    const Party &getParty(int partyId) const;
    Party &getPartyE(int partyId);
    const vector<vector<int>> getPartiesByCoalitions() const;
    void setMaxMandates (int max);
    int getMaxMandates ();
    void setAllJoined (bool allJoinedNow);
    ~Simulation(){ mAgents.clear(); };
    vector <int> &getCoalitionVector();

private:
    vector<int> CoalitionVector;
    Graph mGraph;
    vector<Agent> mAgents;
    int maxMandates;
    bool allJoined;
    
};
#endif
