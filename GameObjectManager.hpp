#ifndef _GAMEOBJECTMANAGER_HPP_
#define _GAMEOBJECTMANAGER_HPP_

#include "GameObject.hpp"
#include <vector>

class GameObjectManager {
	public:
		GameObjectManager();
		~GameObjectManager();
		
		void Insert(GameObject& NewObject);
		
		void Update(double ElapsedTime);
		void DrawAll();
	
	private:
		std::vector<GameObject> VisibleObjects;
};


#endif