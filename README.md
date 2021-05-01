<h1 align="center">🧱 cub3D 🎥</h1>

<p align="center">
  <a href="https://fr.wikipedia.org/wiki/MacOS_Mojave" target="_blank">
    <img alt="platform: osx 10.14.x" src="https://img.shields.io/badge/platform-osx%20v10.14.x-red?style=flat-square"/>
  </a>
  <a href="https://fr.wikipedia.org/wiki/C_(langage)" target="_blank">
    <img alt="language: c" src="https://img.shields.io/badge/language-C-purple?style=flat-square"/>
  </a>
  <a href="https://fr.wikipedia.org/wiki/OpenGL" target="_blank">
    <img alt="framework: opengl" src="https://img.shields.io/badge/framework-OpenGL-blue?style=flat-square"/>
  </a>
  <a href="https://developer.apple.com/documentation/appkit" target="_blank">
    <img alt="framework: appkit" src="https://img.shields.io/badge/framework-AppKit-blue?style=flat-square"/>
  </a>
  <a href="https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html" target="_blank">
    <img alt="library: minilibx" src="https://img.shields.io/badge/library-MiniLibX-orange?style=flat-square"/>
  </a>
  <a href="https://github.com/LoisDuplain/best-libft" target="_blank">
    <img alt="library: best-libft" src="https://img.shields.io/badge/library-best--libft-orange?style=flat-square"/>
  </a>
  <a href="https://profile.intra.42.fr/users/lduplain" target="_blank">
    <img alt="42 login: lduplain" src="https://img.shields.io/badge/42%20login-lduplain-green?style=flat-square"/>
  </a>
</p>

<p align="left">Readme in progress...</p>

<h2 align="left">🖼️ Gallery</h2>

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
./cub3D <map_path_1> <map_path_2> <map_path_...>
```

<p align="left">Automatically save first frame:</p>

```bash
./cub3D <map_path_1> <map_path_2> <map_path_...> --save
```

<h2 align="left">🎮 Controls</h2>

<p align="left">Player movement:</p>
<p align="left">
  <img alt="key: W" src="https://raw.githubusercontent.com/LoisDuplain/cub3D/main/readme-resources/W.png" width="60"/>
  <img alt="key: A" src="https://raw.githubusercontent.com/LoisDuplain/cub3D/main/readme-resources/A.png" width="60"/>
  <img alt="key: S" src="https://raw.githubusercontent.com/LoisDuplain/cub3D/main/readme-resources/S.png" width="60"/>
  <img alt="key: D" src="https://raw.githubusercontent.com/LoisDuplain/cub3D/main/readme-resources/D.png" width="60"/>
</p>

<p align="left">Camera rotation:</p>
<p align="left">
  <img alt="key: arrow_up" src="https://raw.githubusercontent.com/LoisDuplain/cub3D/main/readme-resources/arrow_up.png"/>
  <img alt="key: arrow_down" src="https://raw.githubusercontent.com/LoisDuplain/cub3D/main/readme-resources/arrow_down.png"/>
  <img alt="key: arrow_left" src="https://raw.githubusercontent.com/LoisDuplain/cub3D/main/readme-resources/arrow_left.png"/>
  <img alt="key: arrow_right" src="https://raw.githubusercontent.com/LoisDuplain/cub3D/main/readme-resources/arrow_right.png"/>
</p>

<h2 align="left">📝 Parsing</h2>
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
