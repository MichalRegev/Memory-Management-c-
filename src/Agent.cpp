#include "../include/Agent.h"
#include "../include/Simulation.h"
#include <vector>
#include <iostream>


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), coalition(-1)
{
}
Agent::Agent(int agentId, int partyId,  SelectionPolicy* selectionPolicy,int c):mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), coalition(c) {
//constructor for clone agent
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    int theChosen = mSelectionPolicy->theChosenParty(sim.getGraph(), coalition, mPartyId, sim);
    if (theChosen != -1) 
    {
        (sim.getPartyE(theChosen)).getOffers().push_back(mAgentId);
        if (sim.getPartyE(theChosen).getState() == Waiting) //update the party state
            sim.getPartyE(theChosen).setState(CollectingOffers);
    }
}



void Agent::setCoalition(int c)
{
    coalition = c;
}

int Agent::getCoalition() const
{
    return coalition;
}


SelectionPolicy *Agent::getSelectionPolicyb()
{
    return mSelectionPolicy;
}

Agent::~Agent() //destructor
{
    if (mSelectionPolicy)
        delete mSelectionPolicy;
}

Agent::Agent(const Agent &other):mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy->info()),coalition(other.coalition)
{
    //copy constructor
}

Agent &Agent::operator=(const Agent &other) //copy assingment operator
{
    if (this != &other)
    {
        mAgentId=other.mAgentId;
        mPartyId=other.mPartyId;
        coalition = other.coalition;
        mSelectionPolicy= other.mSelectionPolicy->info();
    }
    return *this;
}

Agent::Agent(Agent &&other) : mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy),coalition(other.coalition) //move cobstructor
{
    other.mSelectionPolicy = nullptr;
}

Agent &Agent ::operator=(Agent &&other) //move assingnment operator
{
    if(this!=&other){
    if (mSelectionPolicy)
        delete mSelectionPolicy;
    coalition = other.coalition;
    mSelectionPolicy = other.mSelectionPolicy;
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    other.mSelectionPolicy = nullptr;
    }
    return *this;

}
