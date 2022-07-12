
// Including GLFW and glad (modern OpenGL loader)
#include "../include/glad/glad.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>


// Function to represent errors on a better way
static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

// Function to call the close of window
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}


// Main function
int main(void) {
    // Init window
    GLFWwindow* window;

    // This function sets the error callback, which is called with an error
    // code and a human-readable description each time a GLFW error occurs.
    // (In this case our function) NULL means delete the current error_callback
    glfwSetErrorCallback(error_callback);

    // Init glfw and check it
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    // Set glfwWindowHInt
    // (check glfw docs for more info with the possible parameters)
    // void = default values
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // This function creates a window and its associated OpenGL or OpenGL ES
    // context. Most of the options controlling how the window and its context
    // should be created are specified with window hints.
    window = glfwCreateWindow(800, 800, "Template", NULL, NULL);


    // Cheack the creation of the window
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Make the current context the window created
    glfwMakeContextCurrent(window);

    /*
    * Load OpenGL using an external loader like SDL_GL_GetProcAddress.
    *
    * Substitute GL with the API you generated
    *
    */
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // This function sets the swap interval for the current OpenGL or OpenGL
    // ES context, i.e. the number of screen updates to wait from the time
    // glfwSwapBuffers was called before swapping the buffers and returning.
    // This is sometimes called vertical synchronization, vertical retrace synchronization or just vsync.
    glfwSwapInterval(1);


    // While loop of the applicantion
    while(!glfwWindowShouldClose(window))
    {
        // Clear the color bit of the buffer (Sets the default color)
        glClear(GL_COLOR_BUFFER_BIT);

        // This function swaps the front and back buffers of the specified
        // window when rendering with OpenGL or OpenGL ES. If the swap interval
        // is greater than zero, the GPU driver waits the specified number of
        // screen updates before swapping the buffers.
        glfwSwapBuffers(window);


        // Function process the events there already in the event queue and
        // returns it
        glfwPollEvents();
    }

    // Destroy all the context and the window specified. If you call this function
    // You can't use anymore the window specified
    glfwDestroyWindow(window);

    // This function destroy all remaining windows and contexts (cursors to)
    // restores any modified gamma ramps and frees any other allocated resources.
    // you need call glfwInit(); again to use GLFW
    glfwTerminate();
}
