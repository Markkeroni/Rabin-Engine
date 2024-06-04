#pragma once

#include "BehaviorNode.h"

class L_MissRight : public BaseNode<L_MissRight> {
protected:
	virtual void on_enter() override;
	virtual void on_update(float dt) override;

private:
	float minZ, maxZ, minY, maxY;
	Vec3 targetPoint;
};