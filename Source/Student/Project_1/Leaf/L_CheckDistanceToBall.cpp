#include <pch.h>
#include "L_CheckDistanceToBall.h"
#include "Agent/BehaviorAgent.h"

void L_CheckDistanceToBall::on_enter() {
	BehaviorNode::on_leaf_enter();
}

void L_CheckDistanceToBall::on_update(float dt) {
	// Get ball agent
	const auto& ballAgent = agents->get_all_agents_by_type("Ball");
	auto& ballPos = ballAgent[0]->get_position();
	if (Vec3::Distance(agent->get_position(), ballPos) <= 7.0f) {
		on_success();
	}
	else {
		on_failure();
	}
}