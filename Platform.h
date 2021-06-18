#ifndef PLATFORM_H
#define PLATFORM_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Logger.h"

#define ENGINE_NAME "Behemoth Engine"
#define ENGINE_VERSION VK_MAKE_VERSION(0, 0, 1)

#define APPLICATION_NAME "Prototype Application"
#define APPLICATION_VERSION VK_MAKE_VERSION(1, 0, 0)

#endif // PLATFORM_H