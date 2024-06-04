#include <pch.h>
#include "L_SetFastSpeed.h"

void L_SetFastSpeed::on_enter()
{
	agent->set_movement_speed(35.0f);
	BehaviorNode::on_leaf_enter();
	on_success();
}