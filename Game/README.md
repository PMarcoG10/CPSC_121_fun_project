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

# Submission checklist
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readability (`make formatcheck`).
1. Answered the questions in `reflection.md`

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc game.cc game_element.cc player.cc opponent.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```
