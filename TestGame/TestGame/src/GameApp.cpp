#include "..\include\GameApp.h"

GameApp::GameApp(): mSpaceship("assets/starship.png",10), 
					mEndNotice("assets/game_over.png"),
					mBackground("assets/space.png"),
					mSpaceshipAction(Action::Forward),
					mFrameNumber(0),
					mGameEnd(false)
{

}

void GameApp::OnUpdate()
{
	Hunter::Renderer::Draw(mBackground, 0, 0, mBackground.GetWidth(),mBackground.GetHeight());
	
	if (mGameEnd)
	{
		Hunter::Renderer::Draw(mEndNotice, 250, 350, mEndNotice.GetWidth(), mEndNotice.GetHeight());
		return;
	}

	if (mFrameNumber % 30 == 0)
	{
		std::string planetType{ "assets/planet" + std::to_string((rand() % 5 + 1)) + ".png" };
		mPlanets.emplace_back(planetType, 10);
		mPlanets.back().SetYCoord(GameApp::GetWindowHeight());
		mPlanets.back().SetXCoord(rand()%(GameApp::GetWindowWidth()-mPlanets.back().GetWidth()));
	}

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

	while(!mPlanets.empty() && mPlanets.front().GetYCoord() <= -mPlanets.front().GetHeight()) 
	{
		mPlanets.pop_front();
	}

	for (auto& planet : mPlanets)
	{
		planet.UpdateYcoord(-planet.Speed());
		if (planet.OverlapsWith(mSpaceship))
		{
			mGameEnd = true;
		}
	}

	for (const auto& planet : mPlanets)
	{
		planet.Draw();
	}

	mSpaceship.Draw();

	mFrameNumber++;
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

void GameApp::OnKeyReleased(Hunter::KeyReleasedEvent& event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT || event.GetKeyCode() == HUNTER_KEY_RIGHT)
	{
		mSpaceshipAction = Action::Forward;
	}

}
