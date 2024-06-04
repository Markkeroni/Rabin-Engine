#include <pch.h>
#include "L_MoveToMaxGoalRight.h"
#include "Agent/BehaviorAgent.h"

void L_MoveToMaxGoalRight::on_enter() {
	// Get reference to left post agent
	const auto& leftPostAgent = agents->get_all_agents_by_type("RightPost");
	// Set target to left post position
	targetPoint = leftPostAgent[0]->get_position();
	targetPoint.z -= 2.0f;
	BehaviorNode::on_leaf_enter();
}

void L_MoveToMaxGoalRight::on_update(float dt) {
	const auto& ballAgent = agents->get_all_agents_by_type("Ball");
	Vec3 ballPos = ballAgent[0]->get_position();
	Vec3 deltaVec = ballPos - agent->get_position();
	float lookTo = atan2(deltaVec.x, deltaVec.z);

	const auto result = agent->move_toward_point(targetPoint, dt);

	agent->set_yaw(lookTo);


	if (result == true) {
		on_success();
	}

	display_leaf_text();
}