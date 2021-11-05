<h1 align="center">🧱 cub3D 🎥</h1>

<p align="center">
  <a href="https://fr.wikipedia.org/wiki/MacOS_Mojave" target="_blank">
    <img alt="platform: osx 10.14.x" src="https://img.shields.io/badge/platform-osx%20v10.14.x-red?style=flat-square"/>
  </a>
  <a href="https://fr.wikipedia.org/wiki/C_(langage)" target="_blank">
    <img alt="language: c" src="https://img.shields.io/badge/language-C-purple?style=flat-square"/>
  </a>
  <a href="https://fr.wikipedia.org/wiki/OpenGL" target="_blank">
    <img alt="framework: opengl" src="https://img.shields.io/badge/framework-OpenGL-green?style=flat-square"/>
  </a>
  <a href="https://developer.apple.com/documentation/appkit" target="_blank">
    <img alt="framework: appkit" src="https://img.shields.io/badge/framework-AppKit-green?style=flat-square"/>
  </a>
  <a href="https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html" target="_blank">
    <img alt="library: minilibx" src="https://img.shields.io/badge/library-MiniLibX-orange?style=flat-square"/>
  </a>
  <a href="https://github.com/LoisDuplain/best-libft" target="_blank">
    <img alt="library: best-libft" src="https://img.shields.io/badge/library-best--libft-orange?style=flat-square"/>
  </a>
  <a href="https://profile.intra.42.fr/users/lduplain" target="_blank">
    <img alt="42 login: lduplain" src="https://img.shields.io/badge/42%20login-lduplain-2DD57B?style=flat-square"/>
  </a>
</p>

<p align="left">
  Cub3D is a game engine written in C. It is inspired by one of the first FPS Wolfenstein3D.
  <br>
  Created by Loïs Duplain. (42login: lduplain, 42mail: lduplain@student.42lyon.fr)
</p>

<h2 align="left">🖼️ Gallery</h2>

<p align="left">Gource (click on image):</p>
<a href="https://www.youtube.com/watch?v=PiN-a9HSDn0"><img src="https://img.youtube.com/vi/PiN-a9HSDn0/0.jpg"></a>

<p align="left">Screenshot - Map: ./maps/debug.cub</p>
<img src="https://github.com/LoisDuplain/cub3D/blob/main/gallery/debug-screenshot.png?raw=true">

<p align="left">Screenshot - Map: ./maps/minecraft.cub</p>
<img src="https://github.com/LoisDuplain/cub3D/tree/main/gallery/minecraft-screenshot.png?raw=true">

<p align="left">Screenshot - Map: ./maps/white-chamber.cub</p>
<img src="https://github.com/LoisDuplain/cub3D/tree/main/gallery/white-chamber-screenshot.png?raw=true">

<h2 align="left">🏗️ Compile</h2>
<p align="left">To basically compile program:</p>

```bash
make
```

<p align="left">To recompile entire program:</p>

```bash
make re
```

<p align="left">To clean all *.o in project:</p>

```bash
make oclean
```

<p align="left">To clean all *.o in project and libraries:</p>

```bash
make clean
```

<p align="left">To clean all *.o and compiled things in project and libraries:</p>

```bash
make fclean
```

<h2 align="left">▶️ Run</h2>
<p align="left">To basically run:</p>

```bash
./cub3D <map_path_1> <map_path_2> <map_path_...>                (default maps in ./maps folder)
```

<p align="left">Automatically save first frame:</p>

```bash
./cub3D <map_path_1> <map_path_2> <map_path_...> --save         (default maps in ./maps folder)
```

<h2 align="left">🎮 Controls (QWERTY)</h2>

<p align="left">Player movement:</p>

```
W A S D
```

<p align="left">Camera rotation:</p>

```
▲ ▼ ► ◄
```

<p align="left">Screenshot:</p>

```
F2
```

<p align="left">Previous/next level:</p>

```
< / >
```

<p align="left">Decrease/increase render distance:</p>

```
K / L
```

<p align="left">Decrease/increase pixel divider:</p>

```
Page Down / Page Up
```

<p align="left">Decrease/increase FOV:</p>

```
NumPad Sub / NumPad Add
```

<h2 align="left">📝 Parsing</h2>

<p align="left">Resolution:</p>

```
R <width> <height>

Example:
R 1920 1080
```

<p align="left">Walls:</p>

```
NO --> North Wall
SO --> South Wall
WE --> West Wall
EA --> East Wall
```

<p align="left">You can put texture or color on wall:</p>

```
XX  <r,g,b>
XX  <path>.xpm

Example:
XX  31,219,81                    --> Green
XX  ./textures/debug/north.xpm   --> Path to texture (default textures in ./textures folder)
```

<p align="left">Floor/ceiling:</p>

```
F --> Floor
C --> Ceiling
```

<p align="left">You can put texture or color on floor/ceiling:</p>

```
F  <r,g,b>
C  <path>.xpm

Example:
F 255,0,0                        --> Red
C ./textures/debug/ceiling.xpm   --> Path to texture (default textures in ./textures folder)
```

<p align="left">Map description:</p>

```
2     --> Sprite
1     --> Wall
0     --> Walkable
Space --> Void
N/S/W/E (North / South / West / East) --> Player spawn point and direction

Example:
1111111111111
1000000000001
1200000000021
1001010101001
120000S000021
1001010101001
1200000000021
1000000000001
1111111111111
```

<h2 align="left">✨ Bonuses</h2>

- Look up and down
- Texture on ground and ceiling
- Collide with walls
- Collide with sprites
- Fog
- Multi level
- Changing FOV in-game
- Crosshair
- Minimap
- Move camera with mouse
- Multi threading
- Replace texture by color in parsing
- Changing render distance in-game
- Changing pixel divider in-game
- Max frames per second and ticks per second
- Take a screenshot

<h2 align="left">🖥️ 42</h2>

<a href="https://github.com/LoisDuplain/42cursus/blob/master/cub3d/cub3d.pdf">Subject</a>
<p align="left">
  Mark:
  <img alt="42-project-mark" src="https://badge42.herokuapp.com/api/project/lduplain/cub3d"/>
</p>

<h2 align="left">⚖️ Copyright</h2>
<p align="left">
  Loïs Duplain (lduplain) © 2020
</p>
