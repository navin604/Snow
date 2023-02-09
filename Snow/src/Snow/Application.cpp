#include "Application.h"
#include "Snow/Events/ApplicationEvent.h"
#include "Snow/Log.h"

namespace Snow {

	Application::Application()
	{

	}


	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SNOW_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SNOW_TRACE(e);
		}


		while (true);
	}


}