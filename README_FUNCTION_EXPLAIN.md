This game was built with an LCD1602A module, so be comfortable and familiarized with the Liquid Crystal library, as we'll be using lcd.setCursor(), lcd.println(), and lcd.clear quite a bit.

  "int distance", "int food", "int money", and "int health" are all the starting resource parameters, and can be adjusted for difficulty[The same can be done with the Min/Max const ints, but it's suggested to leave the Min at zero for each.

  randomSeed(analogRead(0)) uses the voltage noise from an open analog pin[in this case, A0], and seeds the random() function, to make a true random, as the Arduino random() uses the same "randomization" each time, like the fake shuffle on certain music streaming platforms.

  void displayThiefScreen() is the display standard that I hope to eventually have all functions operating on, for text display efficiency.

  The loop is quite simple. It Ensures that the resources aren't above the Max value, then checks to see if any resources are <= the Min value, then checks to see if any buttons were pressed. Then it uses a switch-case to determine what gameState is currently active. It then calls whichever void handle() is associated to the current gameState.

  The "start menus" section of the code is very bare-boned at the moment, but I will flesh it out soon with some real instructions, and perhaps an ASCII animation.

  The "action select" section handles all the ways that a player may choose to spend their day. It again uses a switch-case in order to determine which screen to jump too within the function, based upon user input.
  
    Travelling advances the game, but with risk of injury, cart damage, storms, thieves, and bandit raids.
    
    Hunting takes you off the trail, and into the Wilderness. From here, you choose to Hunt or Forage. Either of these comes with the risk of a predator creature attacking you["Hunter becomes Hunted"], and Hunt has an additional risk of harm, if your prey escapes you. The additional risk comes with the potential reward of getting more food than if you'd just foraged and found some berries.
    
    Trading takes you to a local outpost, where you can buy/sell food to help balance out your resources. These, of course, come with the risk of being scammed, wherein you lose a randomized amount of money[so be sure you can afford the risk :)]; Opposite that risk, is the potential reward for a sweet deaal, wherein you gain a random amount of money.

    Resting uses a random amount of food to recover a random amount of health, and is the only way to keep your HP intact, so it is integral to the gameplay. That being said, it obviously comes with a randomized chance of getting robbed overnight, or waking up sick, alongside the core resting function.


  The Thief, Animal Attack, and Raid sectionss all function similarly, in that they give the player an opportunity to Fight or Flee, which adjusts the randomized resource allocation based upon the outcomes of these choices.

  The Travelling, Hunting, Trading, and Resting sections all handle the different states that are achieved by user input during the Action Select gameState.

  The injuryDamageStorm section handles the static negative effects of travel, which are the functions that take a set amount of health from the player, and are typically light on resource drain.

Injury, Damage, Storm, Thief, Animal Attack, and Raid are all negative effects from Travelling, and are randomly calculated. Each of these has a specific modifier to the finalDistanceTravelled calulation, and are ranked from common to rare accordingly to their risk factor.

The endGame section of the code is just where the call handles lie for the check win/lose conditions.



                                        
                                        
                                        
                                     ### Please let me know if you have any further questions, and happy trails!


  
