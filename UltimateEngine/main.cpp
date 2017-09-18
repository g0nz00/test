
#include<glad\glad.h>
#include<GLFW\glfw3.h>

#include<iostream>

void framebuffer_size_callback(GLFWwindow * mainWindow, int width, int height);

int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *mainWindow = glfwCreateWindow(800, 600, "UltimateEngine", NULL, NULL);
	if (mainWindow == NULL)
	{
		std::cout << "Failed to create main window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(mainWindow);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(mainWindow, framebuffer_size_callback);


	while (!glfwWindowShouldClose(mainWindow))
	{
		glfwSwapBuffers(mainWindow);
		glfwPollEvents();
	}





	

	return 0;
}

void framebuffer_size_callback(GLFWwindow * mainWindow, int width, int height)
{
	glViewport(0, 0, width, height);

}
