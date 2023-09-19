#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <vector>
#include <array>
#include <cassert>
#include <sstream>
#include <numeric>

//#include "vkappbase.h"
#include "CubeApp.h"

#pragma comment(lib, "vulkan-1.lib")

const int WindowWidth = 1280, WindowHeight = 720;
const char* AppTitle = "VulkanBase";

int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, 0);
    auto window = glfwCreateWindow(WindowWidth, WindowHeight, AppTitle, nullptr, nullptr);

    // Vulkan èâä˙âª
    //VulkanAppBase theApp;
    CubeApp theApp;
    theApp.initialize(window, AppTitle);

    while (glfwWindowShouldClose(window) == GLFW_FALSE)
    {
        glfwPollEvents();
        theApp.render();
    }

    // Vulkan èIóπ
    theApp.terminate();
    glfwTerminate();
    return 0;
}
