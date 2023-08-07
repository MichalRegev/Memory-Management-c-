//#pragma once
#ifndef SELECTIONPOLICY_H
#define SELECTIONPOLICY_H
#include "Graph.h"
#include "Party.h"

class SelectionPolicy
{
public:
    virtual int theChosenParty(Graph &graph, int coalitionNum,int partyId, Simulation &sim) = 0;
    virtual  SelectionPolicy* info () =0;
    virtual ~SelectionPolicy()=default;
};

class MandatesSelectionPolicy : public SelectionPolicy
{
public:
    int theChosenParty(Graph &graph, int coalitionNum,int partyId,Simulation &sim);
    SelectionPolicy* info ();
    virtual ~MandatesSelectionPolicy()=default;
};

class EdgeWeightSelectionPolicy : public SelectionPolicy
{
public:
    int theChosenParty(Graph &graph,  int coalitionNum,int partyId,Simulation &sim);
    SelectionPolicy* info ();
    virtual ~EdgeWeightSelectionPolicy()=default;
};
#endif