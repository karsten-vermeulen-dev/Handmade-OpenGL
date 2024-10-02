#include "Input.h"
#include "Screen.h"

//======================================================================================================
Input* Input::Instance()
{
	static Input* inputObject = new Input();
	return inputObject;
}

const Input::State& Input::GetState() const
{
	return state;
}
//======================================================================================================
//bool Input::IsXClicked() const
//{
//	return isXClicked;
//}
//======================================================================================================
//bool Input::IsKeyPressed() const
//{
//	return isKeyPressed;
//}
//======================================================================================================
//bool Input::IsWindowResized() const
//{
//	return isWindowResized;
//}
//======================================================================================================
//bool Input::IsLeftButtonClicked() const
//{
//	return isLeftButtonClicked;
//}
////======================================================================================================
//bool Input::IsRightButtonClicked() const
//{
//	return isRightButtonClicked;
//}
////======================================================================================================
//bool Input::IsMiddleButtonClicked() const
//{
//	return isMiddleButtonClicked;
//}
//======================================================================================================
//const glm::ivec2& Input::GetMouseWheel() const
//{
//	return mouseWheel;
//}
////======================================================================================================
//const glm::ivec2& Input::GetMouseMotion() const
//{
//	return mouseMotion;
//}
//======================================================================================================
//const glm::ivec2& Input::GetMousePosition() const
//{
//	return mousePosition;
//}
//======================================================================================================
//char Input::GetKeyUp() const
//{
//	return keyUp;
//}
////======================================================================================================
//char Input::GetKeyDown() const
//{
//	return keyDown;
//}
////======================================================================================================
//KeyState Input::GetKeyStates() const
//{
//	return keyStates;
//}
//======================================================================================================
//void Input::SetCursorType(CursorType cursorType)
//{
//	SDL_FreeCursor(cursor);
//	cursor = SDL_CreateSystemCursor(static_cast<SDL_SystemCursor>(cursorType));
//	SDL_SetCursor(cursor);
//}
//======================================================================================================-
//void Input::SetCursorState(CursorState cursorEnabled, CursorState cursorVisible)
//{
//	//If mouse cursors are enabled that means they stay within the bounds 
//	//of the window. On top of that they can still be visible or hidden
//	if (static_cast<bool>(cursorEnabled))
//	{
//		if (static_cast<bool>(cursorVisible))
//		{
//			SDL_ShowCursor(static_cast<int>(CursorState::Show));
//			SDL_SetRelativeMouseMode(SDL_FALSE);
//		}
//
//		else
//		{
//			SDL_ShowCursor(static_cast<int>(CursorState::Hide));
//			SDL_SetRelativeMouseMode(SDL_FALSE);
//		}
//	}
//
//	else
//	{
//		SDL_ShowCursor(static_cast<int>(CursorState::Hide));
//		SDL_SetRelativeMouseMode(SDL_TRUE);
//	}
//}

void Input::AssignCallbacks(GLFWwindow* window)
{
	glfwSetKeyCallback(window, Input::OnKeyPress);
	glfwSetCursorPosCallback(window, Input::OnMouseMove);
	glfwSetMouseButtonCallback(window, Input::OnMouseClick);
	glfwSetScrollCallback(window, Input::OnMouseWheel);
}

void Input::OnMouseMove(GLFWwindow* window, double x, double y)
{
	state.mouseMotion.x = (x - state.mousePosition.x) / Screen::Instance()->GetResolution().x;
	state.mouseMotion.y = (y - state.mousePosition.y) / Screen::Instance()->GetResolution().y;
	
	state.mousePosition.x = x;
	state.mousePosition.y = y;
}

void Input::OnMouseClick(GLFWwindow* window, int button, int action, int mods)
{
	switch (action)
	{
	case GLFW_PRESS:
	{
		switch (button)
		{
		case GLFW_MOUSE_BUTTON_LEFT:
		{
			state.isLeftButtonClicked = true;
			break;
		}

		case  GLFW_MOUSE_BUTTON_RIGHT:
		{
			state.isRightButtonClicked = true;
			break;
		}

		case  GLFW_MOUSE_BUTTON_MIDDLE:
		{
			state.isMiddleButtonClicked = true;
			break;
		}
		}

		break;
	}

	case GLFW_RELEASE:
	{
		switch (button)
		{
		case GLFW_MOUSE_BUTTON_LEFT:
		{
			state.isLeftButtonClicked = false;
			break;
		}

		case  GLFW_MOUSE_BUTTON_RIGHT:
		{
			state.isRightButtonClicked = false;
			break;
		}

		case  GLFW_MOUSE_BUTTON_MIDDLE:
		{
			state.isMiddleButtonClicked = false;
			break;
		}
		}
	}

	}
}

void Input::OnKeyPress(GLFWwindow* window, int keyCode, int scancode, int action, int mods)
{
	switch (action)
	{
	case GLFW_PRESS:
	{
		state.isKeyPressed = true;
		state.keyUp = keyCode;
		break;
	}

	case GLFW_RELEASE:
	{
		state.isKeyPressed = false;
		state.keyUp = keyCode;
		break;
	}

	}
}

void Input::OnMouseWheel(GLFWwindow* window, double x, double y)
{
	state.mouseWheel.x = x;
	state.mouseWheel.y = y;
}

//======================================================================================================
void Input::Update()
{
	//This variable is declared locally 
	//so that it has no left over data
	//SDL_Event events;

	//isXClicked = false;
	//isWindowResized = false;
	state.mouseWheel = glm::ivec2(0);
	//mouseMotion = glm::ivec2(0);

	//keyStates = SDL_GetKeyboardState(nullptr);

	glfwPollEvents();
	
	
}