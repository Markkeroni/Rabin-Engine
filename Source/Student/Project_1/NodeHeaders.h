#pragma once

// Include all node headers in this file

// Example Control Flow Nodes
#include "ControlFlow/C_ParallelSequencer.h"
#include "ControlFlow/C_RandomSelector.h"
#include "ControlFlow/C_Selector.h"
#include "ControlFlow/C_Sequencer.h"

// Student Control Flow Nodes


// Example Decorator Nodes
#include "Decorator/D_Delay.h"
#include "Decorator/D_InvertedRepeater.h"
#include "Decorator/D_RepeatFourTimes.h"

// Student Decorator Nodes
#include "Decorator/D_Inverter.h"
#include "Decorator/D_RepeatRandomTimes.h"
#include "Decorator/D_DelaySetTime.h"

// Example Leaf Nodes
#include "Leaf/L_CheckMouseClick.h"
#include "Leaf/L_Idle.h"
#include "Leaf/L_MoveToFurthestAgent.h"
#include "Leaf/L_MoveToMouseClick.h"
#include "Leaf/L_MoveToRandomPosition.h"
#include "Leaf/L_PlaySound.h"

// Student Leaf Nodes
#include "Leaf/L_MoveToMaxGoalLeft.h"
#include "Leaf/L_MoveToMaxGoalRight.h"
#include "Leaf/L_RandomMoveGoalLine.h"
#include "Leaf/L_KickBall.h"
#include "Leaf/L_CheckRPressed.h"
#include "Leaf/L_CheckKicked.h"
#include "Leaf/L_TargetDecider.h"
#include "Leaf/L_OnTarget.h"
#include "Leaf/L_MissLeft.h"
#include "Leaf/L_MissRight.h"
#include "Leaf/L_PlayFailSound.h"
#include "Leaf/L_ResetBall.h"
#include "leaf/L_PlayKickSound.h"
#include "Leaf/L_SetFastSpeed.h"
#include "Leaf/L_SetSlowSpeed.h"
#include "Leaf/L_CheckDistanceToBall.h"
#include "Leaf/L_Spin.h"
#include "Leaf/L_Roll.h"