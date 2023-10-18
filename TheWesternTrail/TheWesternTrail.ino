#include <Wire.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
// Define the pins for the buttons
#define BUTTON1 22
#define BUTTON2 23
#define BUTTON3 24
#define BUTTON4 25
#define BUTTON5 6
// Define the pins for the lcd
#define RS 26
#define E 27
#define D4 28
#define D5 29
#define D6 30
#define D7 31
// Name the lcd, and define the array used by the lcd
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
// Set all states within gameplay
enum GameState {
  MAIN_MENU, START_GAME, HELP, ACTION_SELECT, TRAVELLING, HUNTING, TRADING, RESTING, INJURY, STORM, RAID, DAMAGE, THIEF_ENCOUNTER, ANIMAL_ATTACK, WIN, MONEY_LOSE, FOOD_LOSE, HEALTH_LOSE,
};
// The title menu of "The Western Trail"
GameState currentState = MAIN_MENU;
const int BUTTONS[] = {22, 23, 24, 25, 6}; // Array declaring all buttons
bool buttonState[] = {false, false, false, false, false}; // logic function to reference the state of all buttons
// Game parameters-win/loss conditions and values for player reference, indicating game progress
int distance = 0;
const int WIN_DISTANCE = 1000;
int health = 20;
const int MIN_HEALTH = 0;
const int MAX_HEALTH = 20;
int food = 25;
const int MIN_FOOD = 0;
const int MAX_FOOD = 50;
int money = 25;
const int MIN_MONEY = 0;
const int MAX_MONEY = 50;
  unsigned long previousMillis = 0;
  unsigned long previousMillisHunting = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Initialize the lcd
	 for (int i = 0; i < 5; i++) {  // Initialize the buttons as inputs, with pull-up resistance
	pinMode(BUTTONS[i], INPUT_PULLUP);
  }
    randomSeed(analogRead(0));
}
void updateButtonState() {  // Logic to check the button states
  for (int i = 0; i < 5; i++) {
	buttonState[i] = !digitalRead(BUTTONS[i]);
  }
}
void displayThiefScreen(const char* line1, const char* line2 = "") {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}


void loop() {
  ResourceMeter();
  checkLoseConditions();
  updateButtonState();
  switch (currentState) {
	case MAIN_MENU:     handleMainMenu();     break;
	case START_GAME:    handleStartGame();    break;
	case HELP:          handleHelp();         break;
	case ACTION_SELECT: handleActionSelect(); break;
	case TRAVELLING:    handleTravelling();   break;
	case HUNTING:       handleHunting();      break;
	case TRADING:       handleTrading();      break;
	case RESTING:       handleResting();      break;
	case INJURY:        handleInjury();       break;
	case STORM:         handleStorm();        break;
	case RAID:          handleRaid();         break;
	case DAMAGE:        handleDamage();       break;
	case THIEF_ENCOUNTER: handleThiefEncounter(); break;
  case ANIMAL_ATTACK: handleANIMAL_ATTACK(); break;
	case WIN:           handleWin();          break;
	case HEALTH_LOSE:          handleHlose();         break;
	case FOOD_LOSE:          handleFlose();         break;
	case MONEY_LOSE:          handleMlose();         break;

  }
  delay(100);
}