_This project has been created as part of the 42 curriculum by tokyrand, varandri._

# Push_swap

## Description
Push_swap is a sorting algorithm project for 42, where the goal is to sort a stack of integers using only a limited set of stack operations and the lowest possible number of moves. The project explores algorithmic complexity and requires the implementation of multiple sorting strategies, including adaptive selection based on input disorder.

## Instructions
### Using the Makefile
- Compile the project: 
	```c 
	make
	```
- Clean object files: 
	```c 
	make clean 
	```
- Remove executable and object files: 
	```c
	make fclean
	```
- Recompile from scratch: 
	```c 
	make re 
	```
- Run: 

	```c
	./push_swap [strategy] <numbers>
	``` 
	- Strategies: `--simple`, `--medium`, `--complex`, `--adaptive` (default)
- Example: 
	```c
	./push_swap --adaptive 4 67 3 87 23
	```
- Optional benchmark mode: `--bench` displays metrics to stderr.
- Error handling: invalid input or duplicates print `Error` to stderr.

## Resources
- [Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/) - documentations of sorting algorithms
- [Youtube](https://www.youtube.com/) - algorithm tutorials
- [ClaudeAI](https://claude.ai/) & [GeminiAI](https://gemini.google.com/app) - algorithm research and examples, README structuring

## Features
- Four sorting strategies:
  - Simple (O(n²)) : Simple min/max extraction methods
  - Medium (O(n√n)): Range-based sorting strategies
  - Complex (O(n log n)): Radix sort LSD
  - Adaptive: selects strategy based on disorder metric
- Disorder metric: measures how far the stack is from sorted
- Benchmark mode: operation counts, strategy, complexity, disorder

## Algorithm Justification
- The adaptive algorithm measures disorder before sorting:
  - Low disorder (<0.2): O(n²) strategy
  - Medium disorder (0.2–0.5): O(n√n) strategy
  - High disorder (≥0.5): O(n log n) strategy
- Thresholds are chosen to optimize operation count and performance for different input types.
- Each strategy is implemented to generate valid Push_swap operations, not just theoretical array sorts.

## Usage Examples
- Default adaptive: 

	```bash
	./push_swap 2 1 3 6 5 8
	```
- Force simple: `
	```bash
	./push_swap --simple 5 4 3 2 1`
	```
- Force complex: 
	```bash
	./push_swap --complex 4 67 3 87 23
	```
- Benchmark: 
	```bash
	./push_swap --bench 4 67 3 87 23
	```

## Contributors
- tokyrand: makefiles, README, Complex and Adaptive strategies 
- varandri: input parsing, benchmarking, simple and medium strategies
