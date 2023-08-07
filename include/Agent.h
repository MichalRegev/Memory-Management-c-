
//#pragma once
#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include "SelectionPolicy.h"

class Simulation;
class Graph;
class Agent{

public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    int getCoalition()const;
    void setCoalition(int c);
    SelectionPolicy *getSelectionPolicyb();
    virtual ~Agent();
    Agent (const Agent &other);
    Agent& operator = (const Agent &other);
    Agent ( Agent&& other);
    Agent& operator = ( Agent&& other); 
    Agent(int agentId, int partyId, SelectionPolicy* selectionPolicy,int c);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int coalition;
    
};

#endif
