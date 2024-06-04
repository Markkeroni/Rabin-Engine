#pragma once
#include "BehaviorNode.h"

class L_OnTarget : public BaseNode<L_OnTarget> {
protected:
	virtual void on_enter() override;
	virtual void on_update(float dt) override;

private:
	float minZ, maxZ, minY, maxY;
	Vec3 targetPoint;
};