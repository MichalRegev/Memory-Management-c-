#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"
class Party;
int MandatesSelectionPolicy::theChosenParty(Graph &graph, int coalitionNum,int partyId,Simulation &sim)
{ 
    int theChosen = -1;
    int maxMandates = -1;
    for (int i = 0; i < graph.getNumVertices(); i++) //check all the parties
    {
        if (graph.getEdgeWeight(partyId, i) > 0) //check if the edge is exist
        {
            Party currParty = graph.getPartyE(i);
            if (currParty.getState() == Waiting || currParty.getState() == CollectingOffers)
            {
                bool sameCoal = false;
                for (unsigned int j = 0; (j < (currParty.getOffers()).size()) & (!sameCoal); j++) { //check if the party didnt get offer from the same coalition
                    if (sim.getAgents()[(currParty.getOffers())[j]].getCoalition() == coalitionNum)
                        sameCoal = true;
                }
                if (!sameCoal)
                {
                    if (maxMandates < (graph.getParty(i)).getMandates()) //search for the max mandates party
                    {
                        maxMandates = (graph.getParty(i)).getMandates();
                        theChosen = currParty.getId();
                    }
                }
            }
        }
    }
    return theChosen;
}

 SelectionPolicy* MandatesSelectionPolicy::info () {
        return new MandatesSelectionPolicy();
    }

int EdgeWeightSelectionPolicy::theChosenParty(Graph &graph,  int coalitionNum,int partyId, Simulation &sim)
{
    int theChosen = -1;
    int maxWeight = -1;
    for (int i = 0; i < graph.getNumVertices(); i++) //check all the parties
    {
        if (graph.getEdgeWeight(partyId, i) > 0) //check if the edge is exist
        {
            Party currParty = graph.getPartyE(i);
            if (currParty.getState() == Waiting || currParty.getState() == CollectingOffers)
            {
                bool sameCoal = false;
                for (unsigned int j = 0; (j < (currParty.getOffers()).size()) & (!sameCoal); j++) //check if the party didnt get offer from the same coalition
                {
                    if (sim.getAgents()[(currParty.getOffers())[j]].getCoalition()== coalitionNum)
                        sameCoal = true;
                }
                if (!sameCoal)
                {
                    int currWeight = graph.getEdgeWeight(partyId, i);  
                    if (maxWeight < currWeight) //search for the max edge party
                    {
                        maxWeight = currWeight;
                        theChosen = currParty.getId();
                    }
                }
            }
        }
    }
    return theChosen;
}

    SelectionPolicy* EdgeWeightSelectionPolicy::info () {
        return new EdgeWeightSelectionPolicy();
    }

     


