/* Copyright 2021-2022 by Ian JCV, 'Emil' Williams
 *
 * LainGame is libre software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, under version 3 of the License.
 *
 * LainGame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LainGame. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h> // fprintf
#include <stdlib.h> // atexit

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <AL/alc.h>

#include "game.hpp"

#ifndef VERSION

#ifdef _MSC_BUILD // Compiling with VC++
	#pragma message ("No version provided.")
#else // Using something else, probably GCC.
	#warning No version provided.
#endif

#define VERSION ""
#endif

extern void
Init(void);
extern void
End(void);
extern void
ErrorCallback(int, const char*);

GLFWwindow* Window;
ALCdevice* Device;
ALCcontext* Context;

int
main(void)
{
	Init();

	// we can turn this into a class or have a normal:
	//game_init();

	GameLoop();

	return 0;
}

void
Init(void)
{
	// add file to input setting information

	if (!glfwInit())
	{
		exit(-1);
	}

	atexit(End);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window = glfwCreateWindow(1920, 1080, "Lain " VERSION, NULL, NULL);

	if (Window == NULL)
	{
		exit(-1);
	}

	glfwMakeContextCurrent(Window);

	Device = alcOpenDevice(NULL);

	if (Device)
	{
		Context = alcCreateContext(Device, NULL);

		alcMakeContextCurrent(Context);
	}
	else
	{
		fprintf(stderr, "OpenAL Error: %d\n", alcGetError(Device));
		exit(-1);
	}

	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

void
End(void)
{
	alcDestroyContext(Context);
	alcCloseDevice(Device);
	glfwDestroyWindow(Window);
	glfwTerminate();
}

void
ErrorCallback(int error, const char* desc)
{
	fprintf(stderr, "GLFW Error: %s\n", desc);
}
