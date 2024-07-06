#include <SDL.h>
#include "App.h"
#include "Design.h"

int main(int argc, char* args[])
{
	App app(new Design);
	app.Run();
	return 0;
}