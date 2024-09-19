#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow *window);

int main(){

    // Initialize GLFW
    glfwInit();

    // Set the OpenGL version to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Set the OpenGL profile to core
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "My program", NULL, NULL);
    // Check if the window was created
    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;

        // Terminate GLFW
        glfwTerminate();

        // Return -1
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);



    // Checking if GLAD is loaded
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, 800, 600);

    // Set the callback function for resizing the window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // Vertex data
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };


    // Main loop
    while(!glfwWindowShouldClose(window))
    {
        // Process input
        processInput(window);

        // Rendering commands here
        // ....

        // Temporary color
        // Set the color to clear the screen with
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // Clear the color buffer

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for events
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    // Returning 0
    return 0;
}


// Function to resize the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Set the viewport
    glViewport(0, 0, width, height);
}


// Function to process input
void processInput(GLFWwindow *window)
{
    // Check if the escape key was pressed
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        // Set the window to close
        glfwSetWindowShouldClose(window, true);
    }
}
