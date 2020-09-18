// This is the main file for the game logic and function
#include "game.h"
#include "entity.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "map.h"
#include "ghostgameover.h"
#include "hudstuff.h"
#include <string>
#include "minigame.h"
#include <stdlib.h>
#include <time.h>

double  g_dElapsedTime;
double  g_dDeltaTime;
double g_dGOghostTime;
double g_dFishTime;
double FishTime;
double g_dLanternTime;
double g_dFlickerTime;
double ghostSpeed;
bool fullLantern;
bool halfLantern;
bool dimLantern;
bool offFlicker;
bool onFlicker;
int rand1, rand2, rand3, rand4, randfish;
SKeyEvent g_skKeyEvent[K_COUNT];
SMouseEvent g_mouseEvent;

int x;
int y;


map Map;


// Game specific variables here
SGameChar   g_sChar;
SGameChar   g_sDoor;
SGameChar   g_sCameraState;
SGameChar   g_sFish;
EGAMESTATES g_eGameState = S_MAINMENU; // initial state
EGAMESTATES currentStage = S_STAGE1;
STAGE1states S1State = S1_INIT;
STAGE2states S2State = S2_INIT;
STAGE3states S3State = S3_INIT;

bool lose = false;

// Console object
Console g_Console(80, 30, "SP1 Framework");

//UI, HUD etc
button playButton(13, 3, "Play", 40, 12);
button quitButton(13, 3, "Quit", 40, 24);
button resumeButton(13, 3, "Resume", 40, 12);
button retryButton(13, 3, "Retry", 40, 12);
button stagesButton(13, 3, "Stages", 40, 18);
button backButton(13, 3, "Main Menu", 40, 18);
button S1Button(13, 3, "Stage 1", 40, 6);
button S2Button(13, 3, "Stage 2", 40, 10);
button S3Button(13, 3, "Stage 3", 40, 14);
button PressureButton(13, 3, "Pressure MG", 40, 22);
button PowerButton(13, 3, "Power MG", 40, 26);

button* selectedButton = &playButton;
int buttonIndex = 0;
button* mainButtons[3] = { &playButton, &stagesButton, &quitButton };
int mainButtonsCount = 3;
button* pauseButtons[3] = { &resumeButton, &backButton, &quitButton };
int pauseButtonsCount = 3;
button* stageButtons[6] = {&S1Button, &S2Button, &S3Button, &backButton, &PressureButton, &PowerButton};
int stageButtonsCount = 6;
button* loseButtons[3] = {&retryButton, &backButton, &quitButton};
int loseButtonsCount = 3;

bool WButtonDown = false;
bool SButtonDown = false;
bool SpaceButtonDown = false;
bool paused = false;
bool isMousePressed = false;
menuStates MState;

std::string objective = " ";

// Game objects
entity* ghost = nullptr;
entity* plasma = nullptr;

//Animation objects
ghostgameover ghostGO;

//HUD drawings
hudstuff drawings;

//cutscenes
button dialogueBox(77, 7, "doesnt matter for now ack", 39, 24);
cutscene horrorIntro(8);
cutscene helloGhost(1);
cutscene scubaSuit(1);
cutscene escape(1);
int sceneIndex = 0;

//minigames
minigame mini;

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init( void )
{
    srand(time(NULL));

    fullLantern = false;
    halfLantern = false;
    dimLantern = false;
    offFlicker = false;
    onFlicker = false;
    // Set precision for floating point output
    g_dElapsedTime = 0.0;    
    g_dGOghostTime = 0.0;

    // sets the initial state for the game
    g_eGameState = S_MAINMENU;
    MState = MENU_MAIN;

    //if camera true
    g_sChar.m_cLocation.X = g_Console.getConsoleSize().X / 2;
    g_sChar.m_cLocation.Y = 10;

    //if camera false
    //g_sChar.m_cLocation.X = 40; 
    //g_sChar.m_cLocation.Y = 18;

    g_sChar.m_bActive = true;
    g_sCameraState.counter = true; // camera follow
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

    // remember to set your keyboard handler, so that your functions can be notified of input events
    g_Console.setKeyboardHandler(keyboardHandler);
    g_Console.setMouseHandler(mouseHandler);

    //isMousePressed = false;
    //setButtons();
    Map.maparray(g_Console);
    x = 40;
    y = 5;
    

    //setting of cutscene dialogues
    horrorIntro.setStory(0, "Rawbert: Have you heard of the story of the haunted submarine(AW-4 Nawtilus)?");
    horrorIntro.setStory(1, "Jawhn: AW-4 Nawtilus? Do you mean that abandoned submarine at the corner that has not been boarded by anyone for the past 10 years?");
    horrorIntro.setStory(2, "Rawbert: Yes! They say that 10 years ago, a female reporter boarded the AW-4 Nawtilus along with a professor to interview him about the submarine.");
    horrorIntro.setStory(3, " However, the submarine went missing, both of them were never seen again and the mystery behind it still isn't solved till this day.");
    horrorIntro.setStory(4, "You: One cool summer night, you decided to go out for a walk to take a breather.");
    horrorIntro.setStory(5, "While walking, you started to see flashes of light at the corner of your eye. You turned to see what it was, and you saw a rusty-looking submarine by the shore.");
    horrorIntro.setStory(6, "So you went to take a closer look and realised that the model number of the submarine was AW-4 Nawtilus.");
    horrorIntro.setStory(7, "You then decided to take a look inside the submarine, hoping to solve the mystery.");
    helloGhost.setStory(0, "ghost appear whoosh");
    scubaSuit.setStory(0, "AAAA");
    escape.setStory(0, "AAAA");
    

    //minigames (camera state to false)
    g_sDoor.counter = true;
    g_sFish.startTimer = false;
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();

    delete ghost;
}

//--------------------------------------------------------------
// Purpose  : Get all the console input events
//            This function sets up the keyboard and mouse input from the console.
//            We will need to reset all the keyboard status, because no events will be sent if no keys are pressed.
//
//            Remember to set the handlers for keyboard and mouse events.
//            The function prototype of the handler is a function that takes in a const reference to the event struct
//            and returns nothing. 
//            void pfKeyboardHandler(const KEY_EVENT_RECORD&);
//            void pfMouseHandlerconst MOUSE_EVENT_RECORD&);
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput( void )
{
    // resets all the keyboard events
    memset(g_skKeyEvent, 0, K_COUNT * sizeof(*g_skKeyEvent));
    // then call the console to detect input from user
    g_Console.readConsoleInput();    
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the keyboard input. Whenever there is a keyboard event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            The KEY_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any keyboard event in the Splashscreen state
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent - reference to a key event struct
// Output   : void
//--------------------------------------------------------------
void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent)
{    
    gameplayKBHandler(keyboardEvent);
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the mouse input. Whenever there is a mouse event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            For the mouse event, if the mouse is not moved, no event will be sent, hence you should not reset the mouse status.
//            However, if the mouse goes out of the window, you would not be able to know either. 
//
//            The MOUSE_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any mouse event in the Splashscreen state
//            
// Input    : const MOUSE_EVENT_RECORD& mouseEvent - reference to a mouse event struct
// Output   : void
//--------------------------------------------------------------
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{    
    gameplayMouseHandler(mouseEvent);
}

//--------------------------------------------------------------
// Purpose  : This is the keyboard handler in the game state. Whenever there is a keyboard event in the game state, this function will be called.
//            
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent)
{
    // here, we map the key to our enums
    EKEYS key = K_COUNT;
    switch (keyboardEvent.wVirtualKeyCode)
    {
    case VK_SPACE: key = K_SPACE; break;
    case VK_ESCAPE: key = K_ESCAPE; break; 
    case VK_RETURN: key = K_ENTER; break;
    case 0x57: key = K_W; break;
    case 0x41: key = K_A; break;
    case 0x53: key = K_S; break;
    case 0x44: key = K_D; break;

    }
    // a key pressed event would be one with bKeyDown == true
    // a key released event would be one with bKeyDown == false
    // if no key is pressed, no event would be fired.
    // so we are tracking if a key is either pressed, or released
    if (key != K_COUNT)
    {
        g_skKeyEvent[key].keyDown = keyboardEvent.bKeyDown;
        g_skKeyEvent[key].keyReleased = !keyboardEvent.bKeyDown;
    }    
}

//--------------------------------------------------------------
// Purpose  : This is the mouse handler in the game state. Whenever there is a mouse event in the game state, this function will be called.
//            
//            If mouse clicks are detected, the corresponding bit for that mouse button will be set.
//            mouse wheel, 
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{
    if (mouseEvent.dwEventFlags & MOUSE_MOVED) // update the mouse position if there are no events
    {
        g_mouseEvent.mousePosition = mouseEvent.dwMousePosition;
    }
    g_mouseEvent.buttonState = mouseEvent.dwButtonState;
    g_mouseEvent.eventFlags = mouseEvent.dwEventFlags;
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;
    g_dGOghostTime += dt;
    g_dLanternTime += dt;
    g_dFlickerTime += dt;
    FishTime += dt;
    g_dFishTime += dt;

    if (!paused)
    {
        switch (g_eGameState)
        {
        case S_MAINMENU: mainMenuWait();
            break;
        case S_STAGESMENU: stagesMenuWait();
            break;
        case S_INTRO: playCutScene(horrorIntro);
            //play cutscene of horror story + enter submarine and then submarine go off course
            //if (end of cutscene) set state to STAGE1
            break;
        case S_STAGE1: playSTAGE1();
            break;
        case S_GHOST: playCutScene(helloGhost);
            //play cutscene of ghost on steering wheel
            //if (end of cutscene) set state to STAGE2
            break;
        case S_STAGE2: playSTAGE2();
            break;
        case S_SCUBA: playCutScene(scubaSuit);
            //play cutscene
            break;
        case S_STAGE3: updateGame();
            break;
        case S_SWIM: updateGame();
            break;
        case S_gameOverGhost: update_gameOverGhost();
            break;
        case S_LOSE: loseMenuWait();
            break;
        case S_PRESSUREGAME: update_pressureMini();
            break;
        }
    }
    else
    {
        pauseMenuWait();
    }
}

void initSTAGE1()
{
    //set spawnpoints; etc
    objective = "Go to Control Room testingtingswhEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";
    S1State = S1_GAME;
    currentStage = S_STAGE1;
    
}

void playSTAGE1()
{
    switch (S1State)
    {
    case S1_INIT: 
        initSTAGE1();
        break;
    case S1_GAME:
        updateGame();
        if (x >= 121)
        {
            g_eGameState = S_GHOST;
        }
        break;
    }
}

void initSTAGE2()
{
   
    g_dLanternTime = 0.0;
    ghost = new entity(x + 10, y);
    S2State = S2_GAME;
    currentStage = S_STAGE2;
}

void playSTAGE2()
{
    switch (S2State)
    {
    case S2_INIT:
        initSTAGE2();
        break;
    case S2_GAME:
        if (lose)
        {
            g_eGameState = S_gameOverGhost;
        }
        updateGame();
        break;
    }
}

void updateGame()       // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
                        // sound can be played here too.
    
    if (g_dLanternTime > 0) //full lantern
    {
        fullLantern = true;
        halfLantern = false;
        dimLantern = false;
    }
    if (g_dLanternTime > 10) //half lantern
    {
        halfLantern = true;
        fullLantern = false;
        dimLantern = false;
        
        static bool flickerTime = false;
        if (flickerTime == false)
        {
            g_dFlickerTime = 0.0;
            flickerTime = true;
        }
        
        if (g_dFlickerTime > 0.5 && g_dFlickerTime < 1.1)
        {
            offFlicker = true;
            onFlicker = false;
        }
        if (offFlicker == true && g_dFlickerTime > 1.1 && g_dFlickerTime < 1.6)
        {
            onFlicker = true;
            offFlicker = false;
        }
        if (onFlicker == true && g_dFlickerTime > 1.6)
        {
            g_dFlickerTime = 0.0;
            onFlicker = false;
        }
    }
    
    if (g_dLanternTime > 25) //dim lantern
    {
        dimLantern = true;
        fullLantern = false;
        halfLantern = false;
        offFlicker = false;
        onFlicker = false;
    }
    
}

void update_gameOverGhost()
{
    if (g_dGOghostTime > 10)
    {
        selectedButton = &retryButton;
        g_eGameState = S_LOSE;
        MState = MENU_LOSE;
    }
    processUserInput();
}

void gameOverGhost()
{ 
    COORD c;
    ghostGO.initGridGhost(g_Console);
    ghostGO.GhostSprite1(g_Console);
    
    if (g_dGOghostTime > 0.3)
    {
        ghostGO.GhostSprite2(g_Console);
        if (g_dGOghostTime > 0.6)
        {
            ghostGO.GhostSprite3(g_Console);
            if (g_dGOghostTime > 0.9)
            {
                ghostGO.GhostSprite4(g_Console);
                if (g_dGOghostTime > 1.2)
                {
                    ghostGO.GhostSprite5(g_Console);
                    if (g_dGOghostTime > 1.5)
                    {
                        ghostGO.GhostSprite6(g_Console);
                        if (g_dGOghostTime > 1.8)
                        {
                            ghostGO.GhostSprite7(g_Console);
                            if (g_dGOghostTime > 2.1)
                            {
                                ghostGO.GhostSprite8(g_Console);
                                if (g_dGOghostTime > 2.4)
                                {
                                    ghostGO.GhostSprite9(g_Console);
                                    if (g_dGOghostTime > 2.7)
                                    {
                                        ghostGO.GhostSprite10(g_Console);
                                        if (g_dGOghostTime > 3.0)
                                        {
                                            ghostGO.GhostSprite11(g_Console);
                                            if (g_dGOghostTime > 3.3)
                                            {
                                                ghostGO.GhostSprite12(g_Console);
                                                if (g_dGOghostTime > 3.6)
                                                {
                                                    ghostGO.GhostSprite13(g_Console);
                                                    if (g_dGOghostTime > 3.9)
                                                    {
                                                        ghostGO.GhostSprite14(g_Console);
                                                        if (g_dGOghostTime > 4.2)
                                                        {
                                                            ghostGO.GhostSprite15(g_Console);
                                                            if (g_dGOghostTime > 4.5)
                                                            {
                                                                ghostGO.GhostSprite16(g_Console);
                                                                if (g_dGOghostTime > 4.8)
                                                                {
                                                                    ghostGO.GhostSprite17(g_Console);
                                                                    if (g_dGOghostTime > 5.1)
                                                                    {
                                                                        ghostGO.GhostSprite18(g_Console);
                                                                        if (g_dGOghostTime > 5.4)
                                                                        {
                                                                            ghostGO.GhostSprite19(g_Console);
                                                                            if (g_dGOghostTime > 5.7)
                                                                            {
                                                                                ghostGO.GhostSprite20(g_Console);
                                                                                if (g_dGOghostTime > 6.0)
                                                                                {
                                                                                    ghostGO.GhostSprite21(g_Console);
                                                                                    if (g_dGOghostTime > 6.3)
                                                                                    {
                                                                                        ghostGO.GhostSprite22(g_Console);
                                                                                        if (g_dGOghostTime > 6.6)
                                                                                        {
                                                                                            ghostGO.GhostSprite23(g_Console);
                                                                                            if (g_dGOghostTime > 6.9)
                                                                                            {
                                                                                                ghostGO.GhostSprite24(g_Console);
                                                                                                if (g_dGOghostTime > 7.2)
                                                                                                {
                                                                                                    ghostGO.GhostSprite25(g_Console);
                                                                                                    if (g_dGOghostTime > 7.5)
                                                                                                    {
                                                                                                        ghostGO.GhostSprite26(g_Console);
                                                                                                        if (g_dGOghostTime > 7.8)
                                                                                                        {
                                                                                                            ghostGO.GhostSprite27(g_Console);
                                                                                                            if (g_dGOghostTime > 8.1)
                                                                                                            {
                                                                                                                ghostGO.GhostSprite28(g_Console);
                                                                                                                if (g_dGOghostTime > 9.5)
                                                                                                                {
                                                                                                                    ghostGO.GhostSprite29(g_Console);
                                                                                                                    if (g_dGOghostTime > 9.6)
                                                                                                                    {
                                                                                                                        ghostGO.GhostSprite30(g_Console);
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void fishLeft(Console& g_Console, int j)
{
    COORD c;
    if (g_dFishTime > 1)
    {
        mini.fishLeft(g_Console, 22, j);
        if (g_dFishTime > 1.3)
        {
            mini.fishLeft(g_Console, 24, j);
            if (g_dFishTime > 1.6)
            {
                mini.fishLeft(g_Console, 26, j);
                if (g_dFishTime > 1.9)
                {
                    mini.fishLeft(g_Console, 28, j);
                    if (g_dFishTime > 2.2)
                    {
                        mini.fishLeft(g_Console, 30, j);
                        if (g_dFishTime > 2.5)
                        {
                            mini.fishLeft(g_Console, 32, j);
                            if (g_dFishTime > 2.8)
                            {
                                mini.fishLeft(g_Console, 34, j);
                                if (g_dFishTime > 3.1)
                                {
                                    mini.fishLeft(g_Console, 36, j);
                                    if (g_dFishTime > 3.4)
                                    {
                                        mini.fishLeft(g_Console, 38, j);
                                        if (g_dFishTime > 3.7)
                                        {
                                            mini.fishLeft(g_Console, 40, j);
                                            if (g_dFishTime > 4.0)
                                            {
                                                mini.fishLeft(g_Console, 42, j);
                                                if (g_dFishTime > 4.3)
                                                {
                                                    mini.fishLeft(g_Console, 44, j);
                                                    if (g_dFishTime > 4.6)
                                                    {
                                                        mini.fishLeft(g_Console, 46, j);
                                                        if (g_dFishTime > 4.9)
                                                        {
                                                            mini.fishLeft(g_Console, 48, j);
                                                            if (g_dFishTime > 5.2)
                                                            {
                                                                mini.fishLeft(g_Console, 50, j);
                                                                if (g_dFishTime > 5.5)
                                                                {
                                                                    mini.fishLeft(g_Console, 52, j);
                                                                    if (g_dFishTime > 5.8)
                                                                    {
                                                                        mini.fishLeft(g_Console, 54, j);
                                                                        if (g_dFishTime > 6.1)
                                                                        {
                                                                            mini.fishLeft(g_Console, 55, j);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void update_pressureMini()
{
    processUserInput();
    moveCharacter();
    if (FishTime > 1)
    {
        g_sFish.startTimer = false;
    }
    if (g_dFishTime > 6.4)
    {
        g_sFish.startTimer = true;
        g_sFish.counter = true;
    }
}

void pressureMini()
{
    mini.initialiseMap(g_Console);
    mini.pressureMap(g_Console);
    //randomise doors
    if (g_sDoor.counter == true)
    {
        rand1 = rand() % 35 + 21;
        rand2 = rand() % 35 + 21;
        rand3 = rand() % 35 + 21;
        rand4 = rand() % 35 + 21;
        g_sDoor.counter = false;
    }
    mini.pressureDoors(g_Console, rand1, 2);
    mini.pressureDoors(g_Console, rand2, 4);
    mini.pressureDoors(g_Console, rand3, 6);
    mini.pressureDoors(g_Console, rand4, 8);
    mini.pressureDoors(g_Console, rand3, 10);
    mini.pressureDoors(g_Console, rand2, 12);
    mini.pressureDoors(g_Console, rand1, 14);
    mini.pressureDoors(g_Console, rand4, 16);
    mini.pressureWin(g_Console, rand1, 1);
    mini.fishLeft(g_Console, 52, 17);
    mini.pressureBorder(g_Console);

    //fish randomise 
    if (g_sFish.startTimer == true)
    {
        g_dFishTime = 0.0;
        g_sFish.resetTimer = true;
    }
    if (g_sFish.resetTimer == true)
    {
        if (g_sFish.counter == true)
        {
            randfish = rand() % 15 + 3;
        }
        g_sFish.counter = false;
        fishLeft(g_Console, randfish); 
    }

    mini.pressureBorder(g_Console);
    renderCharacter();

    //check if player collides with fish
    if ((mini.miniGrid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '<') || (mini.miniGrid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '>'))
    {
        g_dGOghostTime = 0.0;
        g_eGameState = S_gameOverGhost;
        g_sDoor.counter = true;
        g_sCameraState.counter = true; //changes back to original camera state
        g_sChar.m_cLocation.X = g_Console.getConsoleSize().X / 2; //resets position of character
        g_sChar.m_cLocation.Y = 10;
    }
    //spawn back to other map
    if (mini.miniGrid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '@')
    {
        g_sDoor.counter = true;
        g_sCameraState.counter = true; //changes back to original camera state
        g_eGameState = S_STAGE1; //goes back to stage 1
        g_sChar.m_cLocation.X = g_Console.getConsoleSize().X / 2; //resets position of character
        g_sChar.m_cLocation.Y = 10;
    }

    // ^insert HUD after the maparray function
    for (int i = 0; i < 81; i++)
    {
        for (int j = 20; j < 30; j++)
        {
            g_Console.writeToBuffer(i, j, " ", 0x0F);
        }
    }
}

void moveCharacter()
{    
    // Updating the location of the character based on the key release
    // providing a beep sound whenver we shift the character

    //moving camera

    if (g_sCameraState.counter == true)
    {
        if (g_skKeyEvent[K_W].keyDown && g_sChar.m_cLocation.Y > 0)
        {
            if (Map.map[y - 1][x] != '+' && Map.map[y - 1][x] != 'O') // collision for + and O
            {
                Map.map[y][x] = ' ';
                Map.map[y - 1][x] = 'P';
                y--;
            }
        }
        if (g_skKeyEvent[K_A].keyDown && g_sChar.m_cLocation.X > 0)
        {
            if (Map.map[y][x - 1] != '+' && Map.map[y][x - 1] != 'O')
            {
                Map.map[y][x] = ' ';
                Map.map[y][x - 1] = 'P';
                x--;
            }
        }
        if (g_skKeyEvent[K_S].keyDown && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
        {
            if (Map.map[y + 1][x] != '+' && Map.map[y + 1][x] != 'O')
            {
                Map.map[y][x] = ' ';
                Map.map[y + 1][x] = 'P';
                y++;
            }
        }
        if (g_skKeyEvent[K_D].keyDown && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
        {
            if (Map.map[y][x + 1] != '+' && Map.map[y][x + 1] != 'O')
            {
                Map.map[y][x] = ' ';
                Map.map[y][x + 1] = 'P';
                x++;
            }
        }
        if (g_skKeyEvent[K_SPACE].keyDown)
        {
            g_sChar.m_bActive = !g_sChar.m_bActive;
        }
    }

    else if (g_sCameraState.counter == false)
    {
        int i, j;
        i = g_sChar.m_cLocation.X;
        j = g_sChar.m_cLocation.Y;
        if (g_skKeyEvent[K_W].keyDown && g_sChar.m_cLocation.Y > 1)
        {
            if (mini.miniGrid[i][j - 1] != '-')
            {
                g_sChar.m_cLocation.Y--;
            }
        }
        if (g_skKeyEvent[K_A].keyDown && g_sChar.m_cLocation.X > 21)
        {
            if (mini.miniGrid[i - 1][j] != '-')
            {
                g_sChar.m_cLocation.X--;
            }
        }
        if (g_skKeyEvent[K_S].keyDown && g_sChar.m_cLocation.Y < 18)
        {
            if (mini.miniGrid[i][j + 1] != '-')
            {
                g_sChar.m_cLocation.Y++;
            }
        }
        if (g_skKeyEvent[K_D].keyDown && g_sChar.m_cLocation.X < 58)
        {
            if (mini.miniGrid[i + 1][j] != '-')
            {
                g_sChar.m_cLocation.X++;
            }
        }
    }

    //ghost chase
    int dirx;
    int diry;
    int thedir;
    if (ghost != nullptr)
    {
        int diffinx = x - ghost->getPos().getx();
        int diffiny = y - ghost->getPos().gety();

        if (diffinx > 0)
        {
            dirx = 4;
        }
        else
        {
            dirx = 3;
        }

        if (diffiny > 0)
        {
            diry = 2;
        }
        else
        {
            diry = 1;
        }

        if (2 * abs(diffinx) > abs(diffiny))
        {
            thedir = dirx;
        }
        else
        {
            thedir = diry;
        }

        if (Map.map[ghost->getnextPos(1).gety()][ghost->getnextPos(1).getx()] == '+' && Map.map[ghost->getnextPos(2).gety()][ghost->getnextPos(2).getx()] == '+')
        {
            if (thedir == dirx)
            {
                thedir = diry;
            }
            else
            {
                thedir = dirx;
            }
        }

        if (diffinx == 0 && diffiny == 0)
        {
            lose = true;
        }

        ghost->setDirection(thedir);

        ghostSpeed += g_dDeltaTime;
        if (ghostSpeed >= 0.25)
        {
            ghostSpeed = 0;
            ghost->updatePos();
            if (Map.map[ghost->getPos().gety()][ghost->getPos().getx()] == '+')
            {
                ghost->updatePos();
            }
        }
    }
}

void processUserInput()
{
    // quits the game if player hits the escape key
    if (g_skKeyEvent[K_ESCAPE].keyReleased)
    {
        //g_bQuitGame = true;
        paused = true;
        MState = MENU_PAUSE;
        selectedButton = &resumeButton;
        buttonIndex = 0;
    }

    /*if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED && checkButtonClick(pauseButton))
    {
        paused = true;
        MState = MENU_PAUSE;
    }*/
}

//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
    clearScreen();      // clears the current screen and draw from scratch 

    if (g_eGameState != S_MAINMENU && g_eGameState != S_gameOverGhost)
    {
        //black bg
        for (int i = 0; i < 81; i++)
        {
            for (int j = 20; j < 30; j++)
            {
                g_Console.writeToBuffer(i, j, " ", 0x0F);
            }
        }

        //Box Corners
        COORD pos;
        pos.X = 0;
        pos.Y = 20;
        g_Console.writeToBuffer(pos, (char)201, 0x0F);
        pos.Y = 29;
        g_Console.writeToBuffer(pos, (char)200, 0x0F);
        pos.X = 79;
        pos.Y = 20;
        g_Console.writeToBuffer(pos, (char)187, 0x0F);
        pos.Y = 29;
        g_Console.writeToBuffer(pos, (char)188, 0x0F);
    }

    switch (g_eGameState)
    {
    case S_MAINMENU: renderMainMenu();
        break;
    case S_STAGESMENU: renderStagesMenu();
        break;
    case S_INTRO: renderDialogue(horrorIntro);
        break;
    case S_GHOST: renderDialogue(helloGhost);
        break;
    case S_SCUBA: renderDialogue(scubaSuit);
        break;
    case S_SWIM:
        break;
    case S_gameOverGhost: gameOverGhost();
        break;
    case S_LOSE: renderLoseMenu();
        break;
    case S_PRESSUREGAME: pressureMini();
        break;
    default:
        renderGame();
        break;
    }
    //renderFramerate();      // renders debug information, frame rate, elapsed time, etc
    renderInputEvents();    // renders status of input events
    if (paused)
    {
        renderPauseMenu();
    }
    renderToScreen();       // dump the contents of the buffer to the screen, one frame worth of game
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x00);
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}

void renderSplashScreen()  // renders the splash screen
{
    COORD c = g_Console.getConsoleSize();
    c.Y /= 3;
    c.X = c.X / 2 - 9;
    g_Console.writeToBuffer(c, "A game in 3 seconds", 0x0C);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 20;
    g_Console.writeToBuffer(c, "Press <Space> to change character colour", 0x0D);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 9;
    g_Console.writeToBuffer(c, "Press 'Esc' to quit", 0x0D);
}

void renderGame()
{
    if ((g_skKeyEvent[K_SPACE].keyDown) && ((y == 11 && x == 33) || (y == 13 && x == 33) || (y == 12 && x == 32) || (y == 12 && x == 34)))
    {
        g_dLanternTime = 0.0;
        fullLantern = true;
        halfLantern = false;
        dimLantern = false;
    }
    if ((g_skKeyEvent[K_SPACE].keyDown) && ((y == 1 && x == 118) || (y == 3 && x == 118) || (y == 2 && x == 117) || (y == 2 && x == 119)))
    {
        g_dLanternTime = 0.0;
        fullLantern = true;
        halfLantern = false;
        dimLantern = false;
    }
    if ((g_skKeyEvent[K_SPACE].keyDown) && ((y == 26 && x == 74) || (y == 28 && x == 74) || (y == 27 && x == 73) || (y == 27 && x == 75)))
    {
        g_dLanternTime = 0.0;
        fullLantern = true;
        halfLantern = false;
        dimLantern = false;
    }
    if ((g_skKeyEvent[K_SPACE].keyDown) && ((y == 13 && x == 16) || (y == 15 && x == 16) || (y == 14 && x == 15) || (y == 14 && x == 17)))
    {
        g_dLanternTime = 0.0;
        fullLantern = true;
        halfLantern = false;
        dimLantern = false;
    }
    if ((g_skKeyEvent[K_SPACE].keyDown) && ((y == 13 && x == 135) || (y == 15 && x == 135) || (y == 14 && x == 134) || (y == 14 && x == 136)))
    {
        g_dLanternTime = 0.0;
        fullLantern = true;
        halfLantern = false;
        dimLantern = false;
    }

    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
    renderGhost();
    if (offFlicker == true)
    {
        drawings.LanternDim(g_Console);
        //dimLantern = true;
        //halfLantern = false;
    }
    if (onFlicker == true)
    {
        drawings.LanternHalf(g_Console);
        //dimLantern = false;
        //halfLantern = true;
    }
}

void renderMap()
{
    COORD c;
    if (fullLantern == true)
    {
        Map.renderFullLantern(g_Console, x, y); //full lantern
    }
    else if (halfLantern == true)
    {
        Map.renderHalfLantern(g_Console, x, y); //half lantern
    }
    else if (dimLantern == true)
    {
        Map.renderDimLantern(g_Console, x, y); //dim lantern
    }
    else
    {
        Map.rendermap(g_Console, x, y); //full screen
    }

    
    /*for (int i = 0; i < 81; i++)
    {
        for (int j = 20; j < 30; j++)
        {
            g_Console.writeToBuffer(i, j, " ", 0x0F);
        }
    }*/
    renderHUD();
    c.X = 20;
    c.Y = 21;
    std::string srr = std::to_string(x);
    g_Console.writeToBuffer(c, srr, 0x0F);
    c.Y = 22;
    std::string srrs = std::to_string(y);
    g_Console.writeToBuffer(c, srrs, 0x0F);
}

void renderCharacter()
{
    // Draw the location of the character
    WORD charColor = 0x0C;
    if (g_sChar.m_bActive)
    {
        charColor = 0x71;
    }
    g_Console.writeToBuffer(g_sChar.m_cLocation, (char)12, charColor);
}

void renderGhost()
{
    COORD pos;
    if (ghost != nullptr)
    {
        pos.X = ghost->getPos().getx() - x + 40;
        pos.Y = ghost->getPos().gety() - y + 10;
        g_Console.writeToBuffer(pos, (char)71, 0x7D);
    }
}

void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 9;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str(), 0x59);
}

// this is an example of how you would use the input events
void renderInputEvents()
{
    // keyboard events
    COORD startPos = {50, 2};
    std::ostringstream ss;
    std::string key;
    /*for (int i = 0; i < K_COUNT; ++i)
    {
        ss.str("");
        switch (i)
        {
        case K_W: key = "W";
            break;
        case K_S: key = "S";
            break;
        case K_A: key = "A";
            break;
        case K_D: key = "D";
            break;
        case K_SPACE: key = "SPACE";
            break;
        default: continue;
        }
        if (g_skKeyEvent[i].keyDown)
            ss << key << " pressed";
        else if (g_skKeyEvent[i].keyReleased)
            ss << key << " released";
        else
            ss << key << " not pressed";

        COORD c = { startPos.X, startPos.Y + i };
        g_Console.writeToBuffer(c, ss.str(), 0x17);
    }*/

    // mouse events    
    ss.str("");
    ss << "Mouse position (" << g_mouseEvent.mousePosition.X << ", " << g_mouseEvent.mousePosition.Y << ")";
    g_Console.writeToBuffer(g_mouseEvent.mousePosition, ss.str(), 0x59);
    ss.str("");
    switch (g_mouseEvent.eventFlags)
    {
    case 0:
        if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            ss.str("Left Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 1, ss.str(), 0x59);
        }
        else if (g_mouseEvent.buttonState == RIGHTMOST_BUTTON_PRESSED)
        {
            ss.str("Right Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x59);
        }
        else
        {
            ss.str("Some Button Pressed");
            g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 3, ss.str(), 0x59);
        }
        break;
    case DOUBLE_CLICK:
        ss.str("Double Clicked");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 4, ss.str(), 0x59);
        break;        
    case MOUSE_WHEELED:
        if (g_mouseEvent.buttonState & 0xFF000000)
            ss.str("Mouse wheeled down");
        else
            ss.str("Mouse wheeled up");
        g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 5, ss.str(), 0x59);
        break;
    default:        
        break;
    }
    
}

void renderMainMenu()
{
    

    renderButton(playButton);
    renderButton(stagesButton);
    renderButton(quitButton);


    renderSelectedButton();

}

void renderPauseMenu()
{
    renderButton(resumeButton);
    renderButton(backButton);
    renderButton(quitButton);

    renderSelectedButton();
}

void renderStagesMenu()
{
    //black bg
    for (int i = 0; i < 30; i++)
    {
        g_Console.writeToBuffer(0, 0 + i, "                                                                                ", 0x00);
    }

    for (int i = 0; i < stageButtonsCount; i++)
    {
        renderButton(*stageButtons[i]);
    }

    renderSelectedButton();
}

void renderLoseMenu()
{
    renderButton(retryButton);
    renderButton(backButton);
    renderButton(quitButton);

    renderSelectedButton();
}

void renderHUD()
{
    COORD pos;
    
    switch (g_eGameState)
    {
    case S_PRESSUREGAME:
        //render pressure level;
        break;

    default:
        //lantern
        if (fullLantern == true)
        {
            drawings.LanternFull(g_Console);

        }
        if (halfLantern == true)
        {
            drawings.LanternHalf(g_Console);
        }
        if (dimLantern == true)
        {
            drawings.LanternDim(g_Console);
        }

        //objective
        pos.X = 50;

        for (int i = 0; i < (objective.length() / 29) + 1; i++)
        {
            pos.Y = 22 + i;
            if (i == objective.length() / 29)
            {
                g_Console.writeToBuffer(pos, objective.substr(29 * i, objective.length() - (29 * i)), 0x05);
            }
            else
            {
                g_Console.writeToBuffer(pos, objective.substr(29 * i, 29), 0x05);
            }
        }
        break;
    }
        
    
}

void renderButton(button& button)
{
    COORD pos;
    for (int y = button.getCorner(0).gety(); y <= button.getCorner(2).gety(); y++)
    {
        for (int x = button.getCorner(0).getx(); x <= button.getCorner(1).getx(); x++)
        {
            pos.X = x;
            pos.Y = y;
            g_Console.writeToBuffer(pos, " ", 0xF4);
        }
    }

    pos.X = button.getPos().getx() - (button.getText().length() / 2);
    pos.Y = button.getPos().gety();
    g_Console.writeToBuffer(pos, button.getText(), 0xF4);
}

void renderSelectedButton()
{
    //selected button highlight
    COORD pos;
    for (int x = (*selectedButton).getCorner(0).getx() - 1; x <= (*selectedButton).getCorner(1).getx() + 1; x++)
    {
        pos.X = x;
        pos.Y = (*selectedButton).getCorner(0).gety() - 1;
        g_Console.writeToBuffer(pos, " ", 0x44);
        pos.Y = (*selectedButton).getCorner(2).gety() + 1;
        g_Console.writeToBuffer(pos, " ", 0x44);
    }
    for (int y = (*selectedButton).getCorner(0).gety(); y <= (*selectedButton).getCorner(2).gety(); y++)
    {
        pos.Y = y;
        pos.X = (*selectedButton).getCorner(2).getx() - 1;
        g_Console.writeToBuffer(pos, " ", 0x44);
        pos.X = (*selectedButton).getCorner(3).getx() + 1;
        g_Console.writeToBuffer(pos, " ", 0x44);
    }
}

void mainMenuWait()
{
   
    checkButtonSelect(mainButtonsCount);

    if (g_skKeyEvent[K_SPACE].keyDown)
    {

        switch (buttonIndex)
        {
        case 0:
            g_eGameState = S_INTRO;
            g_dLanternTime = 0.0; // put this to stage 2
            break;
        case 1:
            MState = MENU_STAGES;
            g_eGameState = S_STAGESMENU;
            selectedButton = &S1Button;
            break;
        case 2:
            g_bQuitGame = true;
            break;
        }
        buttonIndex = 0;

    }
}

void pauseMenuWait()
{
    checkButtonSelect(pauseButtonsCount);

    if (g_skKeyEvent[K_SPACE].keyDown)
    {
        switch (buttonIndex)
        {
        case 0:
            paused = false;
            break;
        case 1:
            paused = false;
            g_eGameState = S_MAINMENU;
            MState = MENU_MAIN;
            S1State = S1_INIT;
            S2State = S2_INIT;
            S3State = S3_INIT;
            selectedButton = &playButton;
            break;
        case 2:
            g_bQuitGame = true;
            break;
        }
        buttonIndex = 0;
    }
}

void stagesMenuWait()
{
    checkButtonSelect(stageButtonsCount);

    if (g_skKeyEvent[K_SPACE].keyDown)
    {
        switch (buttonIndex)
        {
        case 0:
            g_eGameState = S_INTRO;
            S1State = S1_INIT;
            break;
        case 1:
            g_eGameState = S_GHOST;
            S2State = S2_INIT;
            break;
        case 2:
            g_eGameState = S_SCUBA;
            S3State = S3_INIT;
        case 3:
            g_eGameState = S_MAINMENU;
            MState = MENU_MAIN;
            selectedButton = &playButton;
            break;
        case 4:
            g_eGameState = S_PRESSUREGAME;
            break;
        case 5:
            break;
        }
        buttonIndex = 0;
    }
}

void loseMenuWait()
{
    checkButtonSelect(loseButtonsCount);

    if (g_skKeyEvent[K_SPACE].keyDown)
    {
        switch (buttonIndex)
        {
        case 0:
            g_eGameState = currentStage;
            S1State = S1_INIT;
            S2State = S2_INIT;
            S3State = S3_INIT;
            break;
        case 1:
            g_eGameState = S_MAINMENU;
            MState = MENU_MAIN;
            S1State = S1_INIT;
            S2State = S2_INIT;
            S3State = S3_INIT;
            selectedButton = &playButton;
            break;
        case 2:
            g_bQuitGame = true;
            break;
        }
        buttonIndex = 0;
        lose = false;
    }
}

bool checkButtonClick(button button)
{
    if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
    {
        if (isMousePressed == false)
        {
            isMousePressed = true;

            if (g_mouseEvent.mousePosition.X >= button.getCorner(0).getx() && g_mouseEvent.mousePosition.Y >= button.getCorner(0).gety()
                && g_mouseEvent.mousePosition.X <= button.getCorner(1).getx() && g_mouseEvent.mousePosition.Y <= button.getCorner(2).gety())
            {
                return true;
            }
        }
    }
    else
    {
        isMousePressed = false;
    }
    return false;
}

void checkButtonSelect(int a)
{
    if (g_skKeyEvent[K_W].keyDown)
    {
        if (WButtonDown == false && buttonIndex > 0)
        {
            WButtonDown = true;
            changeButton(false);
        }
    }
    else
    {
        WButtonDown = false;
    }
    if (g_skKeyEvent[K_S].keyDown)
    {
        if (SButtonDown == false && buttonIndex < a - 1)
        {
            SButtonDown = true;
            changeButton(true);
        }
    }
    else
    {
        SButtonDown = false;
    }
}

void changeButton(bool down)
{
    if (down) 
    {
        buttonIndex++;
    }
    else
    {
        buttonIndex--;
    }

    switch (MState)
    {
    case MENU_MAIN:
        selectedButton = mainButtons[buttonIndex];
        break;
    case MENU_PAUSE:
        selectedButton = pauseButtons[buttonIndex];
        break;
    case MENU_STAGES:
        selectedButton = stageButtons[buttonIndex];
        break;
    case MENU_LOSE:
        selectedButton = loseButtons[buttonIndex];
        break;
    }
}

void playCutScene(cutscene& scene)
{
    if (g_skKeyEvent[K_SPACE].keyDown && SpaceButtonDown == false)
    {
        if (sceneIndex + 1 == scene.getnoofLines())
        {
            switch (g_eGameState)
            {
            case S_INTRO:
                g_eGameState = S_STAGE1;
                break;
            case S_GHOST:
                g_eGameState = S_STAGE2;
                break;
            case S_SCUBA:
                g_eGameState = S_STAGE3;
                break;
            }
            sceneIndex = 0;
        }
        else 
        {
            sceneIndex++;
        }
        SpaceButtonDown = true;
    }
    else if (g_skKeyEvent[K_SPACE].keyReleased)
    {
        SpaceButtonDown = false;
    }

    if (g_skKeyEvent[K_ENTER].keyDown) 
    {
        switch (g_eGameState)
        {
        case S_INTRO:
            g_eGameState = S_STAGE1;
            break;
        case S_GHOST:
            g_eGameState = S_STAGE2;
            break;
        case S_SCUBA:
            g_eGameState = S_STAGE3;
            break;
        }

        sceneIndex = 0;
    }
}

void renderDialogue(cutscene& scene)
{
    COORD pos;

    //dialogue
    pos.X = 1;

    for (int i = 0; i < (scene.getLine(sceneIndex).length() / 77) + 1; i++)
    {
        pos.Y = 21 + i;
        if (i == scene.getLine(sceneIndex).length() / 77)
        {
            g_Console.writeToBuffer(pos, scene.getLine(sceneIndex).substr(77 * i, scene.getLine(sceneIndex).length() - (77 * i)), 0x0F);
        }
        else
        {
            g_Console.writeToBuffer(pos, scene.getLine(sceneIndex).substr(77 * i, 77), 0x0F);
        }
    }
}

