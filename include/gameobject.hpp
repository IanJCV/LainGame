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

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <vector>

class Component;
class GameObject;

class GameObject
{
	public:
		GameObject(void);
		GameObject(const char*);
		~GameObject(void);
		void Update(void);
		void LateUpdate(void);
		void Draw(void);

		const char* name;

		void AddComponent(Component*);
		void RemoveComponent(Component*);
		template<typename T> T GetComponent(); // static_assert(std::is_base_of<BaseClass, T>::value, "");

	private:
		std::vector<Component*> m_Components;
};

class Component
{
	public:
		virtual void Awake(void);		// Called on every Component first.
		virtual void Start(void);		// Called on every Component after Awake.
		virtual void Update(void);		// Called on every frame.
		virtual void LateUpdate(void);	// 
		virtual void OnEnable(void);	// 
		virtual void OnDisable(void);	// 
		virtual void OnDestroy(void);	// 
};

#endif /* GAMEOBJECT_HPP_ */
