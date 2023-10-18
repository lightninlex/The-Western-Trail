// Code to handle the static negative effects of travelling
void handleInjury() {
  lcd.clear();
  lcd.print("Injured!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Health -1");
    health = max(health - 1, 0);
  delay(2000);
    currentState = ACTION_SELECT;
}
void handleDamage() {
  lcd.clear();
	lcd.setCursor(0, 0);
  lcd.print("Cart Damage!");
  lcd.setCursor(0, 1);
  lcd.print("*YEEOWCH!!*");
  delay(2000);
  lcd.clear();
	lcd.setCursor(0, 0);
  lcd.print("Let's camp");
  lcd.setCursor(0, 1);
  lcd.print("here tonight.");
  delay(2000);
    health = max(health - 1, 0);
    food = max(food - 5, 0);
    money = max(money - 2, 0);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Good morning!");
  lcd.setCursor(0, 1);
  lcd.print("Cart repaired!");
  delay(2000);
    currentState = ACTION_SELECT;
}
void handleStorm() {
  lcd.clear();
	lcd.setCursor(0, 0);
  lcd.print("Storm!");
  lcd.setCursor(0, 1);
  lcd.print("Health -2");
    health = max(health - 2, 0);
  delay(2000);
    currentState = ACTION_SELECT;
}