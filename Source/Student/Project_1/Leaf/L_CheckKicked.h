#pragma once
#include "BehaviorNode.h"

class L_CheckKicked : public BaseNode<L_CheckKicked> {
protected:
	virtual void on_update(float dt);
};