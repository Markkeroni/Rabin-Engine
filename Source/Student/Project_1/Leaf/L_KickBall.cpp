#include <pch.h>
#include "L_KickBall.h"
#include "Agent/BehaviorAgent.h"

void L_KickBall::on_enter() {
	// Set pitch speed
	agent->set_pitch_speed(0.7f);
	// Get reference to ball agent
	const auto& ballAgent = agents->get_all_agents_by_type("Ball");
	// Get position of ball agent
	targetPoint = ballAgent[0]->get_position();
	targetPoint.x -= 5.0f;
	targetPoint.z -= 1.0f;

	BehaviorNode::on_leaf_enter();
}

void L_KickBall::on_update(float dt) {
	const auto result1 = agent->move_toward_point(targetPoint, dt);
	bool result2 = false;
	bool result3 = false;
	if (result1 == true) { // Once plaer move to ball
		agent->set_pitch_speed(2.0f);
		if (drawBackFlag == false) {
			agent->set_yaw(PI / 2);
			result2 = agent->move_toward_pitch(0.6f, dt);	
			if (result2 == true) {
				drawBackFlag = true;
			}
		}
		else {
			agent->set_pitch_speed(6.0f);
			result3 = agent->move_toward_pitch(-0.3f, dt);
			if (result3 == true) {
				// Set kicked to true in blackboard
				auto& bb = agent->get_blackboard();
				bb.set_value("Kicked", true);

				// Get ball agent
				auto& ballAgent = agents->get_all_agents_by_type("Ball");
				// Set ball to kicked
				ballAgent[0]->set_kicked_state(true);

				on_success();
			}
		}
		
	}
	
	display_leaf_text();
}