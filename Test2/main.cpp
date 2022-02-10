#include <SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		cout << "SDL Fail initialized!\n";

	else
		cout << "SDL initialized successfully!\n";

	system("pause");
	return 0;
}