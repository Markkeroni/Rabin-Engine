#pragma once
#include "BehaviorNode.h"

class L_KickBall : public BaseNode<L_KickBall> {
protected:
	virtual void on_enter() override;
	virtual void on_update(float dt) override;

private:
	Vec3 targetPoint;
	bool drawBackFlag;
};