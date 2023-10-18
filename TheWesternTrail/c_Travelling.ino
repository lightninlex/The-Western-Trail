void handleTravelling() {
  // Display "Travelling..." 5 times
  for(int i = 0; i < 3; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Travelling...");
    delay(800);
    lcd.clear();
    delay(800);
  }
  int baseDistanceGained = random(5, 15);  // Random distance
  float eventDistanceModifier = 1.0;  // Initialize to 1 (no effect)
  // Generate a random event between 0 and 99
  int event = random(100);
  // Handle event outcomes based on probabilities
  if (event < 10) {
    health -= 1;
    Serial.println("injury state");
    currentState = INJURY;
    eventDistanceModifier = 0.5;
  } else if (event < 20) {
    health -= 1;
        Serial.println("damage state");
    currentState = DAMAGE;
    eventDistanceModifier = 0.6;
  } else if (event < 35) {
    health -= 2;
    currentState = STORM;
    eventDistanceModifier = 0.7;
  } else if (event < 50) {
        Serial.println("thief state");
    currentState = THIEF_ENCOUNTER;
    eventDistanceModifier = 0.8;
  } else if (event < 60) {
        Serial.println("animal state");
    currentState = ANIMAL_ATTACK;
    eventDistanceModifier = 0.9;
  } else if (event < 75) {
        Serial.println("raid state");
    currentState = RAID;
    eventDistanceModifier = 0.8;
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Another day");
    lcd.setCursor(0, 1);
    lcd.print("safely passes.");
    delay(1000);
    lcd.clear();
    currentState = ACTION_SELECT;
  }
  // Calculate the final distance gained based on the event modifier
  float finalDistanceGained = baseDistanceGained * eventDistanceModifier;
  distance += finalDistanceGained;
  lcd.setCursor(0, 0);
  lcd.print("Distance gained:");
  lcd.setCursor(0, 1);
  lcd.print(finalDistanceGained);
  delay(2000);  // Wait for 2 seconds before transitioning
}