### Fract-ol

- Create ft_atod() for julia parsing.
- Fix bug where x-axis is mirrored when only an imaginary constant is given for the julia constant.
- Fix parsing.
	- if argc == 2
 		- check if argv[1] == "mandelbrot"
	- if argc == 4 (./fractol mandelbrot -i <int> || ./fractol julia <real> <imaginary>)
		- check if argv[1] == "mandelbrot" ->  check if argv[2] == "-i" -> convert argv[3] into integer.
		- check if argv[1] == "julia" -> convert argv[2] and argv[3] into double (which should fail if any non-numerical character is put in!)
   	- if argc == 6 (./fractol julia <real> <imaginary> -i <int>)
   		- check if argv[1] == "julia" -> convert argv[2] and argv[3] into double -> check if argv[4] == "-i" -> convert argv[5] into int. 
``` c
double	ft_atof(char *str)
{
	int	first_part;
	int	second_part;

	/* ----CHECK IF STRING VALID----
	** 
	** - only whitespace before number starts
	** - only numbers and one '.'
	** - one negative or plus sign at start of number
	*/

	/* ----SPLIT PARTS BEFORE AND AFTER COMMA----
	**
	** - Find where the dot is ('.')
	** - Duplicate string before the dot and call ft_atoi.
	** - Skip the dot, duplicate rest of string and call ft_atoi.
	*/

	/* ----CREATE THE DOUBLE----
	**
	** - Create a new double variable.
	** - divide the second part by its own length (ammount of decimals) and add to double.
	** - Add the first part to the double.
	*/
}
     
```

*Optional*
