#include "../include/Simulation.h"
#include "../include/Graph.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : CoalitionVector(), mGraph(graph), mAgents(agents), maxMandates(0), allJoined(false)
{
    vector<int> tmpCoalitionVector;
    for (unsigned int c = 0; c < mAgents.size(); c++) //checks all the agents. the num of agents in the beginning is equal to the num of coalitions
    {
        int partyIndex = mAgents[c].getPartyId();
        Party currParty = getPartyE(partyIndex);
        currParty.setCoalition(c);
        mAgents[c].setCoalition(c);
        tmpCoalitionVector.push_back(currParty.getMandates());
        if (currParty.getMandates() > maxMandates) //update the global max mandates
            maxMandates = currParty.getMandates();
    }
    CoalitionVector = tmpCoalitionVector; //in each index will be the num of mandates of the coalition
    if (mGraph.getNumVerticesU() == mAgents.size())
        allJoined = true;
}

void Simulation::step()
{
    for (int i = 0; i < mGraph.getNumVertices(); i++)
    {
        (mGraph.getPartyE(i)).step(*this);
    }
    for (vector<Agent>::iterator itr = mAgents.begin(); itr != mAgents.end(); ++itr)
    {
        itr->step(*this);
    }
    allJoined = true;
    for (int i = 0; (i < mGraph.getNumVertices()) & (allJoined); i++)
    {
        if (mGraph.getParty(i).getState() == CollectingOffers || mGraph.getParty(i).getState() == Waiting)
        {
            allJoined = false;
        }
    }
}

bool Simulation::shouldTerminate() const
{
    if ((maxMandates >= 61) | allJoined)
        return true;
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}
Graph &Simulation::getGraph()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

vector<Agent> &Simulation::getAgentsE()
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party &Simulation::getPartyE(int partyId)
{
    return mGraph.getPartyE(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> vectorCoalitions; 
    for (unsigned int i = 0; i < CoalitionVector.size(); i++) 
    {
        vector<int> v;
        vectorCoalitions.push_back(v);
    }
    for (unsigned int a = 0; a < mAgents.size(); a++)
    {
        int coalitionNum = (mAgents[a]).getCoalition();
        vectorCoalitions[coalitionNum].push_back(mAgents[a].getPartyId());
    }
    return vectorCoalitions;
}

void Simulation::setMaxMandates(int max)
{
    maxMandates = max;
}

int Simulation::getMaxMandates()
{
    return maxMandates;
}
void Simulation::setAllJoined(bool allJoinedNow)
{
    allJoined = allJoinedNow;
}

vector <int> &Simulation::getCoalitionVector(){
    return CoalitionVector;
}
