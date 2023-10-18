// code to handle maximum resource limits
void ResourceMeter() {
  if (money >= MAX_MONEY) {
    money = MAX_MONEY;
  }
if (food >= MAX_FOOD) {
  food = MAX_FOOD;
}
if (health >= MAX_HEALTH) {
  health = MAX_HEALTH;
}
}