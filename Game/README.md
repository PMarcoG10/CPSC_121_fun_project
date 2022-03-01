# Project specifications
The goal of the project is to develop a graphical game based on Space Invaders. Although the project is based on the original game, you are free to design your own game theme. For example, below we have an Aerial Fire Fighting game where a firefighter plane puts out forest fires on the map.

![image](https://user-images.githubusercontent.com/60152830/156079282-344127d0-0736-4857-8fad-5c2f1185fd8a.png)

The program will take mouse input from the user to move their character around the map, launch projectiles that will eliminate opponents, and avoid colliding with opponents and their opponent's projectiles.

The software should be designed using the object-oriented programming paradigm so that the code can easily be modified, extended, and scaled by other developers. It is equally important to provide sufficient internal documentation to help other developers understand the code and encourage them to contribute to its development.

The software will be delivered in incremental versions or milestones over the course of the semester. Descriptions of the milestones are presented below, but technical details will be provided in your GitHub repositories for each milestone. The deadlines listed for each milestone may change depending on the class’ progress. In such cases, I will announce changes in class and/or through Canvas.

## Compiling and running the program
To manually test your code you can compile and run this program with:

```
clang++ -std=c++17 main.cc game.cc game_element.cc player.cc opponent.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
./main
```

*Note: you need a few additional flags on Mac which are not shown here.*

However, that's a lot to type, so I've included a shortcut to compile and create ``main``:

```
make build
./main
```

## Run the unit tests

I've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

## Run the style and format checkers

You can use two checkers to avoid common errors and make sure your code is easy to read. Use their output to follow programming best practices and make your code readable.

```
make stylecheck
```

```
make formatcheck
```
