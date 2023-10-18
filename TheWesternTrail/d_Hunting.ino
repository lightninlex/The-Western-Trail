void handleHunting() {
Serial.println("entered hunting state");
  // Declaring constants within the function scope
  const int MIN_FOOD_GAINED = 5;
  const int MAX_FOOD_GAINED = 10;
  const int MIN_HEALTH_LOST = 1;
  const int MAX_HEALTH_LOST = 4;
  const int MIN_BERRIES_FOUND = 0;
  const int MAX_BERRIES_FOUND = 5;
  const int HUNTED_CHANCE = 20; // 20% chance
  const int MIN_DAMAGE = 2;
  const int MAX_DAMAGE = 5;
  const int RANDOM_EVENT_RANGE = 100; // for generating random events
  static int screen = 0;
  int success = random(20);
	int foodGained = random(MIN_FOOD_GAINED, MAX_FOOD_GAINED + 1);
	int healthLost = random(MIN_HEALTH_LOST, MAX_HEALTH_LOST + 1);
	int event = random(1, RANDOM_EVENT_RANGE + 1);
	int berriesFound = random(MIN_BERRIES_FOUND, MAX_BERRIES_FOUND + 1);
       updateButtonState();
    if (buttonState[0] && screen == 0) {
      screen = 1;
      Serial.println("entering case 1");
  }   else if (buttonState[1] && screen == 0) {
      screen = 2;
      Serial.println("entering case 2");
  }
  unsigned long currentMillis = millis();
  const long interval = 2000;
    if (currentMillis - previousMillisHunting >= interval) {
      Serial.println("Entering interval block");
      previousMillisHunting = currentMillis;
    switch (screen) {
      case 0:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Wilderness");
        lcd.setCursor(0, 1);
        lcd.print("1.Hunt 2.Forage");
        break;  // Add this break statement to prevent fall-through
	    case 1: // Hunting screen
		    if (success < 15) {
		  //int foodGained = random(MIN_FOOD_GAINED, MAX_FOOD_GAINED + 1);
		      food += foodGained;
        lcd.clear();
	      lcd.setCursor(0, 0);
		    lcd.print("You smite");
		    lcd.setCursor(0, 1);
        lcd.print("your prey!");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
		    lcd.print(String(foodGained) + " Food");
		    } else {
		  //int healthLost = random(MIN_HEALTH_LOST, MAX_HEALTH_LOST + 1);
		    health = max(health - healthLost, 0);
        lcd.clear();
	      lcd.setCursor(0, 0);
		    lcd.print("Your prey");
		    lcd.setCursor(0, 1);
        lcd.print("has escaped!");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
		    lcd.print(String("-") + (healthLost) + " Health");
  }
          screen = 3;
        break;
      case 2: { // Foraging screen
	      if (berriesFound > 0) {
	        food += berriesFound;
        lcd.clear();
	      lcd.setCursor(0, 0);
	      lcd.print("Found berries! +:");
	      lcd.setCursor(0, 1);
	      lcd.print(berriesFound);
	        } else {
            lcd.clear();
	          lcd.setCursor(0, 0);
	          lcd.print("No luck!!");
	          lcd.setCursor(0, 1);
        	  lcd.print("Found nothing...");
	}
		        Serial.println("entering case 3");
            screen++;
	      break;
  }
	  case 3:
        if (event <= HUNTED_CHANCE) {
          int damage = random(MIN_DAMAGE, MAX_DAMAGE + 1);
          health = max(health - damage, 0);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Hunter becomes");
          lcd.setCursor(0, 1);
          lcd.print("Hunted! -" + String(damage));
          screen++;
        } else {
          screen++;
        }
        break;
    case 4:
      screen = 0;
      currentState = ACTION_SELECT;
  }
  }
  }