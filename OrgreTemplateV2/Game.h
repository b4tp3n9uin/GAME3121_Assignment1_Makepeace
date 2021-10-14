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

/// Game class
///
/// Main base class for the game. Inherits from Application Listener and Input Listener. Any type of keyboard/mouse event based entities should be done from here
/// @see Bat
/// @see Ball
class Game
    : public ApplicationContext
    , public InputListener
{
public:
    /// Constructor
    ///
    /// called in main.cpp .
    Game();

    /// Virtual Destructor
    ///
    /// called after application quits.
    virtual ~Game() {}

    /// called when key is pressed.
    /// 
    /// @returns boolean always true.
    /// @param evt reference to keyboard event.
    bool keyPressed(const KeyboardEvent& evt);


    void refreshUserInterface();

    /// called when the game is constructed.
    /// 
    /// @param no parameters
    void setup();

    /// creates the bat, ball and lights in the game scene.
    /// 
    /// @returns no return type
    /// @param no parameters
    void createScene();
    void createCamera();
    void createUI();

    /// refresh all Labels in the Game UI.
    /// 
    /// @returns no return type
    /// @param no parameters
    void updateUI();

    /// checks for the movement of the ball in the game class
    /// 
    /// @returns no return type
    /// @param no parameters
    void BallMovement();

    /// checks collisions of the ball whether its with the paddle or the boundaries.
    /// 
    /// @returns no return type
    /// @param (batX) recieves the x position of the paddle.
    void CheckCollision(float batX);

    /// Creates the frame listener for any updates.
    /// 
    /// @returns no return type
    /// @param no parameters
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
