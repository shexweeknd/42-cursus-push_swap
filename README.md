# Push Swap

This repository contains the implementation of the **Push Swap** project from 42 School.

## Description

The **Push Swap** project is a sorting algorithm implementation. It takes a stack of integers as input and sorts them using a limited set of operations. The goal is to sort the stack with the minimum number of operations.

## Algorithm

![algorithm](https://github.com/shexweeknd/blob/blob/main/42-cursus-push_swap/algo-overview.png)

The **Push Swap** can be solved from various algorithms to efficiently sort the stack.

I saw a bit of them during the 42 Cursus:

- Radix Sort
- Mechanical Turk
- Chunk Algorithm
- ...
  
For my part I decided to use Mechanical Turk combined with Chunk Algorithm.

**Mechanical Turk**: for its mechanical simplicity, that completely suits to my brain.

**Chunk Algorithm**: for its savings in terms of operations. It also makes some order in the stack while processing Turk.

The code minimizes the number of operations required by analyzing the stack and performing the most optimal moves.

## Usage

To use the **Push Swap** program, follow these steps:

- Clone this repository

```sh
git clone https://github.com/shexweeknd/42-cursus-push_swap.git
```

- Compile the program using the provided Makefile.

```sh
cd 42-cursus-push_swap/ &&\

make all bonus
```

**MANDATORY PART**:

- Run the program with the input stack as an argument.

```bash
./push_swap <stack>
```

>**example:**

```bash
./push_swap 28 0 42 73 1 6
```

**BONUS PART**: [ONLY IF MANDATORY PART IS PERFECT]

- The binary `checker` is a tester for `push_swap`, here is how it works:

```bash
./push_swap <stack> | ./checker <stack>
```

>**example:**

```bash
./push_swap 28 0 42 73 1 6 | ./checker 28 0 42 73 1 6
```

If the test succeed then it will display `OK` else it will display `KO`.

You can also proceed as follow:

```bash
./checker 28 0 42 73 1 6
```

Then you give the operations in the prompt, then `Ctrl + D` to evaluate the sorting commands.

![example-of-checker](https://github.com/shexweeknd/blob/blob/main/42-cursus-push_swap/bonus-example.png)

If the test succeed then it will display `OK` else it will display `KO`.

## Resources

To get start with the mechanical Turk Algorithm, as well as the chunck algorithm follow those links:

- <https://medium.com/@ayogun/push-swap-c1f5d2d41e97>
- <https://www.youtube.com/watch?v=50f7SgnWPCk&pp=ygUaY2h1bmtzIGFsZ29yaXRobSBwdXNoX3N3YXA%3D>
- <https://www.youtube.com/watch?v=2aMrmWOgLvU>
- <https://vscza.itch.io/push-swap>

## Contributions

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## Project Goals

- Learn complex and advanced sorting algorithms.
- Improve C programming skills regarding shained list.

## License

![42-antananarivo-logo](https://github.com/shexweeknd/blob/blob/main/42-cursus-so_long/42-cursus-so_long-42-logo.png)

This project is from 42 School Common Core Cursurs. I do not own any of the concept mentionned above. Instead I own the provided code in the repository.

Licensed under the [MIT License](https://github.com/shexweeknd/blob/blob/main/LICENSE).

## Acknowledgments

- 42 Network for providing the project.
- Axian Group
