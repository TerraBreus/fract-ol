### Fract-ol
- Add macros for keypresses.

- Refactor functions from events into handlers that go to the correct function if a specific key is pressed.

- Implement reset button

- Initial memset so that all relevant pointers are set to NULL in case we need to exit program on failure (and don't run into segfaults when freeing)

- Fix zoom issue when offset. (Apparently you should add offset after you have multiplied)

- Print string on window.

- Implement Julia fractal (might take some time)
	- Take in parameters (aka some integers or convert them to doubles if you want)
		If julia then formula will be:
			z: The coordinate from the pixels.
			c: Some constant defined by the Julia.
		If Mandelbrot then formula will be;
			z: The coordinate from the pixels.
			c: The coordinate from the pixels.
	- Establish fractal type and parse relevant parameters if Julia
		- correct_input -> parse_input
		- Parse fractal through the function that 
	- Render with the updated Julia set 
		- check_fractal_type() function.
- Norminette

- Implement Phoenix
	Uses the following calculation
	`Fn+1 = Fn^2 + c^2`
	Where C is the converted pixels.
