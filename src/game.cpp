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

#include "game.hpp"

void
game_loop(void)
{
	double last = glfwGetTime();
	double delta = 0;

	double accum = 0;

	const double FPS = 60.0f;

	while (!glfwWindowShouldClose(window))
	{
		delta = glfwGetTime() - last;
		last  = glfwGetTime();
		accum += delta;

		if (accum > 1.0f/62.0f)
		{

			// input
			glfwPollEvents();

			//update();

			accum -= 1.0f/60.0f;
		}

		//draw();

		glfwSwapBuffers(window);

		//sleep(1.0f / FPS) / (end - last));
	}
}
