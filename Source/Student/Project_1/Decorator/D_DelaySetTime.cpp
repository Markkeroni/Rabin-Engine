#include <pch.h>
#include "D_DelaySetTime.h"

D_DelaySetTime::D_DelaySetTime() : delay(0.0f)
{}

void D_DelaySetTime::on_enter()
{
    delay = 0.7f;

    BehaviorNode::on_enter();
}

void D_DelaySetTime::on_update(float dt)
{
    delay -= dt;

    if (delay < 0.0f)
    {
        BehaviorNode* child = children.front();

        child->tick(dt);

        // assume same status as child
        set_status(child->get_status());
        set_result(child->get_result());
    }
}