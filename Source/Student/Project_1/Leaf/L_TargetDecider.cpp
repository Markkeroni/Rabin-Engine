#include <pch.h>
#include "L_TargetDecider.h"
#include "../Agent/BehaviorAgent.h"

void L_TargetDecider::on_enter() {
	BehaviorNode::on_leaf_enter();
	RNG::coin_toss() ? on_success() : on_failure();
}