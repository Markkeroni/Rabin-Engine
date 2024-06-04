#pragma once
#include "BehaviorNode.h"

class L_SetSlowSpeed : public BaseNode<L_SetSlowSpeed>
{
protected:
    virtual void on_enter() override;
};