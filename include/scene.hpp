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
	struct SceneData;

	class Scene
	{
		public:
			Scene(void);
			Scene(const char*);
			~Scene(void);
			void Update(void);
			void Draw(void);

			// we should minimize getters/setters
			// may as well be public...
			GameObject* GetObject(int); // Returns a pointer to the object at the given index.
			GameObject* GetObjectCount(void); // Returns the number of objects in the scene.

			// just make it public
			char* GetName(void); // Returns the name of the scene.
		

		private:
			// init should be public to allow resetting a scene without deleting the obj.
			void Init(void);

			// if we make these public...
			// modification IS possible but our code shouldn't do that so no worries.
			const char* name;
			std::vector<int> m_Objects;

			friend SceneData;
	};
	
	// Scene asset data.
	typedef struct SceneData
	{
		/*
		 * maybe a group of data pointers?
		 *
		 * imagepng* image;
		 * font* font;
		 * wavfrm* wv;
		 *
		 * also this should be blindly coupled to Scene, meaning it doesn't know anything to maximize portability.
		 * this would remove the need for freinding, but allowing freinds is a good way to push data then, removing blindness.
		 * friending can be reduced with public data, where we agree it should only be modif by scenedat.
		 */

		SceneData(Scene*);
		~SceneData(void);
	} SceneData;
}

#endif /* SCENE_HPP_ */
