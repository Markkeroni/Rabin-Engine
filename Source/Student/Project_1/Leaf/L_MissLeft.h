#pragma once
#include "BehaviorNode.h"

class L_MissLeft : public BaseNode<L_MissLeft> {
protected:
	virtual void on_enter() override;
	virtual void on_update(float dt) override;

private:
	float minZ, maxZ, minY, maxY;
	Vec3 targetPoint;
};