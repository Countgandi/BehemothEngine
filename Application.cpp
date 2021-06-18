#include "Application.h"

engine::Application::Application(uint32_t width, uint32_t height) {
	engine::logInfo(std::string(APPLICATION_NAME ":v") + std::to_string(VK_VERSION_MAJOR(APPLICATION_VERSION)) + "." + std::to_string(VK_VERSION_MINOR(APPLICATION_VERSION)) + "." + std::to_string(VK_VERSION_PATCH(APPLICATION_VERSION)) +
		(" - w/" ENGINE_NAME ":v") + std::to_string(VK_VERSION_MAJOR(ENGINE_VERSION)) + "." + std::to_string(VK_VERSION_MINOR(ENGINE_VERSION)) + "." + std::to_string(VK_VERSION_PATCH(ENGINE_VERSION)));

	if (!glfwInit()) {
		logErrorAndCrash("Could not initialize GLFW!!!");
	}

	m_vkRenderer = new engine::VulkanRenderer(width, height);

	run();
}

engine::Application::~Application() {
	delete m_vkRenderer;
}

void engine::Application::run() {
	float delta = 0;
	float last = 0;

	while (!m_vkRenderer->getWindow()->shouldClose()) {
		float current = getElapsedTime();
		delta = current - last;
		last = current;

		tick();
		render();

		m_vkRenderer->update();
	}
}

void engine::Application::tick() {

}

void engine::Application::render() {

}
