#pragma once

#include "BehaviorNode.h"

class L_CheckRPressed : public BaseNode<L_CheckRPressed>
{
protected:
    virtual void on_update(float dt);
};