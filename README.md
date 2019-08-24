# Up Down Challenge

This is a project to solve a puzzle found in an awesome Nintendo Switch game called Tardy.

The puzzle consists in 7 indicators organized vertically that can have the ⬆️ or ⬇️ symbols, or nothing.
Next to each indicator, there's a button.


If a button with a ⬆️ is pressed, the ⬆️ arrow goes up only if there's a blank space immediately above it, 
or if there's a blank space above it with a ⬇️ arrow between. 
In the former case, the blank space and the ⬆️ arrow exchange places.
In the latter case, the blank space and the ⬆️ arrow exchange places and the ⬇️ is in the same place.

This is an attempt to solve this puzzle using the A* path finding algorithm implemented in C.