#ifndef OBSERVER_H
#define OBSERVER_H

class Player;

class Observer {

    public:
    virtual void notify(Player &whoFrom) = 0;
    virtual ~Observer() = default;
};

#endif