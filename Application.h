#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"
#include "VulkanRenderer.h"
#include "Logger.h"

namespace engine {

	class Application
	{
	public:
		Application(uint32_t width, uint32_t height);
		~Application();

	private:
		void run();
		void tick();
		void render();

		Window* m_window = nullptr;
		VulkanRenderer* m_vkRenderer = nullptr;
	};

}

#endif APPLICATION_H