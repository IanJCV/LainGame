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

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <vector>
#include "gameobject.hpp"

namespace Scene
{
    class Scene;
    class SceneData;

    class Scene
    {
        public:
            Scene();
            Scene(const char*);
            ~Scene();
            void Update();
            void Draw();

            GameObject* GetObject(int); // Returns a pointer to the object at the given index.
            GameObject* GetObjectCount(); // Returns the number of objects in the scene.

            char* GetName(); // Returns the name of the scene.

        private:
            void Init();

            const char* name;
            std::vector<int> m_Objects;

            friend SceneData;
    };
    
    struct SceneData
    {
        SceneData(Scene*);
        ~SceneData();

    };
}

#endif // SCENE_HPP_