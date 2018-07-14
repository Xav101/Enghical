#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#ifdef _WIN32
//preprocessor definition for windows-specific code

#elif defined(__linux__)
//preprocessor definition for linux-specific code

#endif

unsigned int WINDOW_WIDTH;
unsigned int WINDOW_HEIGHT;
std::string WINDOW_NAME = "OpenGL";

void get_res() {
	const GLFWvidmode* vid_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	WINDOW_WIDTH = vid_mode->width;
	WINDOW_HEIGHT = vid_mode->height;
}
 
void framebuffer_size_callback(GLFWwindow* window_object, int NEW_WIDTH, int NEW_HEIGHT) {
	glViewport(0, 0, NEW_WIDTH, NEW_HEIGHT);
}

void key_callback(GLFWwindow* window_object, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window_object, true);
	}
}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	get_res();
	GLFWwindow* window_object = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL", NULL, NULL);

	if (window_object == NULL) {
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window_object);
	glfwSetFramebufferSizeCallback(window_object, framebuffer_size_callback);
	glfwSetKeyCallback(window_object, key_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		std::cout << "Failed to initialize GLAD" << std::endl;
	
	while (!glfwWindowShouldClose(window_object)) {
		glfwSwapBuffers(window_object);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}