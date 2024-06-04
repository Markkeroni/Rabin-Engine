#include <pch.h>
#include "L_CheckRPressed.h"
#include "../Agent/BehaviorAgent.h"

void L_CheckRPressed::on_update(float dt) {
	const auto rState = InputHandler::get_current_state(KBKeys::R);

	if (rState == InputHandler::InputState::PRESSED) {
		on_success();
	}
	else {
		on_failure();
	}
	display_leaf_text();
}