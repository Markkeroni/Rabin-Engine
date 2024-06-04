#include <pch.h>
#include "L_PlayFailSound.h"

void L_PlayFailSound::on_enter()
{
	audioManager->PlaySoundEffect(L"Assets\\Audio\\FailSound.wav");
	BehaviorNode::on_leaf_enter();
	on_success();
}