//#pragma once
#ifndef JOINPOLICY
#define JOINPOLICY
#include <vector>
class Agent;
using std::vector;
class Simulation;
class JoinPolicy
{
public:
     virtual  JoinPolicy* info()  = 0;//look at the power point how to send thedestructor to each class destructor
     virtual ~JoinPolicy()= default;
     virtual void join(Simulation &sim, int partyId, vector<int> mOffers)=0;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
      JoinPolicy* info() ;
     virtual ~MandatesJoinPolicy()= default;
     void join(Simulation &sim, int partyId, vector<int> mOffers);
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    JoinPolicy* info() ;
    virtual ~LastOfferJoinPolicy()=default; 
    void join(Simulation &sim, int partyId, vector<int> mOffers);
};
#endif