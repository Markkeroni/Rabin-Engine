#include <pch.h>
#include "L_Spin.h"
#include "Agent/BehaviorAgent.h"

void L_Spin::on_enter() {
	BehaviorNode::on_leaf_enter();
	agent->set_pitch(0.4);
    elapsedTime = 0.0f;
}

void L_Spin::on_update(float dt) {
    elapsedTime += dt;
    if (elapsedTime >= maxTime) {
        // Exit the loop if the maximum time is reached
        on_success(); // Or on_failure() depending on your logic
        return;
    }
    // Get the current yaw of the agent
    float currentYaw = agent->get_yaw();

    // Update the yaw based on the spin speed and delta time
    float newYaw = currentYaw + (spinSpeed * dt);

    // Wrap the yaw angle to keep it within the range of 0 to 360 degrees
    if (newYaw >= 360.0f) {
        newYaw -= 360.0f;
    }
    else if (newYaw < 0.0f) {
        newYaw += 360.0f;
    }

    // Set the new yaw for the agent
    agent->set_yaw(newYaw);

    // Optionally, display some debug text or status
    display_leaf_text();
}

