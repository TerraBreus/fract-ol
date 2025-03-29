# Fract-ol
A 42 project.

## TO DO
### 1. Render the initial Mandelbrot. 
*(non-interactive. pops up a second window displaying the mandelbrot)*

**The image structure:** [Writing pixels to an image](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#writing-pixels-to-a-image)

*A structure from harm-smits documentation on the mlxlib. Each pixel will be assigned a color calculated according to the 'closeness' of the Mandelbrot (aka does it converge or diverge)* 

**The fractal structure:** *Data structure that holds all relevant information for the fractal.*
- `void *mlx_connection` *Holds the return value of `mlx_init()`. Used for easy exiting.*
- `void *mlx_window` *Holds the return value of `mlx_new_window()`. Used for easy exiting.*
- `t_img img` *The actual image of the mandelbrot we want to push to the window when rendering.*
- `double hypotenuse` *The 'range' for when a point is (roughly) outside of the mandelbrot.*
- `int max_iterations` *Will define the quality of the image. More iterations means more calculations done to check whether a point diverges/converges (aka goes beyond the hypotenuse).*

**A 'complex' structure:** *Simple structure with a real and an imaginary part.*



**Do the math:** *A function that checks whether a point is 'close' to the mandelbrot*
```

```

### 2. Key handling.
*Make the Mandelbrot interactive.*

**Moving around (offsetting the map function):**

**Zooming in and out (scaling the map function):**

**Window closing (closing, freeing and exiting without leaks):**

### 3. Add the Julia fractal.
*Similar to the mandelbrot but a little different on the mathmatical side.*
