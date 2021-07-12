#pragma once
#include "HunterCentral.h"
#include "Window.h"
#include "KeyboardEvents.h"

namespace Hunter
{
	class HUNTER_API HunterApp
	{
	public:
		virtual void RunGame();
		static HunterApp* GetApplication();
		virtual ~HunterApp();

		virtual void OnUpdate();

		static int GetWindowWidth();
		static int GetWindowHeight();

		void OnKeyPressed(KeyPressedEvent& event);
	
	protected:	
		HunterApp();
	
	private:
		inline static HunterApp* instance{ nullptr };
		
		Hunter::Window* appWindow{ nullptr };

	};
}

