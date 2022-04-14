#include <stdio.h> // fprintf
#include <stdlib.h> // atexit

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <AL/alc.h>

#include "game.hpp"

#ifndef VERSION
#warning No version provided.
#define VERSION ""
#endif

extern void
init(void);
extern void
bind(void);
extern void
end(void);
void
error_callback(int,
	       const char*);


GLFWwindow* window;
ALCdevice* device;
ALCcontext* context;

int
main(void)
{
	init();

	// we can turn this into a class or have a normal
	//game_init();

	game_loop();

	return 0;
}

void
init(void)
{
	// add file to input setting information

	if (!glfwInit())
	{
		exit(-1);
	}

	atexit(end);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1920, 1080, "Lain " VERSION, NULL, NULL);

	if (window == NULL)
	{
		exit(-1);
	}

	glfwMakeContextCurrent(window);

	device = alcOpenDevice(NULL);

	if (device)
	{
		context = alcCreateContext(device, NULL);

		alcMakeContextCurrent(context);
	}
	else
	{
		fprintf(stderr, "OpenAL Error: %d\n", alcGetError(device));
		exit(-1);
	}

	gladLoadGL(glfwGetProcAddress);
}

void
bind(void)
{
	
}

void
end(void)
{
	alcDestroyContext(context);
	alcCloseDevice(device);
	glfwDestroyWindow(window);
	glfwTerminate();
}

void
error_callback(int error,
	       const char* desc)
{
	fprintf(stderr, "GLFW Error: %s\n", desc);
}
