#include <pch.h>
#include "L_PlayKickSound.h"

void L_PlayKickSound::on_enter()
{
	audioManager->PlaySoundEffect(L"Assets\\Audio\\kickball.wav");
	BehaviorNode::on_leaf_enter();
	on_success();
}