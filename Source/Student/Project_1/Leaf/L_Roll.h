#pragma once
#include "BehaviorNode.h"

class L_Roll : public BaseNode<L_Roll>
{
protected:
    virtual void on_enter() override;
    virtual void on_update(float dt) override;
private:
    bool rollingLeft;
    float rollTime;
    const float maxRollTime = 0.5f; 
    const float rollAngle = 0.5f;
    float elapsedTime = 0.0f;
    float maxTime = 3.0f;
};