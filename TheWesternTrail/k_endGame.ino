void handleWin() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Congratulations!");
  delay(1500);
  lcd.clear();
   lcd.setCursor(0, 0);
  lcd.print("You got");
  lcd.setCursor(0, 1);
  lcd.print("*WEST*!");
  while (true) {}; // End of game
}
void handleHlose() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("You Got");
  lcd.setCursor(0, 1);
  lcd.print("*DEAD*");
  while (true) {}; // End of game
}
void handleFlose() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Y'all done");
  lcd.setCursor(0, 1);
  lcd.print("*STARVED*");
  while (true) {}; // End of game
}
void handleMlose() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ole broke ass");
  lcd.setCursor(0, 1);
  lcd.print("*LIBERAL*");
  while (true) {}; // End of game
}
void checkLoseConditions() {
	if (health <= MIN_HEALTH) {
		currentState = HEALTH_LOSE;
	} else if (food <= MIN_FOOD) {
		currentState = FOOD_LOSE;
	} else if (money <= MIN_MONEY) {
		currentState = MONEY_LOSE;
	}
}