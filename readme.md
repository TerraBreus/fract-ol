# Fract-ol
A 42 project.

## ToC
 1. [Rendering the initial Mandelbrot.](#render-the-initial-mandelbrot)
	- [The fractal structure](#the-fractal-structure)
   	- [A complex structure](#a-complex-structure)
	- [Normalizing for window and color mapping](#normalizing-for-window-and-color-mapping)
 3. [Key handling.](#key-handling)

## Render the initial Mandelbrot
*(non-interactive. pops up a second window displaying the mandelbrot)*

### The image structure:

[Writing pixels to an image](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#writing-pixels-to-a-image)

*A structure from harm-smits documentation on the mlxlib. Each pixel will be assigned a color calculated according to the 'closeness' of the Mandelbrot (aka does it converge or diverge)* 

### The fractal structure
*Data structure that holds all relevant information for the fractal.*
- `void *mlx_connection` *Holds the return value of `mlx_init()`. Used for easy exiting.*
- `void *mlx_window` *Holds the return value of `mlx_new_window()`. Used for easy exiting.*
- `t_img img` *The actual image of the mandelbrot we want to push to the window when rendering.*
- `double hypotenuse` *The 'range' for when a point is (roughly) outside of the mandelbrot.*
- `int max_iterations` *Will define the quality of the image. More iterations means more calculations done to check whether a point diverges/converges (aka goes beyond the hypotenuse).*

*These might not be necessary here*
- `double	window_map` *To convert the pixels to the range of the mandelbrot*
- `double	color_map` *To set the color based on the amount of iterations*

### A complex structure
*Simple structure with a real and an imaginary part.*
```
typedef struct s_complex
{
	double	r;	//Real part
	double	i;	//Imaginary part
}	t_complex;
```
### Normalizing for window and color mapping

*Basically Linear mapping/interpolation*

We want to scale all pixels in our window to be *mapped* inside the domain of R[-2, 2] and C[2, -2]. As this is where our initial mandelbrot resides.

*nb: when an int is passed as a double, it will automatically be converted. As a one-way-street it is compatible*
```
double	ft_map(double x, double old_min, double old_max, double new_min, double new_max)
{
	return (x * (new_max - new_min) / (old_max - old_min));
}
```
*nb2: I think there may be a better way to approach this.*
```
double	calculate_map_scale(double old_min, double old_max, double new_min, double new_max)
{
	return ((new_max - new_min) / (old_max - old_min));
}
```
and then (especially if we only allow a square).
```
t_complex	map(double x, double y, double map_scale)
{
	t_complex	result;

	result.r = x * map_scale;
	result.i = y * map_scale;
	return (result);
}
```

### Do the math: *A function that checks whether a point is 'close' to the mandelbrot*

*Functions needed*
- `t_complex	sq_compl(t_complex x);`
- `t_complex	sum_compl(t_complex x);`
- `bool		out_of_bounds(double a, double b, double c);`

*Function will take the (mapped!) point/pixel we want to check and will always start from the origin.*
```
void	assign_pixel_color(int x, int y, double window_map, double color_map)
{
	t_complex	z;	//Starts from the origin (z = 0 + 0i)
	t_complex	c;	//Not really necessary.

	c.r = x * window_map;							//Later on this will also need to be offset and scaled to the zoom.
	c.i = y * window_map;							//something like; ((y * window_map) * zoom) + offset
	//We can also immediately assign z to c to skip the first iteration
	z.r = 0;
	z.i = 0;

	while (i < fractal->max_iterations)
	{
		z = sum_compl(sq_compl(z) + c);					//ft_sum and ft_square will return t_complex data type.
		if (out_of_bounds(z.r, z.i, hypotenuse) == true)		//Pythagoras' theorem: A^2 + B^2 = C^2
		{
			//Map the amount of iterations in between a scale of black to white and assign it to the pixel.
			put_pixel(x, y, color_map * i) 				//The closer i comes to max_iteration the whiter the pixel will be
		}
		i++;
	}
	//If max_iterations have been met, we consider the point to be inside the mandelbrot.
	put_pixel(x, y, mandelbrot_color);
}
```

### Initialization

*Necessary steps to start calculating. (setting all variables so that calculation can work)* 
- Calculate the maps.

### Render the image

*Pushing the image to the actual window. Should be final step of first part.*

## Key handling.
*Make the Mandelbrot interactive.*

### Moving around (offsetting the map function):

### Zooming in and out (scaling the map function):

### Window closing (closing, freeing and exiting without leaks):

## 3. Add the Julia fractal.
*Similar to the mandelbrot but a little different on the mathmatical side.*
