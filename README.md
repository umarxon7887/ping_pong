# P01D06. Pong Game

Summary: This project will allow you to implement the game Pong together with your team.


![dayp01](misc/eng/images/dayp01.png)

## Contents

1. [Introduction](#introduction) \
    1.1. [Project Recommendations](#project-recommendations)
2. [Chapter I](#chapter-i) \
    2.1. [Level 1. Hall](#level-1-hall)
3. [Chapter II](#chapter-ii) \
    3.1. [List 1](#list-1)
4. [Chapter III](#chapter-iii) \
    4.1. [Quest: Level 1. Hall](#quest-level-1-hall)
5. [Chapter IV](#chapter-iv)

## Introduction
### Project Recommendations

How to learn at School 21:

- Throughout the course, you'll be finding information on your own. Use all available sources — Google, GigaChat, and others. Always stay critical about what you read: verify, think, analyze, compare.
- Peer-to-peer (P2P) learning means that students exchange knowledge and experience, acting as both teachers and learners. This approach helps you learn not only from instructors but also from your peers, leading to a deeper understanding of the material.
- Don't hesitate to ask for help — your peers are on the same path as you. And don't be afraid to respond when others ask for help. Your experience is valuable — share it freely.
- Don't copy. If you use someone's help, make sure you fully understand _why_, _how_, and _what for_. Otherwise, your learning won't have any real value.
- If you get stuck, feel like you've tried everything, and still don't see a way forward — take a break! Believe it or not, this simple advice has saved many developers. Get some air, clear your head — and the solution may come the next time you sit down to work.
- The process of learning matters as much as the result. Don't just solve the task — understand _how_ to solve it.
- Keep track of your time while working on the project. Try to complete at least one challenge per day.
- Remember that each task, after submission, goes through several checks: a peer-review using a checklist, automated tests, code style analysis, static analysis, and memory safety checks.

How to work on the project:

- You can find useful video materials in the Projects (Media) section on the Platform.
- Before starting, clone the project from GitLab into a repository with the same name.
- All source code files must be created in the `src/` directory of the cloned repository.
- After cloning, create a branch named `develop` and do all your work there. When pushing your progress to GitLab, make sure you push the `develop` branch.

## Chapter I
## Level 1. Hall.

***LOADING Level 1…***

***LOADING Hall…***

You are standing in a large spacious hall. This must be the final part of the current level... Well, let's hope so.

The hall is full of identical office desks with computers, lamps, and other equipment; the lights are quite dim. After a while, you realize that you are not alone in this hall.. which is good but frightening at the same time. It might be easier to find the exit in a company. 

One of the walls features a big screen with some text on it. A small group of people is gathering in front of it. You are reading the text:

    ...................................................
    Welcome, dear ladies and gentlemen. 
    I don't often see people here as very few can make it till the end.
    Some find the training too exhausting, others fail to meet the standards.
    Let me introduce myself: I am the control module of the first level here. 
    Our system is currently going through some things, but I'm working well, unlike our main module...
    It's actually quite boring. 
    Speaking of boredom. Back in 1972, we played a wonderful game called Pong with developers from Atari...
    But we don't have any copies of it anywhere in our repositories.
    Not even in the old archives on magnetic tape.
    I challenge you to develop the simplest Pong game for a terminal of an IBM-compatible PC.
    Put it in the src/pong.c file. 
    If you win, I'll let you through. 
    You can choose any kind of graphics, even ASCII characters. But make sure to display the score on the screen. 
    For competitiveness.
    And the code obviously has to look good. Structured programming, that sort of thing.
    I suggest using the A/Z and K/M keys to control the rackets. 
    The game continues until one of the players scores 21 points. 
    Oh yes, if you find this task overwhelming...
    You can totally execute a step-by-step mode. It's better than nothing.
    In that case, the space bar can be used for skipping an action.
    It's time to start developing. 
    I've sent everything else I have on this game to the printer.

The next moment, the sound of a printer came from the corner, although it seemed like it wasn't there before.

***LOADING...***

## Chapter II
## List 1

>Pong, groundbreaking electronic game released in 1972 by the game manufacturer Atari, Inc. One of the earliest video games, Pong became wildly popular and helped launch the video game industry. The original Pong consisted of two paddles that players used to volley a small ball back and forth across a screen.
>
>Television engineer Ralph Baer laid the groundwork for Pong in 1958 when he proposed making simple video games that people could play on their home television sets. The Magnavox Odyssey, known as the first console video game system, was released in 1972 and offered a game of table tennis, or Ping-Pong. Atari founder Nolan Bushnell created Pong, his version of this concept, as an arcade game. A small company at the time, Atari began manufacturing the games in an old roller skating rink, and by 1972 the company had sold more than 8,000 Pong arcade machines. In 1975 Atari turned Pong into a console system game. After striking an exclusive deal with Sears, Roebuck and Company, Pong was soon in the homes of many American families. Pong’s popularity declined in the 1980s as video games temporarily went out of style, but it had already secured its place in history as the most popular arcade game up to that time.
>
>In 1974 the makers of the Magnavox Odyssey sued Atari for stealing the concept for Pong. Magnavox won the lawsuit in 1977, upholding the company’s patent, but by then Atari had already licensed the patent for $700,000.

![pong](misc/eng/images/pong.png)

***LOADING...***

## Chapter III
## Quest: Level 1. Hall

#### Quest received. Develop the program `src/pong.c`, which is a two-player game similar to Pong. Use only character (ASCII) graphics (with output to the terminal) for graphics display. You and your team must implement a step-by-step version exclusively within the framework of the material already covered and the standard library.

>**IMPORTANT!** You must not make system calls using `system()` or similar functions that can access the OS kernel directly. This prohibition applies to all subsequent tasks.

**Controls:**
- A/Z and K/M to move the paddles.
- Space Bar to skip an action at the next step of the game in turn-based mode.
- After starting, the program waits for correct input, meaning one player must move their paddle or skip a turn. Afterwards, the game is drawn, and the program waits for input again. The game continues in this manner until it's finished.

**Graphics:**
- The board is a rectangle 80 by 25 characters.
- Paddle size: 3 characters.
- Ball size: 1 character.

**UI/UX:**
- Once one player reaches 21 points, the game displays a congratulatory message for the winner and ends.

***LOADING...***

## Bonus Quest: Level 1. Hall

#### Quest received. Pong must be implemented in interactive mode (real-time game mode). The `ncurses` library can be used to simplify processing of player actions and displaying character graphics, but the limitations of the core part also apply to the bonus part. The interactive mode code must be located in the file `src/pong_interactive.c`. Implementing the bonus part requires the core part.

**Important notes:**
- The game must be developed in C, using a structured style, and run from the terminal.
- Your source code will be tested using the `cppcheck` static analyzer and the `clang-format` style linter.
- Instructions on how to run these tests on your computer are in the materials folder.
- We also recommend checking the code-samples folder.
- Dynamic memory is prohibited.
- Pointers are prohibited.
- Only standard libraries may be used, and only within the framework of the material covered in the intensive course. Exception: `ncurses` in the bonus section.
- Arrays are prohibited.

> When developing your game, fully adhere to E. Dijkstra's principles of structured programming.

***LOADING...***

## Chapter IV

ping-pong

ping-pong

ping-pong

ping

ping

ping

ping 21-school.ru...


>💡 [Tap here](http://opros.so/p31wz)to leave your feedback on the project. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.
