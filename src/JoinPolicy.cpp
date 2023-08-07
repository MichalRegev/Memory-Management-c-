#include "../include/JoinPolicy.h"
#include "../include/Agent.h"
#include "../include/Simulation.h"

  JoinPolicy* MandatesJoinPolicy::info ()  {
      return new MandatesJoinPolicy();
    }

void MandatesJoinPolicy::join(Simulation &sim, int partyId, vector<int> mOffers){
    Agent *theChosen_p  =&(sim.getAgentsE()[mOffers[0]]); //always will be at least one offer
    int maxMandates=sim.getCoalitionVector()[theChosen_p->getCoalition()];
    for (unsigned int a = 1; a < mOffers.size(); a++) //check all the party's offers
     {
         if (maxMandates < (sim.getCoalitionVector()[(sim.getAgentsE())[mOffers[a]].getCoalition()])){ //search for the max mandate coalition 
             theChosen_p= &(sim.getAgentsE()[mOffers[a]]);
             maxMandates =sim.getCoalitionVector()[(sim.getAgentsE())[mOffers[a]].getCoalition()];
        }
    }  
    Agent theChosen=*theChosen_p;        
    int myCoalitionMandates = sim.getCoalitionVector()[theChosen.getCoalition()];
    sim.getCoalitionVector()[theChosen.getCoalition()]=myCoalitionMandates+(sim.getGraph().getPartyE(partyId).getMandates()); //update the coalition mandates with the new party
    sim.getGraph().getPartyE(partyId).setState(Joined);
    sim.getGraph().getPartyE(partyId).setCoalition(theChosen.getCoalition());
    if (sim.getCoalitionVector()[theChosen.getCoalition()] > sim.getMaxMandates()) //update the global max mandates
        sim.setMaxMandates(myCoalitionMandates+ (sim.getGraph().getPartyE(partyId).getMandates()));
    Agent clonedAgent((sim.getAgents()).size(), partyId, theChosen.getSelectionPolicyb()->info(),theChosen.getCoalition() ); 
    (sim.getAgentsE()).push_back(clonedAgent);
}

   JoinPolicy* LastOfferJoinPolicy::info () {   
       return new LastOfferJoinPolicy();
    }

void LastOfferJoinPolicy::join(Simulation &sim, int partyId, vector<int> mOffers){
    Agent &theChosen = sim.getAgentsE()[mOffers[mOffers.size()-1]];  //take the last offer       
    int myCoalitionMandates = sim.getCoalitionVector()[theChosen.getCoalition()];
    sim.getCoalitionVector()[theChosen.getCoalition()]=myCoalitionMandates+(sim.getGraph().getPartyE(partyId).getMandates()); //update the coalition mandates with the new party
    sim.getGraph().getPartyE(partyId).setState(Joined);
    sim.getGraph().getPartyE(partyId).setCoalition(theChosen.getCoalition());
    if (sim.getCoalitionVector()[theChosen.getCoalition()] > sim.getMaxMandates()) //update the global max mandates
        sim.setMaxMandates(myCoalitionMandates+(sim.getGraph().getPartyE(partyId).getMandates()));
    Agent clonedAgent((sim.getAgents()).size(), partyId, theChosen.getSelectionPolicyb()->info(),theChosen.getCoalition() ); 
    (sim.getAgentsE()).push_back(clonedAgent);

}





