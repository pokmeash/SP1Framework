#ifndef _GAME_H
#define _GAME_H
#include "entity.h"
#include "button.h"
#include "cutscene.h"
#include "Framework\timer.h"

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;

// struct to store keyboard events
// a small subset of KEY_EVENT_RECORD
struct SKeyEvent
{
    bool keyDown;
    bool keyReleased;
};

// struct to store mouse events
// a small subset of MOUSE_EVENT_RECORD
struct SMouseEvent
{
    COORD mousePosition;
    DWORD buttonState;
    DWORD eventFlags;
};

// Enumeration to store the control keys that your game will have
enum EKEYS
{
    K_W,
    K_A,
    K_S,
    K_D,
    K_ESCAPE,
    K_SPACE,
    K_ENTER,
    K_COUNT
};

// Enumeration for the different screen states
enum EGAMESTATES
{
    S_MAINMENU,
    S_INTRO, //cutscene
    S_STAGE1,
    S_GHOST, //cutscene of appearance of ghost and power out
    S_STAGE2, //obj: go to power room and play minigame
    S_SCUBA, //cutscene for intro of 5minute timer and etc info
    S_STAGE3, //5 minutes
    S_SWIM, //cutscene/escape
    S_gameOverGhost, //ghost jumpscare
    S_PRESSUREGAME, //pressure minigame
    S_COUNT
    
};

enum STAGE1states
{
    S1_INIT,
    S1_GAME
};

enum STAGE2states
{
    S2_INIT,
    S2_GAME
};

enum STAGE3states
{
    S3_INIT,
    S3_GAME
};

enum menuStates
{
    MENU_MAIN,
    MENU_PAUSE
};

// struct for the game character
struct SGameChar : public entity
{
    COORD m_cLocation;
    bool  m_bActive;
    bool counter;
};

void init        ( void );      // initialize your variables, allocate memory, etc
void getInput    ( void );      // get input from player
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void updateGame();          // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderGame();          // renders the game stuff
void renderMap();           // renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderGhost();
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void renderInputEvents();   // renders the status of input events
void renderMainMenu();
void renderPauseMenu();
void renderHUD();
void mainMenuWait();
void pauseMenuWait();

//Game States
void initSTAGE1();
void playSTAGE1();
void initSTAGE2();
void playSTAGE2();

//UI, HUD tings
bool checkButtonClick(button button);
void changeButton(bool down);

//cutscene tings
void playCutScene(cutscene& scene);
void renderDialogue(cutscene& scene);

// keyboard and mouse input event managers
void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent);  // define this function for the console to call when there are keyboard events
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent);      // define this function for the console to call when there are mouse events

void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent);   // handles keyboard events for gameplay 
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent); // handles mouse events for gameplay 

//Game over ghost animation
void update_gameOverGhost();
void gameOverGhost();

//Minigames
void update_pressureMini();
void pressureMini();

#endif // _GAME_H