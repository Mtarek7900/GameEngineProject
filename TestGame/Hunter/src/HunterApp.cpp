#include <pch.h>
#include "HunterApp.h"
#include "WindowsWindow.h"

namespace Hunter 
{
	void HunterApp::RunGame()
	{
		HLOG("Start the game")
		
		while (true)
		{
			appWindow->SwapBufferes();
			appWindow->PollForEvent();
		}
	}

	HunterApp* HunterApp::GetApplication()
	{
		return instance;
	}

	void HunterApp::Init()
	{
		if (instance == nullptr)
			instance = new HunterApp;
	}

	HunterApp::HunterApp() 
	{
		assert(instance == nullptr);

#ifdef _HUNTER_WINDOWS
		appWindow = new WindowsWindow;
#else
	#Only_Windows_supported_for_now
#endif

		
		appWindow = new WindowsWindow;
		bool success{ appWindow->CreateWindow(800, 600) };
		assert(success);
	}

	HunterApp::~HunterApp()
	{
		appWindow->DeleteWindow();
	}
}