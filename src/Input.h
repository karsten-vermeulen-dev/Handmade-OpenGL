#pragma once
#include <SDL.h>
#include <glm.hpp>

#include "Screen.h"

//Massive WIP!
//Some helpful docs for GLFW events:
//https://www.glfw.org/docs/3.3/group__window.html
//https://www.glfw.org/docs/3.3/input_guide.html#events
//https://www.glfw.org/docs/3.3/group__input.html#ga1caf18159767e761185e49a3be019f8d

typedef const Uint8* KeyState;

class Input
{

public:

	/*enum class ButtonState
	{
		Up,
		Down
	};*/

	/*enum class CursorState
	{
		On = 1,
		Off = 0,
		Show = 1,
		Hide = 0
	};*/

	/*enum class CursorType
	{
		Arrow = SDL_SYSTEM_CURSOR_ARROW,
		IBeam = SDL_SYSTEM_CURSOR_IBEAM,
		Wait = SDL_SYSTEM_CURSOR_WAIT,
		Crosshair = SDL_SYSTEM_CURSOR_CROSSHAIR,
		WaitArrow = SDL_SYSTEM_CURSOR_WAITARROW,
		No = SDL_SYSTEM_CURSOR_NO,
		Hand = SDL_SYSTEM_CURSOR_HAND
	};*/

	static Input* Instance();

	struct State
	{
		int keyUp{ 0 };
		int keyDown{ 0 };
		bool isKeyPressed{ false };

		glm::dvec2 mouseWheel{ 0 };
		glm::dvec2 mouseMotion{ 0 };
		glm::dvec2 mousePosition{ 0 };

		bool isLeftButtonClicked{ false };
		bool isRightButtonClicked{ false };
		bool isMiddleButtonClicked{ false };
	};

	const State& GetState() const;

	//char GetKeyUp() const;
	//char GetKeyDown() const;
	//KeyState GetKeyStates() const;

	//bool IsXClicked() const;
	//bool IsKeyPressed() const;
	//bool IsWindowResized() const;

	//bool IsLeftButtonClicked() const;
	//bool IsRightButtonClicked() const;
	//bool IsMiddleButtonClicked() const;

	//const glm::ivec2& GetMouseWheel() const;
	//const glm::ivec2& GetMouseMotion() const;
	//const glm::ivec2& GetMousePosition() const;

	//void SetCursorType(CursorType cursorType = CursorType::Arrow);
	//void SetCursorState(CursorState cursorEnabled = CursorState::On,
		//CursorState cursorVisible = CursorState::Show);

	void AssignCallbacks(GLFWwindow* window);

	//GLFW will invoke these functions when keyboard and mouse are used
	static void OnMouseMove(GLFWwindow* window, double x, double y);
	static void OnMouseClick(GLFWwindow* window, int button, int action, int mods);
	static void OnKeyPress(GLFWwindow* window, int keyCode, int scancode, int action, int mods);
	static void OnMouseWheel(GLFWwindow* window, double x, double y);

	void Update();

private:

	Input() {}
	Input(const Input&);
	Input& operator=(const Input&);

	inline static State state;

	//inline static int keyUp{ 0 };
	//inline static int keyDown{ 0 };
	//inline static bool isKeyPressed{ false };

	//char keyUp{ 0 };
	//char keyDown{ 0 };

	//bool isWindowResized{ false };

	//KeyState keyStates{ nullptr };
	//SDL_Cursor* cursor{ nullptr };

};