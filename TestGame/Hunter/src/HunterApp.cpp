#include <pch.h>
#include "HunterApp.h"
#include "Windows/WindowsWindow.h"
#include "Renderer.h"
#include "Sprite.h"
#include "HunterKeys.h"


namespace Hunter 
{
	void HunterApp::RunGame()
	{
		HLOG("Start the game");

		Renderer::Init();
			
		while (true)
		{
			Renderer::ClearFrame();

			OnUpdate();

			appWindow->SwapBuffers();
			appWindow->PollForEvent();
		}
	}

	HunterApp* HunterApp::GetApplication()
	{
		return instance;
	}


	HunterApp::HunterApp() 
	{
		assert(instance == nullptr);

		instance = this;

#ifdef _HUNTER_WINDOWS
		appWindow = new WindowsWindow;
#else
	#Only_Windows_supported_for_now
#endif

		
		//appWindow = new WindowsWindow;
		bool success{ appWindow->CreateWindow(800, 800) };
		assert(success);

		appWindow->SetKeyPressedCallback([this](KeyPressedEvent& event) {OnKeyPressed(event); });
	}

	HunterApp::~HunterApp()
	{
		appWindow->DeleteWindow();
	}

	void HunterApp::OnUpdate()
	{

	}

	int HunterApp::GetWindowWidth() 
	{
		return instance->appWindow->GetWidth();
	}

	int HunterApp::GetWindowHeight() 
	{
		return instance->appWindow->GetHeight();
	}

	void HunterApp::OnKeyPressed(KeyPressedEvent& event)
	{
		
	}
}