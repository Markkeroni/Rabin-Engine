#include <pch.h>
#include "L_ResetBall.h"

void L_ResetBall::on_enter() {

	// Get references to agents
	const auto& playerAgent = agents->get_all_agents_by_type("Player");
	const auto& ballAgent = agents->get_all_agents_by_type("Ball");

	//
	ballAgent[0]->set_kicked_state(false);

	// Set agents back to default positions
	playerAgent[0]->set_position(Vec3(0, 0, 40)); // Spawn player near X centre of map 
	playerAgent[0]->set_yaw(PI / 2); // Make player face the goal

	ballAgent[0]->set_position(Vec3(10, 2, 50)); // Spawn ball near middle back of map

	BehaviorNode::on_leaf_enter();
	on_success();
}