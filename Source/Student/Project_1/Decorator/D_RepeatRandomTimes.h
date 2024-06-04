#pragma once
#include "BehaviorNode.h"

class D_RepeatRandomTimes : public BaseNode<D_RepeatRandomTimes>
{
public:
    D_RepeatRandomTimes();

protected:
    unsigned counter;
    unsigned int randTimes;
    virtual void on_enter() override;
    virtual void on_update(float dt) override;
};