#pragma once
#include "Core.h"



namespace Snow {
	class SNOW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};


	//Defined in client
	Application* CreateApplication();


}

