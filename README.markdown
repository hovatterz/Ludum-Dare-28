# LD28 Entry

The theme for this entry is "You Only Get One". I decided to make a
roguelike since you only get one life.

## Controls

| Key | Action      |
| --- | ----------- |
| k   | move north  |
| j   | move south  |
| h   | move west   |
| l   | move east   |

Menus are controlled by the hjkl direction keys as well.

## Building

This game requires a few libraries to build.

- [entityx](https://github.com/alecthomas/entityx)
- [termbox](https://github.com/nsf/termbox)

After they are installed, you should just be able to run `make`. The game
builds to the `bin` directory.
