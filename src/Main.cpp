//#include <SDL.h>
#include "App.h"
#include "Design.h"

//int main(int argc, char* args[])
int main()
{
	App app(new Design);
	app.Run();
	return 0;
}