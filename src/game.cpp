#include "game.hpp"

void
game_loop(void)
{
	while (!glfwWindowShouldClose(window))
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}
