#include <pch.h>
#include "L_MissRight.h"
#include "Agent/BehaviorAgent.h"

void L_MissRight::on_enter() {
	// Set ball propeties
	agent->set_movement_speed(100.0f);
	// Get references to agents
	const auto& leftPostAgent = agents->get_all_agents_by_type("RightPost");
	// Get Min and Max bounds for miss
	minZ = leftPostAgent[0]->get_position().z + 5.0f;
	maxZ = 100.0f;
	minY = 2.0f;
	maxY = 25.0f;
	targetPoint.x = 110.0f;
	targetPoint.y = RNG::range<float>(minY, maxY);
	targetPoint.z = RNG::range<float>(minZ, maxZ);

	BehaviorNode::on_leaf_enter();
}

void L_MissRight::on_update(float dt) {
	auto result = agent->move_toward_point(targetPoint, dt);
	if (result == true) {
		
		on_success();
	}

	display_leaf_text();
}