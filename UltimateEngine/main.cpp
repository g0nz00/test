
#include<glad\glad.h>
#include<GLFW\glfw3.h>

#include<iostream>

#include "Shader.h"

void framebuffer_size_callback(GLFWwindow * mainWindow, int width, int height);
void processInput(GLFWwindow *window);
void changeDrawingMode(int mode);

bool drawingMode = false;


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
	
	Shader myShader("Shaders\\vertexShader.vert", "Shaders\\fragmentShader.frag");
	




	unsigned int indices[] = {  
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};


	float vertices[] = {
		// positions         // colors
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	
	while (!glfwWindowShouldClose(mainWindow))
	{
		processInput(mainWindow);
		
	
		glClearColor(0.5f, 0.7f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		myShader.use();
		int offset = glGetUniformLocation(myShader.ID, "offset");
		glUniform1f(offset, 0.4);


		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);








		glfwPollEvents();
		changeDrawingMode(drawingMode);
		glfwSwapBuffers(mainWindow);
		
	}





	
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);

}

void processInput(GLFWwindow *window)
{


	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS )
	{	
		drawingMode = true;
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		drawingMode = false;
	}
	
}

void changeDrawingMode(int mode)
{
	if ( mode == true)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	}
	if(mode==false)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		
	}


}