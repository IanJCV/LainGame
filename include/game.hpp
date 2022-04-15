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

#ifndef GAME_HPP_
#define GAME_HPP_

#include <GLFW/glfw3.h>
#include <AL/alc.h>

extern GLFWwindow* Window;
extern ALCdevice* Device;
extern ALCcontext* Context;

extern void
GameLoop(void);

#endif /* GAME_H_ */
