#include <pch.h>
#include "Projects/ProjectOne.h"
#include "Agent/CameraAgent.h"

void ProjectOne::setup()
{
    // Create an agent (using the default "Agent::AgentModel::Man" model)


    // You can change properties here or at runtime from a behavior tree leaf node
    // Look in Agent.h for all of the setters, like these:
    // man->set_position(Vec3(0, 0, 50)); // Spawn player at X centre of map
    // man->set_yaw(1.5708); // Make player face the goal
    // man->set_color(Vec3(0, 0, 1)); // Make player blue
    // man->set_scaling(Vec3(7,7,7));

    // Create an agent with a different 3D model:
    // 1. (optional) Add a new 3D model to the framework other than the ones provided:
    //    A. Find a ".sdkmesh" model or use https://github.com/walbourn/contentexporter
    //       to convert fbx files (many end up corrupted in this process, so good luck!)
    //    B. Add a new AgentModel enum for your model in Agent.h (like the existing Man or Tree).
    // 2. Register the new model with the engine, so it associates the file path with the enum
    //    A. Here we are registering all of the extra models that already come in the package.
    Agent::add_model("Assets\\tree.sdkmesh", Agent::AgentModel::Tree);
    Agent::add_model("Assets\\car.sdkmesh", Agent::AgentModel::Car);
    Agent::add_model("Assets\\bird.sdkmesh", Agent::AgentModel::Bird);
    Agent::add_model("Assets\\ball.sdkmesh", Agent::AgentModel::Ball);
    Agent::add_model("Assets\\hut.sdkmesh", Agent::AgentModel::Hut);
    // 3. Create the agent, giving it the correct AgentModel type.
    //auto tree = agents->create_behavior_agent("ExampleAgent2", BehaviorTreeTypes::Example, Agent::AgentModel::Tree);
    
    // 4. (optional) You can also set the pitch of the model, if you want it to be rotated differently
    //tree->set_pitch(PI / 2);
    
    // 5. (optional) Set other aspects to make it start out correctly
    //tree->set_color(Vec3(0, 0.5, 0));   // Set the tree to green

    /* ================================== Player Start ====================================*/
    auto player = agents->create_behavior_agent("Player", BehaviorTreeTypes::PlayerTree); // Create player
    player->set_position(Vec3(0, 0, 40)); // Spawn player near X centre of map
    player->set_yaw(PI/2); // Make player face the goal
    player->set_color(Vec3(0, 0, 1)); // Make player blue
    player->set_scaling(Vec3(2, 2, 2)); // Make player scale 2
    /* ================================== Player End ====================================*/

    /* ================================== Left Post Start ====================================*/
    auto leftPost = agents->create_behavior_agent("LeftPost", BehaviorTreeTypes::Idle, Agent::AgentModel::Hut);
    leftPost->set_position(Vec3(100, 0, 25)); // Spawn left post at far end of map
    leftPost->set_color(Vec3(0, 0, 0)); // Make left post black
    leftPost->set_scaling(Vec3(0.1, 1.5, 0.1)); // Scale post to become stick   
    /* ================================== Left Post  End  ====================================*/

    /* ================================== Top Post Start ====================================*/
    //auto topPost = agents->create_behavior_agent("TopPost", BehaviorTreeTypes::Idle, Agent::AgentModel::Tree);
    /* ================================== Top Post  End  ====================================*/

    /* ================================== Right Post Start ====================================*/
    auto rightPost = agents->create_behavior_agent("RightPost", BehaviorTreeTypes::Idle, Agent::AgentModel::Hut);
    rightPost->set_position(Vec3(100, 0, 75)); // Spawn left post at far end of map
    rightPost->set_color(Vec3(0, 0, 0)); // Make left post black
    rightPost->set_scaling(Vec3(0.1, 1.5, 0.1)); // Scale post to become stick   
    /* ================================== Right Post  End  ====================================*/

    /* ================================== Goalie Start ====================================*/
    auto goalie = agents->create_behavior_agent("Goalie", BehaviorTreeTypes::GoalieTree); // Create player
    goalie->set_position(Vec3(100, 0, 50)); // Spawn goalie at X centre, far end of map
    goalie->set_yaw(2*PI - PI/2); // Make goalie face away from goal
    goalie->set_color(Vec3(1, 0, 0)); // Make goalie blue
    goalie->set_scaling(Vec3(2, 2, 2)); // Make golaie scale 2
    /* ================================== Goalie  End  ====================================*/

    /* ================================== Spectator Start ====================================*/
    auto spectator1 = agents->create_behavior_agent("Spectator", BehaviorTreeTypes::SpectatorTree, Agent::AgentModel::Man);
    auto spectator2 = agents->create_behavior_agent("Spectator", BehaviorTreeTypes::SpectatorTree, Agent::AgentModel::Man);
    auto spectator3 = agents->create_behavior_agent("Spectator", BehaviorTreeTypes::SpectatorTree, Agent::AgentModel::Man);
    auto spectator4 = agents->create_behavior_agent("Spectator", BehaviorTreeTypes::SpectatorTree, Agent::AgentModel::Man);
    auto spectator5 = agents->create_behavior_agent("Spectator", BehaviorTreeTypes::SpectatorTree, Agent::AgentModel::Man);
    auto spectator6 = agents->create_behavior_agent("Spectator", BehaviorTreeTypes::SpectatorTree, Agent::AgentModel::Man);

    spectator1->set_position(Vec3(25, 0, 100));
    spectator2->set_position(Vec3(50, 0, 100));
    spectator3->set_position(Vec3(75, 0, 100));
    spectator4->set_position(Vec3(25, 0, 0));
    spectator5->set_position(Vec3(50, 0, 0));
    spectator6->set_position(Vec3(75, 0, 0));
    
    spectator1->set_scaling(Vec3(2, 2, 2));
    spectator2->set_scaling(Vec3(2, 2, 2));
    spectator3->set_scaling(Vec3(2, 2, 2));
    spectator4->set_scaling(Vec3(2, 2, 2));
    spectator5->set_scaling(Vec3(2, 2, 2));
    spectator6->set_scaling(Vec3(2, 2, 2));

    /* ================================== Spectator  End  ====================================*/

    /* ================================== Ball Start ====================================*/
    auto ball = agents->create_behavior_agent("Ball", BehaviorTreeTypes::BallTree, Agent::AgentModel::Ball);
    ball->set_position(Vec3(10, 2, 50)); // Spawn ball near middle back of map
    ball->set_scaling(Vec3(0.4, 0.4, 0.4));
    /* ================================== Ball  End  ====================================*/
    
    // You can technically load any map you want, even create your own map file,
    // but behavior agents won't actually avoid walls or anything special, unless you code
    // that yourself (that's the realm of project 2)
    terrain->goto_map(0);

    // You can also enable the pathing layer and set grid square colors as you see fit.
    // Works best with map 0, the completely blank map
    terrain->pathLayer.set_enabled(true);
    terrain->pathLayer.set_value(0, 0, Colors::Red);

    // Camera position can be modified from this default
    auto camera = agents->get_camera_agent();
    camera->set_position(Vec3(-62.0f, 40.0f, terrain->mapSizeInWorld * 0.5f));
    camera->set_pitch(0.610865/2); // 35/2 degrees

    // Sound control (these sound functions can be kicked off in a behavior tree node - see the example in L_PlaySound.cpp)
    audioManager->SetVolume(0.5f);
    audioManager->PlayMusic(L"Assets\\Audio\\CrowdNoise.wav", true);
    //audioManager->PlaySoundEffect(L"Assets\\Audio\\retro.wav");
    // Uncomment for example on playing music in the engine (must be .wav)
    // audioManager->PlayMusic(L"Assets\\Audio\\motivate.wav");
    // audioManager->PauseMusic(...);
    // audioManager->ResumeMusic(...);
    // audioManager->StopMusic(...);
}