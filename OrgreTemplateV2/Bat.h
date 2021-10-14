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
	/**
	* @brief (bat_Model) Prefab type sphere to represent the rectangle paddle.
	*/
	Ogre::SceneNode* bat_Model;
	
	/**
	* @brief (velocity) Current velocity of the bat.
	*/
	Ogre::Vector2 velocity;
	
	/**
	* @brief (position) Current position of the bat.
	*/
	Ogre::Vector2 position;

	
public:

	/// Constructor for the bat class.
	/// 
	/// @param bat_Entity A refrence to the entity you want to use.
	/// @param scnMgr A refrence to the scene manager.
	Bat(Ogre::Entity* bat_Entity, Ogre::SceneManager* m_SceneManager);
	
	/// Constructor.
	/// 
	/// @param no parameters
	Bat();
	
	/// Destructor.
	/// 
	/// @param no parameters
	~Bat();

	/**
   * @brief bat's x position
   * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
   */
	float posX = 0.0f;

	/**
   * @brief bat's y position
   * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
   */
	float posY = -20.f;

	/**
   * @brief speed of the bat
   * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
   */
	float speed = 2.0f;

	/// Gets the Shape of the bat.
	/// 
	/// @param no parameters
	/// @returns Returns the shape as a Ogre::SceneNode reference
	Ogre::SceneNode* GetModle() const;

	/// Gets the bat's velocity.
	/// 
	/// @param no parameters
	/// @returns Returns the position as an Ogre::Vector2
	Ogre::Vector2 GetVelocity() const;

	/// Gets the position of the bat.
	/// 
	/// @param no parameters
	/// @returns Returns the position as an Ogre::Vector2
	Ogre::Vector2 GetPosition() const;

	/// Set bat's velocity.
	/// 
	/// @param (vel) velocity is to be set
	/// @returns no return type
	void SetVelocity(Ogre::Vector2 vel);

	/// Set bat's position.
	/// 
	/// @param (pos) bat
	/// @returns no return type
	void SetPosition(Ogre::Vector3 pos);

	/// update
	///
	/// called once per frame  
	/// @param (deltaTime) time elapsed since previous frame.
	/// @returns no return type
	void Update(float deltaTime);


};

