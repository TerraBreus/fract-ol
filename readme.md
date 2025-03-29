# Fract-ol
A 42 project.

## TO DO
### 1. Render the initial Mandelbrot. 
*(non-interactive. pops up a second window displaying the mandelbrot)*
	- **The fractal structure:** *Data structure that holds all relevant information for the fractal.*
	- [ ] `void *mlx_connection` *holds the return value of `mlx_init()`. Used for easy exiting.*
	- [ ] `void *mlx_window` *Holds the return value of `mlx_new_window()`. Used for easy exiting.*
	- [ ] 
2. Key handling.
	Make the Mandelbrot interactive.
	- Moving around (offsetting the map function).
	- Zooming in and out (scaling the map function).
	- Window closing (closing, freeing and exiting without leaks).
3. Add the Julia fractal.
	Similar to the mandelbrot but a little different on the mathmatical side.
