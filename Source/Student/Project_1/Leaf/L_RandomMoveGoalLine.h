#pragma once
#include "BehaviorNode.h"
#include "Misc/NiceTypes.h"

class L_RandomMoveGoalLine : public BaseNode<L_RandomMoveGoalLine> {
protected:
	virtual void on_enter() override;
	virtual void on_update(float dt) override;

private:
	Vec3 targetPoint;
	float minZ, maxZ;
};