# BombDynasty

Disclaimer:
-----------------------
The mechanic of this game is derived from "Bomberman", originally released in 1987 by Hudson Soft. We do not own the original game idea.

Background music: Five Armies - The Descent
We do not own the music. All rights belong to original composer.

This game is not for commercial usage.

System Requirements:
-----------------------
Must be run with Qt 5.12.0 compiler or higher (check current version in Project->Build & Run). Works best with mac OS.

Game Description:
-----------------------
The goal of this game is to eliminate your enemy. You must do so by placing explosives on the game field while moving about to avoid those placed by the enemy (and also your own).

Game Modes:
-----------------------
Single Player Mode: Play with a computer player.
Two Player Mode: Play with a friend on the same computer.

Game Mechanic:
-----------------------
The primary attack method of the player is to place a bomb on the game field, which will explode 3 seconds after being placed, affecting areas horizontally and vertically adjacent to the bomb. All players start out being able to place only one bomb on the game field at a time, and bombs affect only one square above, below, to the left, and right of the bomb unless a wall is present, in which case the explosive effect is stopped by the wall. As the player encounters power ups, these stats may increase. Some power ups grant special abilities to the player in a given amount of time, while some may harm the player.

Player Action Keys:
-----------------------
Player 1: Arrow keys to move, RETURN key (large ENTER key on PC keyboard) to place a bomb.
Player 2 (two-player mode): W, A, S, D to move, SPACE key to place a bomb.
Press ESC while in game to pause and resume the game by toggling the in-game menu.

List of Power Ups:
-----------------------
1. Bomb +1: Increases maximum bombs active on screen by one (max 3)
2. Bomb Power Up: Increases bomb explosion radius by 1 (max 5)
3. Freeze: One-time secondary attack. Freeze a player horizontally, vertically, or diagonally adjacent to you for 2 seconds on your next bomb attack (overrides bomb placement). The frozen player cannot move. Freeze attack will always preceed Mine placement when both are active.
4. Ghosting: Gain ability to pass through walls and place bombs inside walls for 10 seconds. Bombs placed inside wall are invisible.
5. Mine: One-time secondary attack. Place a mine on your next bomb attack key press (overrides bomb placement). Mines explode when stepped on, but expire after 20 seconds if not.
6. Push Bomb: Gain ability to push bombs in your way for 10 seconds. The normal push range is 5 squares, but can be cut short in presence of a wall obstacle.
7. Reverse: Flips your direction keys for 10 seconds.
8. Shield: Gain a shield for 10 seconds. Bombs cannot hurt you when your shield is active. However, mine attacks are not protected by the shield.

End of game:
-----------------------
A player can die in one of the two following ways:
1. Player steps on an active mine.
2. Player is in the explosion area of effect and does not have an active shield.
If one player dies, the other player automatically wins the game.

How to Navigate:
-----------------------
- On the welcome screen, click "How To Play" to see a description of action keys and power ups.
- Click "Settings" to adjust background music and sound effect volumes.
- Click "Enter Game" to select play mode.
- Click "Start Game" to start a game.
- Press the ESC key while in game to pause and resume the game and toggle the in-game menu.
- Adjust volume in the in-game menu or click "Quit Game" to return to game mode selection screen.
- When the game has ended, click "RETURN TO MENU" to return to game mode selection screen.

