void handleThiefEncounter() {
  static int screen = 0;
  int moneyGained = random(1, 20);
  int healthLost = random(1, 5);
  int moneyLost = random(1, 15);
  int healthLostFlee = random(1, 5);
  int fightOutcome = random(25);  // Generate a random number between 0 and 24
  bool fightSuccess = fightOutcome < 15;  // 15 out of 25 chance for success
  const long interval = 2000;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    switch (screen) {
      case 0:
        displayThiefScreen("Thief!");
        screen++;
        break;
      case 1:
        displayThiefScreen("1.Fight 2.Flee");
        screen++;
        break;
      case 2:
        updateButtonState();
        if (buttonState[0]) {  // Player chose to fight
          displayThiefScreen(fightSuccess ? "**WHAM!**" : "OWCH!");
          screen = fightSuccess ? 3 : 4;  // Jump to the victory or defeat screen
        } else if (buttonState[1]) {  // Player chose to flee
          displayThiefScreen("Escaped!");
          screen = 6;  // Jump to the flee screen
        }
        break;
      case 3:
        money = max(money + moneyGained, 0);
        displayThiefScreen("Money +:", String(moneyGained).c_str());
        screen = 7;
        break;
      case 4:
        health = max(health - healthLost, 0);
        money = max(money - moneyLost, 0);
        displayThiefScreen("Health -:", String(healthLost).c_str());
        screen++;
        break;
      case 5:
        displayThiefScreen("Money -:", String(moneyLost).c_str());
        screen = 7;
        break;
      case 6:
        health = max(health - healthLostFlee, 0);
        displayThiefScreen("Health -:", String(healthLostFlee).c_str());
        screen = 7;
        break;
      case 7:
        screen = 0;
        currentState = ACTION_SELECT;
        break;
    }
  }
}
