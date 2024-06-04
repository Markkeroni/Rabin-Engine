#pragma once

#include "BehaviorNode.h"

class D_DelaySetTime : public BaseNode<D_DelaySetTime>
{
public:
    D_DelaySetTime();

protected:
    float delay;

    virtual void on_enter() override;
    virtual void on_update(float dt) override;
};