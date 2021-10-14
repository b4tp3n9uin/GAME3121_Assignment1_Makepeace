#include "Bat.h"

Bat::Bat(Ogre::Entity* bat_Entity, Ogre::SceneManager* m_SceneManager)
{
	bat_Model = m_SceneManager->getRootSceneNode()->createChildSceneNode();
	bat_Model->setPosition(0, 0, 0);
	bat_Model->setScale(0.6f, 0.1f, 0.f);
	bat_Model->attachObject(bat_Entity);
}

Bat::Bat()
{
}

Bat::~Bat()
{
}

Ogre::SceneNode* Bat::GetModle() const
{
	return bat_Model;
}

Ogre::Vector2 Bat::GetVelocity() const
{
	return Ogre::Vector2();
}

Ogre::Vector2 Bat::GetPosition() const
{
	return position;
}

void Bat::SetVelocity(Ogre::Vector2 vel)
{
	this->velocity = vel;
}

void Bat::SetPosition(Ogre::Vector3 pos)
{
	bat_Model->setPosition(pos);
	this->position = Ogre::Vector2(position.x, position.y);
}

void Bat::Update(float deltaTime)
{

}
