#pragma once
#include "Ball.h"
#include "Bat.h"
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"
#include <iostream>

using namespace Ogre;
using namespace OgreBites;

class FrameListenerObserver : public Ogre::FrameListener
{
private:
    Ogre::SceneNode* _node;
public:

    class FrameListenerObserver(Ogre::SceneNode* node)
    {
        _node = node;
    }

    bool frameStarted(const Ogre::FrameEvent& evt);

    std::shared_ptr<Ball> ball;
};

class Game
    : public ApplicationContext
    , public InputListener
{
public:

    Game();
    virtual ~Game() {}

    //bool frameStarted(const FrameEvent& evt);
    bool keyPressed(const KeyboardEvent& evt);
    void refreshUserInterface();
    void setup();
    void createScene();
    void createCamera();
    void createUI();
    void updateUI();
    void GameOverUI();
    void BallMovement();
    void CheckCollision(float batX);
    void createFrameListener();

    OgreBites::TrayManager* mTrayMgr;
    OgreBites::TrayListener myTrayListener;
    OgreBites::Label* m_NameLabel;
    OgreBites::Label* m_FpsLabel;
    OgreBites::Label* m_Fps;

    OgreBites::Label* m_ScoreLabel;
    OgreBites::Label* m_Score;

    OgreBites::Label* m_TULabel;
    OgreBites::Label* m_TU;

    OgreBites::Label* m_LivesLabel;
    OgreBites::Label* m_Lives;

    std::shared_ptr<Ball> m_ball;
    std::shared_ptr<Bat> m_bat;

private:
    SceneNode* ballNode;
    SceneManager* scnMgr;
    Root* root;

    int score = 0;
    int lives = 5;

    bool GameOver = false;

    float velX = 4.f;

    float velY = 4.f;

    char buffer[50];
};
