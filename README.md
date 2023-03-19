# Wireframe-render

A simple program to render wireframe models using isometric projections.

The program used the MiniLibX library, a graphic library used in projects developed at school 42.

## Usage

The program takes in a .fdf file, wich contains the coordinates of the landscape to be render. The file should be formatted as the following example:

![image](https://user-images.githubusercontent.com/79791165/226207581-32bfea70-bbad-4165-a5f3-ee98b651135b.png)

Where the horizontal position corresponds to its axis. The vertical position corresponds to its ordinate. The value corresponds to its altitude.

Diferrent colors can be defined to each point using True Colors. The color code should be provided after the altitude of the point, separated by a colon. Example:

![image](https://user-images.githubusercontent.com/79791165/226208250-c7e629c6-70f3-4943-b0f9-5cf37877f7f5.png)

For the above map, the program renders the following landscape:

![image]

The folder "/maps" at the root of the repository contains a set of properly formatted maps that can be used.

The path to the .fdf file should be passed as an argument to the program:

```./fdf <file_path>```
