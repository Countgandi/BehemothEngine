#ifndef WINDOW_H
#define WINDOW_H

#include "Platform.h"

namespace engine {

	class Window
	{
	public:
		Window(uint32_t width, uint32_t height, const char* title, VkInstance* instace);
		~Window();

		void update();
		void setTitle(const char* title);
		bool shouldClose();

		GLFWwindow* getWindow();
		VkSurfaceKHR* getSurface();

		uint32_t getWidth();
		uint32_t getHeight();

		void setSize(uint32_t width, uint32_t height);

	private:
		GLFWwindow* m_window = nullptr;

		VkInstance* m_instance = nullptr;
		VkSurfaceKHR m_surface;
		uint32_t m_width, m_height;

	};

}

#endif // WINDOW_H