#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"

/// Pong Ball
/// 
/// The class that manages the ball in Pong
class Ball
{
private:
	/**
	* @brief (ball_Model) Prefab type sphere to represent the ball.
	*/
	Ogre::SceneNode* ball_Model;

	/**
	* @brief (position) Current position of the ball.
	*/
	Ogre::Vector2 position;
public:
	/**
	* @brief (velocity) Current velocity of the ball.
	*/
	Ogre::Vector2 velocity;

	/// Constructor for the ball class.
	/// 
	/// @param ball_Entity A refrence to the entity you want to use
	/// @param scnMgr A refrence to the scene managerwhat 
	Ball(Ogre::Entity* ball_Entity, Ogre::SceneManager* m_SceneManager);

	/// Constructor.
	/// 
	/// @param no parameters
	Ball();

	/// Destructor.
	/// 
	/// @param no parameters
	~Ball();

	/// Gets the Shape of the ball.
	/// 
	/// @param no parameters
	/// @returns Returns the shape as a Ogre::SceneNode reference
	Ogre::SceneNode* GetModle() const;

	/// Gets the ball's velocity.
	/// 
	/// @param no parameters
	/// @returns Returns the position as an Ogre::Vector2
	Ogre::Vector2 GetVelocity() const;

	/// Gets the ball's position.
	/// 
	/// @param no parameters
	/// @returns Returns the position as an Ogre::Vector2
	Ogre::Vector2 GetPosition() const;

	/// Set ball's velocity.
	/// 
	/// @param (vel) velocity is to be set
	/// @returns no return type
	void SetVelocity(Ogre::Vector2 vel);

	/// Set ball's position.
	/// 
	/// @param (vel) position is to be set
	/// @returns no return type
	void SetPosition(Ogre::Vector3 pos);

	/// update
	///
	/// called once per frame  
	/// @param (deltaTime) time elapsed since previous frame.
	/// @returns no return type
	void Update(float deltaTime);

	/// checkbounds
	///
	/// performs an AABB collision test and deflects ball velocity accordingly 
	/// @param (x) check the x position of ball.
	/// @param (y) check the y position of ball.
	/// @returns no return type
	void CheckBounds(float x, float y);

	/// reset
	///
	/// this method is called the moment the ball leaves the boundary.
	/// @param no parameters
	/// @returns no return type
	void Reset();
};

