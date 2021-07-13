#include "..\include\GameApp.h"

GameApp::GameApp(): mSpaceship("assets/starship.png",5), mSpaceshipAction(Action::Forward)
{

}

void GameApp::OnUpdate()
{
	if (mSpaceshipAction == Action::LeftMove)
	{
		if (mSpaceship.GetXCoord() >= mSpaceship.Speed())
			mSpaceship.UpdateXcoord(-mSpaceship.Speed());
		else
			mSpaceship.SetXCoord(0);
	}
		
	else if(mSpaceshipAction == Action::RightMove)
	{
		if (mSpaceship.GetXCoord() + mSpaceship.GetWidth() + mSpaceship.Speed() < GameApp::GetWindowWidth())
			mSpaceship.UpdateXcoord(mSpaceship.Speed());
		else
			mSpaceship.SetXCoord(GameApp::GetWindowWidth() - mSpaceship.GetWidth());
	}

	mSpaceship.Draw();
}

void GameApp::OnKeyPressed(Hunter::KeyPressedEvent& event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT)
	{
		mSpaceshipAction = Action::LeftMove;
	}
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT)
	{
		mSpaceshipAction = Action::RightMove;
	}
}
