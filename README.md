# Postfix_calculator with C++
Building the whole calculator took me around 20+ hours.

### How to use:
- Open terminal
- Navigate to the directory containing the program files
- Use command: g++ Postfix_calc/*.cpp -o Postfix_calc/Postfix_calc
- Run program: ./Postfix_calc/Postfix_calc -p

### Test cases:
1. Addition and subtraction:
   Input: 5 6 +
   --> Expected result: 11

   Input: 10 3 -
   --> Expected result: 7

2. Multiplication and division:
   Input: 4 5 *
   --> Expected result: 20

   Input: 18 3 /
   --> Expected result: 6

3. Exponentiation and Square Root:
   Input: 2 3 ^
   --> Expected result: 8

   Input: 25 v
   --> Expected result: 5

4. Exchange Operation:
   Input: 3 4 x -
   --> Expected result: -1

5. Sum Operation and Average Operation:
    Input: 5 6 7 * + s
    --> Expected result: 47

    Input: 10 15 20 3 a
    --> Expected result: 12
