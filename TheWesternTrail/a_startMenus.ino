// Begin the game
void handleStartGame() {
  lcd.clear();
lcd.setCursor(0, 0);
  lcd.print("Load on up");
  lcd.setCursor(0, 1);
  lcd.print("there, pardner!");
  delay(1500);
  currentState = ACTION_SELECT;
}
// Begin the game, or receive instructions for play
void handleMainMenu() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("1.Start 2.Help");
  if (buttonState[0]) currentState = START_GAME;
  else if (buttonState[1]) currentState = HELP;
}
// Instructions for play
void handleHelp() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Travel West,");
  lcd.setCursor(0, 1);
  lcd.print("Pardner!");
  delay(1500);
  currentState = MAIN_MENU;
}