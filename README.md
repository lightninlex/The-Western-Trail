# The-Western-Trail
An educational experiment to create a simplified-yet-dynamic reimagination of The Oregon Trail

The code is written in Arduino C, and is designed for an ATMega 2560 microcontroller. As it stands, it should still work on an Uno r3, but it basically maxes out all memory. I decided to continue programming on the Mega with the intent of expanding the game and adding many more functions, as it only takes up about 6% of the expanded memory of this microcontroller.

The gameplay is simple; Players will start the game, and be brought to the ACTION_SELECT state. From here, the player may choose one of four options: 1. Travel, 2. Hunt, 3. Trade, and 4. Rest. Through these different gameStates, the player will gather or lose resources, depending on many random factors from within. The 3 resources are: 1. Health, 2. Food, and 3. Money. Health caps at 20, while Food and Money cap at 50. If any of these resources fall to zero or below, the game is ended and the player loses.

The goal is to travel 1000 distance units, while surviving the many dangers of The Western Trail, such as:

  Storm, Injury, or Damage - Violent lightning storms, sprained ankles, damaged carts; all of these things hinder travel and lead to personal injury.

  Got sick(just a small, random amount of HP), or robbed overnight(or a small, random amount of money) - careful where you rest, nowhere is safe when you're headed West!

  Raid! - Stow your fears, or soar upon them; the bandits have come to take all, can you defeat them? Or will you choose to flee? A roll of Fate's dice will decide your outcome in any scenario[randomly decided outcomes :)]

  Thief! - Some rogueish types don't take to night or numbers. A highwayman stands between you and the Western horizon! Fight or Flee, fate shall yet again decide the outcomes, losses, and gains!

  Wild animal! - While hunting and foraging, there's always a chance of coming across a creature that didn't quite want to meet a hunter!(Or perhaps, one that did....and thus the Hunter becomes the Hunted...)


Don't forget to stop at a trading outpost, to balance your resources out. You can even find a sweet deal from time to time[and gain a random amount of money]; But beware of scammers[random loss of money]!




This about sums up The Western Trail! I am very interested in any feedback, suggestions, or collaborations in advancing this game, an also learning together!

      Lightnin Lex
