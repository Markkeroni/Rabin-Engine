#pragma once
#include "BehaviorNode.h"

class L_CheckDistanceToBall : public BaseNode<L_CheckDistanceToBall> {
protected:
	virtual void on_enter() override;
	virtual void on_update(float dt) override;
private:
};