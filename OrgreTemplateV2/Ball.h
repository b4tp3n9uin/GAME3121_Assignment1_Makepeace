#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"

class Ball
{
private:
	Ogre::SceneNode* ball_Model;
	Ogre::Vector2 position;
public:
	Ogre::Vector2 velocity;

	Ball(Ogre::Entity* ball_Entity, Ogre::SceneManager* m_SceneManager);
	Ball();
	~Ball();

	Ogre::SceneNode* GetModle() const;
	Ogre::Vector2 GetVelocity() const;
	Ogre::Vector2 GetPosition() const;

	void SetVelocity(Ogre::Vector2 vel);
	void SetPosition(Ogre::Vector3 pos);
	void Update(float deltaTime);

	void CheckBounds(float x, float y);
	void Reset();
};

