#include "SimpleEngineCore/Window.hpp"
#include "SimpleEngineCore/Log.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SimpleEngine
{
    static bool s_GLFW_initialized = false;

    Window::Window(const std::string title, const unsigned int width, const unsigned int height)
        : m_data({std::move(title), width, height})
    {
        int resultCode = init();
    };

    Window::~Window()
    {
        shutdown();
    };

    void Window::on_update()
    {
         glClearColor(1, 0, 0, 0);
         glClear(GL_COLOR_BUFFER_BIT);
         glfwSwapBuffers(m_pWindow);
         glfwPollEvents();
    };

    int Window::init()
    {
        LOG_INFO("Creating window '{0}' width size {1}x{2}", m_data.title, m_data.width, m_data.height);

        if(!s_GLFW_initialized)
        {
                    /* Initialize the library */
            if (!glfwInit())
            {
                LOG_CRITICAL("Can't initialize GLFW!");
                return -1;
            }

            s_GLFW_initialized = true;
        };

        /* Create a windowed mode window and its OpenGL context */
        m_pWindow = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
        if (!m_pWindow)
        {
            LOG_CRITICAL("Can't create window {0} width size {1}x{2}", m_data.title, m_data.width, m_data.height);
            glfwTerminate();
            return -2;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(m_pWindow);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
             LOG_CRITICAL("Failed to initialize GLAD");
             return -3;
        };

        glfwSetWindowUserPointer(m_pWindow, &m_data);

        glfwSetWindowSizeCallback(m_pWindow,
            [](GLFWwindow* pWindow, int width, int height)
            {
                WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(pWindow));
                data.width = width;
                data.height = height;

                Event event;
                event.width = width;
                event.height = height;
                data.eventCallbackFn(event);
            }
        );

        return 0;

    };

    void Window::shutdown()
    {
        glfwDestroyWindow(m_pWindow);
        glfwTerminate();
    };

    void Window::set_event_callback(const EventCallbackFn& callback)
    {
        m_data.eventCallbackFn = callback;
    };
}
