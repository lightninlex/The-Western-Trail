unsigned long previousMillisRaid = 0;  // Separate variable for Raid timing
void handleRaid() {
  static int screen = 0;
  const long interval = 2000;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisRaid >= interval) {
    previousMillisRaid = currentMillis;
    int fightOutcome = random(25);  // Generate a random number between 0 and 24
    bool fightSuccess = fightOutcome < 15;  // 15 out of 25 chance for success
    int foodLost = random(1, 15);
    int moneyLost = random(1, 15);
    int healthLost;
    switch (screen) {
      case 0:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Raid!");
        screen++;
        break;
      case 1:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("1.Fight 2.Flee");
        screen++;
        break;
      case 2:
        updateButtonState();
        if (buttonState[0]) { // Player chose to fight
          healthLost = fightSuccess ? 1 : 5;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(fightSuccess ? "Victory!" : "Defeat...");
          lcd.setCursor(0, 1);
          lcd.print("Rest now.");
          health = max(health - healthLost, 0);  // Health loss here
          if (!fightSuccess) {
            food = max(food - foodLost, 0);  // Food loss only on defeat
            money = max(money - moneyLost, 0);  // Money loss only on defeat
          }
          screen++;
          if (fightSuccess) {
            food = max(food + foodLost, 0);  // Food gain upon victory
            money = max(money + moneyLost, 0);  // Money gain upon victory
          }
        } else if (buttonState[1]) { // Player chose to flee
          healthLost = 1;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Fleeing...");
          lcd.setCursor(0, 1);
          lcd.print("Find safe camp");
          health = max(health - healthLost, 0);  // Health loss here
          food = max(food - foodLost, 0);  // Food loss on fleeing
          money = max(money - moneyLost, 0);  // Money loss on fleeing
          screen++;
        }
        break;
      case 3:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Status update");
        screen = 0;  // Reset to the first screen
        currentState = ACTION_SELECT;  // Transition back to action select
        break;
    }
  }
}