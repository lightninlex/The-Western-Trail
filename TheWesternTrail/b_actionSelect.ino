/*
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
This is how players will decide upon their day. They will need to choose wisely, and consider their available resources in order
to survive their path to West
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void handleActionSelect() {
  unsigned long currentMillis = millis();
  const long interval = 1500;  // interval at which to display screens (milliseconds)
	static int screen = 0;
if (currentMillis - previousMillis >= interval) {
	previousMillis = currentMillis;
	switch (screen) {
	  case 0:		// Update player on current resources
  lcd.clear();
	lcd.setCursor(0, 0);
		lcd.print("Health: ");
		lcd.print(health);
		lcd.setCursor(0, 1);
		lcd.print("Food: ");
		lcd.print(food);
		screen++;
		break;
	  case 1:
	lcd.clear();
	lcd.setCursor(0, 0);
		lcd.print("Money: ");
		lcd.print(money);
		lcd.setCursor(0, 1);
		lcd.print("Select Action:");
		screen++;
		break;
	  case 2:		// Allow player to select how to spend the day
	lcd.clear();
	lcd.setCursor(0, 0);
		lcd.print("1.Travel 2.Hunt");
		lcd.setCursor(0, 1);
		lcd.print("3.Trade 4.Rest");
		screen = 0;  // reset to the first screen
		break;
	}
  }
   updateButtonState();
  if (buttonState[0]) {
	currentState = TRAVELLING;
	delay(50);
  } else if (buttonState[1]) {
	currentState = HUNTING;
	delay(50);
  } else if (buttonState[2]) {
	currentState = TRADING;
	delay(50);
  } else if (buttonState[3]) {
	currentState = RESTING;
	delay(50);
  }
}