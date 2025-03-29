#Fract-ol
A 42 project.

## TO DO
1. Render the initial Mandelbrot.
	Non-interactive. 
	- **The fractal structure:**
	
	Initialising the data structure that holds all relevant information of the mandelbrot.
	- [] `void *mlx_connection` *holds the return value of `mlx_init()`*
2. Key handling.
	Make the Mandelbrot interactive.
	- Moving around (offsetting the map function).
	- Zooming in and out (scaling the map function).
	- Window closing (closing, freeing and exiting without leaks).
3. Add the Julia fractal.
	Similar to the mandelbrot but a little different on the mathmatical side.
