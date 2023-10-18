void handleResting() {
  // Clear the LCD and display "Resting..."
    lcd.clear();
    lcd.print("Resting...");
    delay(2000);
  // Generate random numbers for healthRecovered and foodConsumed
  int healthRecovered = random(1, 7);
  int foodConsumed = random(1, healthRecovered + 1);
  // Update health and food levels
      health = max(health + healthRecovered, 10);
      food = max(food - foodConsumed, 0);
  // Display health recovered
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("HP+:");
    lcd.setCursor(0, 1);
    lcd.print(healthRecovered);
    delay(1500);
  // Display food consumed
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Food-:");
    lcd.setCursor(0, 1);
    lcd.print(foodConsumed);
    delay(1500);
  // Generate a random number for events
  int event = random(100);
  // 20% chance of getting sick
    if (event < 20) {
	int healthLost = random(1, 4);
	    health = max(health - healthLost, 0);
	// Display the sickness event
	  lcd.clear();
	  lcd.setCursor(0, 0);
	  lcd.print("Got sick!");
	  lcd.setCursor(0, 1);
	  lcd.print("HP-:");
	  delay(1000);
	  lcd.clear();
	  lcd.setCursor(0, 0);
	  lcd.print(healthLost);
	  delay(2000);
	  lcd.clear();
  }
  // 10% chance of being robbed
    if (event >= 20 && event < 30) {
	int moneyLost = random(1, 6);
	    money = max(money - moneyLost, 0);
	// Display the robbery event
	  lcd.clear();
	  lcd.setCursor(0, 0);
	  lcd.print("Robbed!");
	  lcd.setCursor(0, 1);
	  lcd.print("$-");
	  delay(1500);
  	lcd.clear();
	  lcd.setCursor(0, 0);
	  lcd.print(moneyLost);
	  delay(2000);
	  lcd.clear();
  }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*YAWN* Morning!");
    delay(2000);
      currentState = ACTION_SELECT;
}