#include <algorithm>
#include <assert.h>
#include <map>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>
#include "Screen.h"
#include "Utility.h"

//======================================================================================================
Screen* Screen::Instance()
{
	static Screen* screenObject = new Screen();
	return screenObject;
}
//======================================================================================================
bool Screen::Initialize(const std::string& filename)
{
	std::map<std::string, std::string> dataMap;

	if (!Utility::LoadConfigFile(filename, dataMap))
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"Error opening config file '" + filename + "'", Utility::Severity::Failure);
		return false;
	}

	if (glfwInit() == GLFW_FALSE)
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"GLFW did not initialize properly.", Utility::Severity::Failure);
		return false;
	}

	/*if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1)
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"SDL did not initialize properly.", Utility::Severity::Failure);
		return false;
	}*/
	
	/*SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);*/

	//Set up anti-aliasing 
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

	//GLint profile = std::stoi(dataMap["Core"]) == 1 ? SDL_GL_CONTEXT_PROFILE_CORE
	//	: SDL_GL_CONTEXT_PROFILE_COMPATIBILITY;

	int profile = std::stoi(dataMap["Core"]) == 1 ? GLFW_OPENGL_CORE_PROFILE
		: GLFW_OPENGL_COMPAT_PROFILE;

	glfwWindowHint(GLFW_OPENGL_PROFILE, profile);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, std::stoi(dataMap["Major"]));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, std::stoi(dataMap["Minor"]));

	//set OpenGL context and profile using values assigned earlier
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, profile);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, std::stoi(dataMap["Major"]));
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, std::stoi(dataMap["Minor"]));

	//auto screenFlag = std::stoi(dataMap["Maximized"]) == 1
		//? SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED
		//: SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

	window = glfwCreateWindow(std::stoi(dataMap["Width"]),
							  std::stoi(dataMap["Height"]),
							  dataMap["Name"].c_str(), 
		                      nullptr, nullptr);
	
	if (!window)
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"Application window could not be created.", Utility::Severity::Failure);
		glfwTerminate();
		return false;
	}

	/*window = SDL_CreateWindow(dataMap["Name"].c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		std::stoi(dataMap["Width"]),
		std::stoi(dataMap["Height"]),
		screenFlag);*/

	/*if (!window)
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"Game window could not be created.", Utility::Severity::Failure);
		return false;
	}*/

	//Make the context of the window the main context on the current thread
	glfwMakeContextCurrent(window);
	
	//context = SDL_GL_CreateContext(window);

	/*if (!context)
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"OpenGL context could not be created. "
			"The context is either invalid or not supported by your graphics card",
			Utility::Severity::Failure);
		return false;
	}*/

	if (!gladLoaderLoadGL())
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"GLAD could not be initialized", Utility::Severity::Failure);
		return false;
	}

	//TODO - Not sure if we need this and where it should go
	//SDL_SetRelativeMouseMode(SDL_TRUE);

	resolution.x = std::stoi(dataMap["Width"]);
	resolution.y = std::stoi(dataMap["Height"]);
	
	SetViewport(0, 0, resolution.x, resolution.y);

	//glfwSetFramebufferSizeCallback(window, Screen::WindowResizeCallback);

	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_SCISSOR_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Temp disable UI
	//ImGui::CreateContext();
	//ImGui_ImplOpenGL3_Init("#version 460");
	//ImGui_ImplSDL2_InitForOpenGL(window, context);

	return true;
}

//void Screen::WindowResizeCallback(GLFWwindow* window, int width, int height)
//{
//	SetViewport(0, 0, resolution.x, resolution.y);
//}

//======================================================================================================
const glm::ivec2& Screen::GetResolution()
{
	//SDL_GetWindowSize(window, &resolution.x, &resolution.y);
	//assert(resolution != glm::ivec2(0));
	return resolution;
}
//======================================================================================================
void Screen::SetVSync(VSync VSync)
{
	/*if (SDL_GL_SetSwapInterval(static_cast<int>(VSync) == -1))
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"Vertical sync not supported", Utility::Severity::Warning);
	}*/
}
//======================================================================================================
void Screen::IsDepthTestEnabled(bool flag)
{
	flag ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
}
//======================================================================================================
void Screen::SetCursorPosition(GLuint x, GLuint y)
{
	//SDL_WarpMouseInWindow(window, x, y);
}
//======================================================================================================
void Screen::SetResolution(GLint width, GLint height)
{
	resolution.x = width;
	resolution.y = height;
	glm::max(resolution, 1);
}
//======================================================================================================
void Screen::SetColor(const glm::vec4& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}
//======================================================================================================
void Screen::SetColor(const glm::uvec4& color)
{
	glClearColor(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
}
//======================================================================================================
void Screen::SetColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}
//======================================================================================================
void Screen::SetColor(GLuint r, GLuint g, GLuint b, GLuint a)
{
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}
//======================================================================================================
void Screen::SetViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	glViewport(x, y, width, height);
	glScissor(x, y, width, height);
}
//======================================================================================================
void Screen::Refresh() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
//======================================================================================================
void Screen::Present() const
{
	//SDL_GL_SwapWindow(window);
	glfwSwapBuffers(window);
}
//======================================================================================================
void Screen::Shutdown() const
{
	//Temp ui disable
	//ImGui_ImplOpenGL3_Shutdown();
	//ImGui_ImplSDL2_Shutdown();
	//ImGui::DestroyContext();

	glfwTerminate();

	//SDL_GL_DeleteContext(context);
	//SDL_DestroyWindow(window);
	//SDL_Quit();
}