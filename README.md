# SFML-Beware_Game
University semester project for Computer Programming sem III. It's a 2D game that is supposed to highlight the importance of physical distancing and wearing a mask during the COVID-19 pandemic. Created using C++ and SFML.

## Beware

In the game the player needs to pick up some items in a shopping mall. The items are respresented by glowing shelves and are spread across the level.

![screen](https://user-images.githubusercontent.com/56255228/162787416-b7f37d5f-de07-49c2-91e1-a77ce44ceab6.PNG)

## Technical aspects

The problem of controlling the AI clients was solved by loading a pre-made graph structure from a text file that represents the paths that clients can take. A vertex is described by an ID and some coordinates in the game and an edge between two vertices means that the clients can move between them in a straight line, with no obstacles in the way. The clients are spawned at random vertices at the start of the game and pick a random adjacent vertex to move to. Once they get there they repeat the process of picking a new adjacent vertex with the exclusion of the vertex they just came from. This results in nicer, more coherent movement. The graph is represented by an adjacency matrix. Thanks to this approach there was no need to implement a path finding algorithm. This way the clients also don’t have any collisions which simplifies the implementation and improves performance.

The collisions for the player were implemented by storing the last change in position and using it to correct the players position in case of a collision with a Collider object.

The player can collect items by pressing E while being close to the shelve, that is when the player’s collision box is in contact with the shelve’s collection box. The level is built out of tiles. The overall layout of the level is also loaded from a text file which contains sequences of pairs of numbers representing the type of texture to be used for the tile and it’s desired rotation. This approach was very useful both in the early and late stages of development where changes to the map could be easily introduced without altering the code.

## Controls
The game in controlled using the keyboard.

The key bindings are as follow:

- W : up
- S : down
- D : right
- A : left
- E : pick up
- M : put on/ take off the mask
- Escape : pause menu
- Enter : choose option 
 
In menus W and S is used to navigate.

## More

Details are avialable in the [Final CG Raport](./Beware%20CG%20Final%20Raport.pdf) PDF which was created as the final artifact of the Computer Programming project.
