#include "Ball.h"

Ball::Ball(Ogre::Entity* ball_Entity, Ogre::SceneManager* m_SceneManager)
{
	ball_Model = m_SceneManager->getRootSceneNode()->createChildSceneNode();
	ball_Model->setPosition(0, 25, 0);
	ball_Model->setScale(0.2f, 0.2f, 0.f);
	ball_Model->attachObject(ball_Entity);

	velocity = Ogre::Vector2().ZERO;
	position = Ogre::Vector2(0, 50);
}

Ball::Ball()
{
}

Ball::~Ball()
{
}

Ogre::SceneNode* Ball::GetModle() const
{
	return ball_Model;
}

Ogre::Vector2 Ball::GetVelocity() const
{
	return velocity;
}

Ogre::Vector2 Ball::GetPosition() const
{
	return position;
}

void Ball::SetVelocity(Ogre::Vector2 vel)
{
	this->velocity = vel;
}

void Ball::SetPosition(Ogre::Vector3 pos)
{
	ball_Model->setPosition(pos);
	this->position = Ogre::Vector2(position.x, position.y);
}

void Ball::Update(float deltaTime)
{
	position += velocity * deltaTime;
	this->SetPosition(Ogre::Vector3(position.x, position.y, 0.0f));
}

void Ball::CheckBounds(float x, float y)
{
	if (position.x > x * 0.5f)
		velocity.x *= -1.0f;
	if (position.x < -x * 0.5f)
		velocity.x *= -1.0f;
	if (position.y > y * 0.5f)
		velocity.y *= -1.0f;
}

void Ball::Reset()
{
	velocity.y *= -1.0f;
	position = Ogre::Vector2(0, 50);

	this->SetPosition(Ogre::Vector3::ZERO);
	this->SetVelocity(Ogre::Vector2(velocity.x, velocity.y));
}
