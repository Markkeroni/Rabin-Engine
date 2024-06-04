#pragma once
#include "BehaviorNode.h"

class L_PlayFailSound : public BaseNode<L_PlayFailSound>
{
protected:
    virtual void on_enter() override;
};