#include "../include/Party.h"
#include "../include/Simulation.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp) :offers(), mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(1), coalition(-1)
{
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}
int Party::getId()
{
    return mId;
}
int Party::getMandates() const
{
    return mMandates;
}
vector <int> &Party::getOffers(){
    return offers;
}

const string &Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if (this->getState() == CollectingOffers)
    {
        if (timer == 3)
        {
            mJoinPolicy->join(s,mId,offers);
        }
        else
        {
            timer++;
        }
    }
}

int Party::getCoalition()
{
    return coalition;
}

void Party::setCoalition(int c)
{
    coalition = c;
}

Party::~Party() //destructor
{
    if (mJoinPolicy)
        delete mJoinPolicy;
}

Party::Party(const Party &other):offers(other.offers), mId(other.mId),mName(other.mName),mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->info()), mState(other.mState),timer(other.timer),coalition(other.coalition)
{                    // copy constructor     
}

Party &Party::operator=(const Party &other) //copy assignment operator
{
    if (this != &other)
    {
        delete mJoinPolicy;
        mId=other.mId;
        mName=other.mName;
        mMandates=other.mMandates;
        mState=other.mState;
        timer=other.timer;
        coalition = other.coalition;
        mJoinPolicy = other.mJoinPolicy->info();
    }
    return *this;
}

Party::Party(Party &&other):offers( std::move(other.offers)),mId(other.mId),mName(other.mName),mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy), mState(other.mState),timer(other.timer),coalition(other.coalition) 
{//move constructor
    other.mJoinPolicy = nullptr;
}

Party &Party ::operator=(Party &&other)//move assignment operator
{
    if (mJoinPolicy)
        delete mJoinPolicy;
    coalition = other.coalition;
    mJoinPolicy = other.mJoinPolicy;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    timer = other.timer;
    offers = std::move(other.offers);
    other.mJoinPolicy = nullptr;
    return *this;
}
