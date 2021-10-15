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

    /**
    * @brief Tray Manager for the GUI.
    */
    OgreBites::TrayManager* mTrayMgr;

    /**
    * @brief Tray listener used for GUI.
    */
    OgreBites::TrayListener myTrayListener;

    /**
   * @brief Graphic User Interface label used to render my name.
   */
    OgreBites::Label* m_NameLabel;

    /**
   * @brief Graphic User Interface label used as fps title.
   */
    OgreBites::Label* m_FpsLabel;

    /**
   * @brief Graphic User Interface label used as fps digits.
   */
    OgreBites::Label* m_Fps;

    /**
   * @brief Graphic User Interface label used as score title.
   */
    OgreBites::Label* m_ScoreLabel;

    /**
   * @brief Graphic User Interface label used as score digits.
   */
    OgreBites::Label* m_Score;

    /**
   * @brief Graphic User Interface label used as time update title
   */
    OgreBites::Label* m_TULabel;

    /**
   * @brief Graphic User Interface label used as time update digits
   */
    OgreBites::Label* m_TU;

    /**
   * @brief Graphic User Interface label used as lives title
   */
    OgreBites::Label* m_LivesLabel;

    /**
   * @brief Graphic User Interface label used as lives digit.
   */
    OgreBites::Label* m_Lives;

    /**
    * @brief A reference to the ball.
    * @see Ball
    */
    std::shared_ptr<Ball> m_ball;

    /**
    * @brief A reference to the bat.
    * @see Bat
    */
    std::shared_ptr<Bat> m_bat;

private:

    /**
    * @brief A reference to the ball scene node passed to the FrameListener.
    */
    SceneNode* ballNode;

    /**
    * @brief A reference to the Scene Manager
    */
    SceneManager* scnMgr;

    /**
    * @brief A reference root of the ogre class.
    */
    Root* root;

    /**
    * @brief game score
    */
    int score = 0;

    /**
    * @brief lives counter
    */
    int lives = 5;

    /**
    * @brief bool variable that determines if game over (if GameOver = true, Game Over).
    */
    bool GameOver = false;

    /**
    * @brief velocity for the Ball Scene Node
    */
    float velX = 4.f;

    /**
    * @brief velocity for the Ball Scene Node
    */
    float velY = 4.f;

    /**
    * @brief character stream for setting the captions for all GUI elements.
    */
    char buffer[50];
};
