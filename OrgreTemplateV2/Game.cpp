#include "Game.h"


bool FrameListenerObserver::frameStarted(const Ogre::FrameEvent& evt)
{
    return true;
}

Game::Game()
    : ApplicationContext("GAME 3121 - Assignment 1, by Maathew Makepeace - 101179668")
{
}

//bool Game::frameStarted(const FrameEvent& evt)
//{
//
//    if (!GameOver && latestFrameRate < 30)
//    {
//        m_ball->Reset();
//    }
//
//    if (GameOver)
//    {
//        m_ball->SetPosition(Vector3(1000, 1000, 0));
//        m_ball->SetVelocity(Vector2(0, 0));
//        return true;
//    }
//
//    if (timeLastFrame < refreshTime)
//    {
//        timeLastFrame += evt.timeSinceLastFrame;
//        numFrames++;
//    }
//    else
//    {
//        latestFrameRate = (float)numFrames / timeLastFrame;
//        numFrames = 0;
//        timeLastFrame = 0.0f;
//
//        printf_s(buffer, "FPS: %.1f", latestFrameRate);
//        m_Fps->setCaption(buffer);
//    }
//
//    /*{
//        sprintf_s(buffer, "m/s %.5f", evt.timeSinceLastFrame);
//        m_TU->setCaption(buffer);
//    }*/
//
//    m_ball->CheckBounds(250, 220);
//    m_ball->Update(evt.timeSinceLastFrame);
//
//    m_bat->Update(evt.timeSinceLastFrame);
//
//    Vector2 ballPos = m_ball->GetPosition();
//    Vector2 batPos = m_bat->GetPosition();
//
//    Vector3 move = Vector3(evt.timeSinceLastFrame * 15.f, 0.f, 0.f);
//
//
//    if (ballPos.y < -30)
//    {
//        lives--;
//        if (lives <= 0)
//        {
//            GameOver = true;
//        }
//        else
//        {
//            m_ball->Reset();
//        }
//    }
//
//    if (ballPos.y < -10.0f && ballPos.y > -20.0f && ballPos.x > 60.0f && ballPos.x < -60.0f)
//    {
//        if (!onCollisionEnter)
//        {
//            onCollisionEnter = true;
//            m_ball->velocity.y *= -1.f;
//
//            score += 10;
//            this->refreshUserInterface();
//
//            Vector2 vel = m_ball->GetVelocity();
//
//        }
//    }
//    else
//    {
//        onCollisionEnter = false;
//    }
//
//    return true;
//}

bool Game::keyPressed(const KeyboardEvent& evt)
{
    if (GameOver)
        std::cout << "GAME OVER!!!" << std::endl;

    if (evt.keysym.sym == SDLK_RIGHT)
    {
        if (!GameOver) 
        {
            if (m_bat->posX > 45)
            {
                m_bat->posX = 44;
                m_bat->SetPosition(Vector3(m_bat->posX, m_bat->posY, 0));
            }
            else
            {
                m_bat->posX += 1.0f;
                float xPlace = m_bat->posX * m_bat->speed;
                m_bat->SetPosition(Vector3(xPlace, m_bat->posY, 0));
                CheckCollision(xPlace);
            }
        }
    }

    if (evt.keysym.sym == SDLK_LEFT)
    {
        if (!GameOver)
        {
            // Detect Collision with offscreen
            if (m_bat->posX < -45)
            {
                m_bat->posX = -44;
                m_bat->SetPosition(Vector3(m_bat->posX, m_bat->posY, 0));
            }
            else // If your not offscreen you can move.
            {
                m_bat->posX -= 1.0f;
                float xPlace = m_bat->posX * m_bat->speed;
                m_bat->SetPosition(Vector3(xPlace, m_bat->posY, 0));
                CheckCollision(xPlace);
            }
        }
    }

    BallMovement();

    // Quit the Game with Escape Button
    if (evt.keysym.sym == SDLK_ESCAPE)
    {
        getRoot()->queueEndRendering();
    }
    return true;
}

void Game::refreshUserInterface()
{
    {
        sprintf_s(buffer, "%d", score);
        m_Score->setCaption(buffer);
    }

    {
        sprintf_s(buffer, "%d", lives);
        m_Lives->setCaption(buffer);
    }
}

/// Initialize the game
void Game::setup()
{

    //! do not forget to call the base first
    ApplicationContext::setup();
    addInputListener(this);

    //! get a pointer to the already created root
    root = getRoot();
    scnMgr = root->createSceneManager();

    //! register our scene with the RTSS
    RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);

    createScene();
    createCamera();
    createUI();
    
    createFrameListener();


}

void Game::createScene()
{
    //! turnlights
    scnMgr->setAmbientLight(ColourValue(0.7, 0.0, 0.9));

    //! newlight
    Light* light = scnMgr->createLight("MainLight");
    SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->attachObject(light);

    //! lightpos
    lightNode->setPosition(20, 80, 50);

    // Create Bat and Ball

    Entity* ballEntity = scnMgr->createEntity(SceneManager::PrefabType::PT_SPHERE);
    Entity* batEntity = scnMgr->createEntity(SceneManager::PrefabType::PT_CUBE);

    ballNode = scnMgr->createSceneNode("Character");
    ballNode->attachObject(ballEntity);
    scnMgr->getRootSceneNode()->addChild(ballNode);
    ballNode->setPosition(Ogre::Vector3(0.0f, 0.0f, 0.0f));
    ballNode->setScale(0.1, 0.1, 0);

    //m_ball = std::make_shared<Ball>(ballEntity, scnMgr);

    m_bat = std::make_shared<Bat>(batEntity, scnMgr);
    m_bat->SetPosition(Vector3(0, -20, 0));
}

void Game::createCamera()
{
    //! camera
    SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();

    //! create the camera
    Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);
    camNode->setPosition(0, 0, 140);

    //! and tell it to render into the main window
    getRenderWindow()->addViewport(cam);

    //! cameramove
    camNode->setPosition(0, 47, 222);
}

void Game::createUI()
{
    mTrayMgr = new OgreBites::TrayManager("InterfaceName", getRenderWindow());
    /// @attention you must add mOverlaySystem to Render Queue Listener in order to add a tray
    scnMgr->addRenderQueueListener(mOverlaySystem);

    /// @note Once you have your tray manager, make sure you relay input events to it.
    addInputListener(mTrayMgr);

    m_NameLabel = mTrayMgr->createLabel(TL_TOP, "TInfo", "Matthew Makepeace", 200);

    m_FpsLabel = mTrayMgr->createLabel(TL_TOPRIGHT, "FPS", "FPS:", 150);
    m_Fps = mTrayMgr->createLabel(TL_TOPRIGHT, "fps", "60", 150);

    m_ScoreLabel = mTrayMgr->createLabel(TL_TOPLEFT, "Score", "Score:", 150);
    m_Score = mTrayMgr->createLabel(TL_TOPLEFT, "score", "0", 150);

    m_TULabel = mTrayMgr->createLabel(TL_TOPRIGHT, "Time/Update", "Time/Update:", 150);
    m_TU = mTrayMgr->createLabel(TL_TOPRIGHT, "tpu", "m/s: 0.1667", 150);

    m_LivesLabel = mTrayMgr->createLabel(TL_TOPLEFT, "Lives", "Lives: ", 150);
    m_Lives = mTrayMgr->createLabel(TL_TOPLEFT, "lives", "5", 150);
}

void Game::updateUI()
{
    {
        sprintf_s(buffer, "%d", score);
        m_Score->setCaption(buffer);
    }

    {
        sprintf_s(buffer, "%d", lives);
        m_Lives->setCaption(buffer);
    }
    
}

void Game::BallMovement()
{
    if (ballNode->getPosition().x > 100)
        velX = -4;
    if (ballNode->getPosition().x < -100)
        velX = 4;
    if (ballNode->getPosition().y > 120)
        velY = -4;

    if (ballNode->getPosition().y < -30) 
    {
        lives = lives - 1;

        updateUI();

        if (lives <= 0) 
        {
            ballNode->setPosition(Ogre::Vector3(1000.0f, 100.0f, 0.0f));
            velX = 0;
            velY = 0;
            GameOver = true;
        }
        else 
        {
            ballNode->setPosition(Ogre::Vector3(0.0f, 0.0f, 0.0f));
            velY = 4;
        }
    }

    ballNode->translate(velX, velY, 0);
}

void Game::CheckCollision(float batX)
{
    Vector3 ballPos = ballNode->getPosition();

    if (ballPos.y < -10 && ballPos.y > -20 && ballPos.x > batX - 35 && ballPos.x < batX + 35)
    {
        velY = 5;
        score += 10;
        updateUI();
    }
}

void Game::createFrameListener()
{
    Ogre::FrameListener* FrameListener = new FrameListenerObserver(ballNode);
    mRoot->addFrameListener(FrameListener);
}
