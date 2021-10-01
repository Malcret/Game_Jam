#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader.hpp"
#include "texture.hpp"

// OpenGL context options
#define ANTIALIASING 4
#define OPENGL_MAJOR 4
#define OPENGL_MINOR 6

// Window options
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Callback functions
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
static void character_callback(GLFWwindow *window, unsigned int codepoint);
static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

// Exit with error function
static void exit_error(const char *msg, GLFWwindow *window, bool terminate_GLFW);

int main(int argc, const char **argv) {

    // Initialize GLFW
    if (glfwInit() == GLFW_FALSE) {
        exit_error("Failed to initialize GLFW", NULL, false);
    }

    // Set GLFW context options
    glfwWindowHint(GLFW_SAMPLES, ANTIALIASING);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR);
#ifndef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__

    // Create a GLFW window
    GLFWwindow *window = NULL;
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "GameJam", NULL, NULL);
    if (window == NULL) {
        exit_error("Failed to create an OpenGL window", NULL, true);
    }

    // Set GLFW context
    glfwMakeContextCurrent(window);

    // Set callback
    glfwSetKeyCallback(window, key_callback);
    glfwSetCharCallback(window, character_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    // Initialize GLEW
    glewExperimental = 1;
    if (glewInit() != GLEW_OK) {
        exit_error("Failed to initialize GLEW", window, true);
    }

    // Set capture modes
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GL_TRUE);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Clear screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Get events
        glfwPollEvents();

        // Draw

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Clear context
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}

// Get keyboard input
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

}

// Get character input
static void character_callback(GLFWwindow *window, unsigned int codepoint) {

}

// Get cursor position
static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {

}

// Get mouse input
static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {

}

// Exit with error
static void exit_error(const char *msg, GLFWwindow *window, bool terminate_GLFW) {

    std::cerr << "ERROR: " << msg << std::endl;

    if (window != NULL) {
        glfwDestroyWindow(window);
    }

    if (terminate_GLFW) {
        glfwTerminate();
    }

    exit(EXIT_FAILURE);
}
