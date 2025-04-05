### Fract-ol

- Fix zoom issue when offset. (Apparently you should add offset after you have multiplied)

- Print string on window.

- Implement Julia fractal (might take some time)
	- Take in parameters (aka some integers or convert them to doubles if you want)
	- Establish fractal type and parse relevant parameters if Julia
		argv[2] should be a number between 0-9;
			Do I wish to convert it first and then simply check whether it is between 0 and 9?
		- correct_input -> parse_input
		- Parse fractal through the function that 
	- Render with the updated Julia set 
		- check_fractal_type() function.

- Implement window size parameter

- Norminette

- Implement Phoenix
	Uses the following calculation
	`Fn+1 = Fn^2 + c^2`
	Where C is the converted pixels.
