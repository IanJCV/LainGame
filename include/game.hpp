#ifndef GAME_H_
#define GAME_H_

#include <GLFW/glfw3.h>
#include <AL/alc.h>

extern GLFWwindow* window;
extern ALCdevice* device;
extern ALCcontext* context;

extern void
game_loop(void);

#endif /* GAME_H_ */
