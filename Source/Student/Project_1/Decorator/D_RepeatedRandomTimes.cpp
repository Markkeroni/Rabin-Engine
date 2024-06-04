#include <pch.h>
#include "D_RepeatRandomTimes.h"

D_RepeatRandomTimes::D_RepeatRandomTimes() : counter(0)
{}

void D_RepeatRandomTimes::on_enter()
{
    randTimes = RNG::range<int>(1, 5);
    counter = 0;
    BehaviorNode::on_enter();
}

void D_RepeatRandomTimes::on_update(float dt)
{
    // repeat the child until x successes, stop on any failure
    BehaviorNode* child = children.front();

    child->tick(dt);

    if (child->succeeded() == true)
    {
        ++counter;

        if (counter == randTimes)
        {
            on_success();
        }
        else
        {
            child->set_status(NodeStatus::READY);
        }
    }
    else if (child->failed() == true)
    {
        on_failure();
    }
}
