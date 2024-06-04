#include <pch.h>
#include "L_SetSlowSpeed.h"

void L_SetSlowSpeed::on_enter()
{
	agent->set_movement_speed(10.0f);
	BehaviorNode::on_leaf_enter();
	on_success();
}