#include <pch.h>
#include "L_Roll.h"
#include "Agent/BehaviorAgent.h"

void L_Roll::on_enter() {
    rollingLeft = true; 
    rollTime = 0.0f;
    elapsedTime = 0.0f;
    BehaviorNode::on_leaf_enter();
}

void L_Roll::on_update(float dt) {
    rollTime += dt;
    elapsedTime += dt;
    if (elapsedTime >= maxTime) {       
        on_success();
        return;
    }
    if (rollingLeft) {
        agent->set_roll(rollAngle * (rollTime / maxRollTime));

        if (rollTime >= maxRollTime) {
            rollingLeft = false;
            rollTime = 0.0f;
        }
    }
    else {
        agent->set_roll(-rollAngle * (rollTime / maxRollTime));

        if (rollTime >= maxRollTime) {
            rollingLeft = true;
            rollTime = 0.0f;
        }
    }

    display_leaf_text();
}