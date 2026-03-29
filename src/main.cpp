#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>



void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0 , width, height);

}

int main()
{
    if (!glfwInit()) {
        std::cerr << "Error al iniciar GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "videojuego", nullptr, nullptr);
    if (!window) {
        std::cerr << "Error al crear ventana\n";
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error al iniciar GLAD\n";
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}