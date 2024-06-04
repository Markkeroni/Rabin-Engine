#include <pch.h>
#include "L_MoveToMaxGoalLeft.h"
#include "Agent/BehaviorAgent.h"

void L_MoveToMaxGoalLeft::on_enter() {
	// Get reference to left post agent
	const auto& leftPostAgent = agents->get_all_agents_by_type("LeftPost");
	// Set target to left post position
	targetPoint = leftPostAgent[0]->get_position();

	BehaviorNode::on_leaf_enter();	
}

void L_MoveToMaxGoalLeft::on_update(float dt) {

	const auto result = agent->move_toward_point(targetPoint, dt);

	if (result == true) {
		on_success();
	}

	display_leaf_text();
}