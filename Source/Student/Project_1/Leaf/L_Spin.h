#pragma once
#include "BehaviorNode.h"

class L_Spin : public BaseNode<L_Spin>
{
protected:
    virtual void on_enter() override;
    virtual void on_update(float dt) override;
private:
    float spinSpeed = 20.0f;
    float elapsedTime = 0.0f;
    float maxTime = 3.0f;
};