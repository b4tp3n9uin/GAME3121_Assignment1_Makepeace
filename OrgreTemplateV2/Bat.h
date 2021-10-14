#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"

/// Pong Bat
/// 
/// The class that manages the player controlled Paddle
class Bat
{
private:
	Ogre::SceneNode* bat_Model;
	Ogre::Vector2 velocity;
	Ogre::Vector2 position;

	
public:
	Bat(Ogre::Entity* bat_Entity, Ogre::SceneManager* m_SceneManager);
	Bat();
	~Bat();

	float posX = 0.0f;
	float posY = -20.f;
	float speed = 2.0f;

	Ogre::SceneNode* GetModle() const;
	Ogre::Vector2 GetVelocity() const;
	Ogre::Vector2 GetPosition() const;

	void SetVelocity(Ogre::Vector2 vel);
	void SetPosition(Ogre::Vector3 pos);
	void Update(float deltaTime);


};

