#include <pch.h>
#include "L_CheckKicked.h"
#include "../Agent/BehaviorAgent.h"

void L_CheckKicked::on_update(float dt) {
    if (agent->get_kicked_state() == true) {
        on_success();
    }
    else {
        on_failure();
    }

    display_leaf_text();
}