unsigned long previousMillisAnimalAttack = 0;
void handleANIMAL_ATTACK() {
          int healthLostFlee = 1;  // Small health loss on flee
          int foodGained = random(1, 6);
          int healthLost = random(1, 4);
  const long interval = 2000;
  unsigned long currentMillis = millis();
   if (currentMillis - previousMillisAnimalAttack >= interval) {
      previousMillisAnimalAttack = currentMillis;
      static int screen = 0;
      int fightOutcome = random(25);
      bool fightSuccess = fightOutcome < 15;
    switch (screen) {
      case 0:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Wild animal!");
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
        if (buttonState[0]) {  // Player chose to fight
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("-censored by-");
          lcd.setCursor(0, 1);
          lcd.print("PETA");
          screen++;
        } else if (buttonState[1]) {  // Player chose to flee
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("RUNN OFT");
          screen += 3;
        }
        break;
      case 3:
        if (fightSuccess) {
          food += foodGained;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Food +:");
          lcd.setCursor(0, 1);
          lcd.print(foodGained);
          screen = 4;  
        } else {

          health = max(health - healthLost, 0);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Health -:");
          lcd.setCursor(0, 1);
          lcd.print(healthLost);
          screen = 5;
        }
        break;
      case 4:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Close call!");
        screen = 7;  // Reset to the first screen
        break;
      case 5:
        health = max(health - healthLostFlee, 0);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Health -:");
        lcd.setCursor(0, 1);
        lcd.print(healthLostFlee);
        screen++;
        break;
      case 6:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Let's patch");
        lcd.setCursor(0, 1);
        lcd.print("that up.");
        screen ++;
        break;
      case 7:
            screen = 0;  // Reset screen index
        currentState = ACTION_SELECT;  // Change game state
       
        break;
    }
  }
}