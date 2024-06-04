#include <pch.h>
#include "L_RandomMoveGoalLine.h"
#include "Agent/BehaviorAgent.h"

void L_RandomMoveGoalLine::on_enter() {
	// Set agent movement speed
	agent->set_movement_speed(20.0f);
	// Get reference to posts agents
	const auto& leftPostAgent = agents->get_all_agents_by_type("LeftPost");
	const auto& rightPostAgent = agents->get_all_agents_by_type("RightPost");
	// Get min and max Z bounds
	minZ = leftPostAgent[0]->get_position().z + 2.0f;
	maxZ = rightPostAgent[0]->get_position().z - 2.0f;

	targetPoint.x = RNG::range<float>(70.0f, 100.0f);
	targetPoint.z = RNG::range<float>(minZ, maxZ);
	targetPoint.y = 0.0f;

	BehaviorNode::on_leaf_enter();
}


void L_RandomMoveGoalLine::on_update(float dt) {
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