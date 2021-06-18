#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H

#include <vector>
#include <cstring>
#include <optional>
#include <set>

#include "Platform.h"
#include "Window.h"


const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

#ifdef _DEBUG
const bool enableValidationLayers = true;
#else
const bool enableValidationLayers = false;
#endif // !_DEBUG


namespace engine {

	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	class VulkanRenderer
	{
	public:
		VulkanRenderer(uint32_t width, uint32_t height);
		~VulkanRenderer();

		void update();

		Window* getWindow();

	private:
		void initVulkan();
		void destroyVulkan();

		bool checkValidationLayerSupport();

		uint32_t ratePhyiscalDevice(const VkPhysicalDevice& device);

		uint32_t m_width, m_height;
		VkInstance m_instance;
		QueueFamilyIndices m_queueFamilyIndices;
		VkDevice m_device;

		VkQueue m_graphicsQueue;
		VkQueue m_presentQueue;

		Window* m_window = nullptr;

	};

}

#endif // VULKANRENDERER_H