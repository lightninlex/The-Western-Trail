void handleTrading() {
// Constants for trading
const int MAX_FOOD_PRICE = 8;
const int MIN_FOOD_PRICE = 3;
const int MAX_FOOD_SELL_PRICE = 7;
const int MIN_FOOD_SELL_PRICE = 2;
const int MAX_FOOD_BOUGHT = 5;
const int MIN_FOOD_BOUGHT = 1;
const int MAX_SCAM_AMOUNT = 15;
const int MIN_SCAM_AMOUNT = 5;
const int MAX_RARE_ITEM_BONUS = 20;
const int MIN_RARE_ITEM_BONUS = 10;
const int SCAM_CHANCE = 2;
const int RARE_ITEM_CHANCE = 2;
const int RANDOM_EVENT_RANGE = 10;
	static int screen = 0;
	int foodPrice = random(MIN_FOOD_PRICE, MAX_FOOD_PRICE); // Dynamic pricing
	int foodBought = min(money / foodPrice, int(random(MIN_FOOD_BOUGHT, MAX_FOOD_BOUGHT)));
	int foodSellPrice = random(MIN_FOOD_SELL_PRICE, MAX_FOOD_SELL_PRICE); // Dynamic pricing
	int foodSold = min(food, int(random(MIN_FOOD_BOUGHT, MAX_FOOD_BOUGHT)));
  int event = random(RANDOM_EVENT_RANGE);
		updateButtonState();
    if (buttonState[0] && screen == 0) {
    screen = 1;
    Serial.println("entering case 1");
     } else if (buttonState[1] && screen == 0) {
    screen = 2;
    Serial.println("entering case 2");
     }else if (buttonState[2] && screen == 0) {
    screen = 4;
    Serial.println("entering case 4");
  }
  const long interval = 2000;  // interval at which to display screens (milliseconds)
  unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
	  previousMillis = currentMillis;
	  switch (screen) {
	  case 0:
    	lcd.clear();
	    lcd.setCursor(0, 0);
		  lcd.print("1. Buy");
	    lcd.setCursor(0, 1);
	    lcd.print("2. Sell");
		  break;
	  case 1:// Buying screen
      lcd.clear();
      lcd.setCursor(0, 0);
		  lcd.print("Haggling...");
      delay(500);
      lcd.clear();
      delay(500);
      lcd.setCursor(0, 0);
		  lcd.print("Haggling...");
      delay(500);
      lcd.clear();
      delay(500);    
      lcd.setCursor(0, 0);
		  lcd.print("Buying...");
      delay(800);
		    food += foodBought;
		    money -= foodBought * foodPrice;
      lcd.clear();
	    lcd.setCursor(0, 0);
		  lcd.print("Food +:");
		  lcd.setCursor(0, 1);
		  lcd.print(foodBought);
      delay(1000);
      lcd.clear();
	    lcd.setCursor(0, 0);
		  lcd.print("Money -:");
		  lcd.setCursor(0, 1);
		  lcd.print(foodBought * foodPrice);
		  screen = 3;
		  break;
	  case 2: // Selling screen
      lcd.clear();
      lcd.setCursor(0, 0);
		  lcd.print("Negotiating...");
      delay(500);
      lcd.clear();
      delay(500);
      lcd.setCursor(0, 0);
		  lcd.print("Negotiating...");
      delay(500);
      lcd.clear();
      delay(500);    
      lcd.setCursor(0, 0);
		  lcd.print("Selling...");
      delay(800);
		    food -= foodSold;
		    money += foodSold * foodSellPrice;
      lcd.clear();
	    lcd.setCursor(0, 0);
		  lcd.print("Money +:");
		  lcd.setCursor(0, 1);
		  lcd.print(foodSold * foodSellPrice);
      delay(1000);
      lcd.clear();
	    lcd.setCursor(0, 0);
		  lcd.print("Food -:");
		  lcd.setCursor(0, 1);
		  lcd.print(foodSold);
		    screen++;
		  break;
	  case 3:// Random events during trading
		  if (event < SCAM_CHANCE) { // 20% chance of encountering a scammer
      lcd.clear();
	    lcd.setCursor(0, 0);
		  lcd.print("Dirty, rotten");
      lcd.setCursor(0,1);
      lcd.println("scammers!");
      delay(1000);
		      money = max(money - random(MIN_SCAM_AMOUNT, MAX_SCAM_AMOUNT), 0); // Lose random amount of money
		    screen++;
		    } else if (event < RARE_ITEM_CHANCE) { // 20% chance of finding a rare item
        lcd.clear();
	      lcd.setCursor(0, 0);
		    lcd.print("A STEAL of");
        lcd.setCursor(0, 1);
        lcd.println("a DEAL!");
        delay(1000);
		      money += random(MIN_RARE_ITEM_BONUS, MAX_RARE_ITEM_BONUS); // Gain random amount of money
		    screen++;
        } else {
		        screen = 0; // Go back to the main trading screen
	      }
		  break;
	  case 4:
      lcd.clear();
	    lcd.setCursor(0, 0);
		  lcd.print("Trading");
      lcd.setCursor(0, 1);
      lcd.print("completed!");
      delay(1000);
		    screen = 0;  // reset to the first screen
        currentState = ACTION_SELECT;
		  break;
	}
  }
}