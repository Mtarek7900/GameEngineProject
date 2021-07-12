#include <pch.h>
#include "WindowsWindow.h"

namespace Hunter
{
	bool WindowsWindow::CreateWindow(unsigned int width, unsigned int hieght)
	{
		glfwInit();

		window = glfwCreateWindow(width, hieght, "Test Window", NULL, NULL);

		if (window == nullptr)
			return false;

		glfwMakeContextCurrent(window);
		gladLoadGL();

		glfwSwapInterval(1);
		
		return true;
	}

	void WindowsWindow::DeleteWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void WindowsWindow::SwapBufferes()
	{
		glfwSwapBuffers(window);
	}

	void WindowsWindow::PollForEvent()
	{
		glfwPollEvents();
	}

	int WindowsWindow::GetWidth() const
	{
		int width{ 0 };
		int height{ 0 };

		glfwGetWindowSize(window, &width, &height);

		return width;
	}

	int WindowsWindow::GetHeight() const
	{
		int width{ 0 };
		int height{ 0 };

		glfwGetWindowSize(window, &width, &height);

		return height;
	}
}