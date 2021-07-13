#pragma once
#include "Hunter.h"
#include "Unit.h"
#include <deque>

class GameApp : public Hunter::HunterApp
{
public:
	GameApp();

	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Hunter::KeyPressedEvent& event) override;


private:
	Unit mSpaceship;
	std::deque<Unit> mPlanets;

	enum class Action
	{
		LeftMove,
		RightMove,
		Forward,	
	} mSpaceshipAction;
};