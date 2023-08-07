//#pragma once
#ifndef PARTY_H
#define PARTY_H
#include <string>
#include <vector>
#include "JoinPolicy.h"


class Simulation;


using std::vector;
using std::string;


enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getId ();
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getCoalition ();
    void setCoalition (int coalition); 
    virtual ~Party();
    Party (const Party &other);
    Party& operator = (const Party &other);
    Party ( Party&& other);
    Party& operator = ( Party&& other); 
    JoinPolicy *getJoinPolicy ();
    vector <int> &getOffers();


private:
    vector <int> offers;
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    int coalition;
    
};
#endif