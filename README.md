# rocket-S (another copy of MetalSlug in C++)
C++ framework to create a 2D game.

This is just a small project I want to try in order to check how SDL2 works and basically start making a simple engine that manages everything involved in a simple gameplay.

I based all the art in one of my favourites 2D game "Metal Slug". I've just scavenged all the art from many places and I hope artists will be fine with this. 

It contains the following:

- Sprite animation based: Frame(minimum unit), FrameAnimation(a collection of Frames) and FrameAnimationSet (contains all the FrameAnimations).
- A GraphicsManager that just renders frames. I let SDL to manage all of this +)
- An InputManager that can send keyboards (and mouse) events to the one that subscribes to it.
- A MessageDispatcher that sends any message to components on entities.
- A component-based architecture for entities (Controllers) that uses the previous MessageDispatcher to arrange commands (messages).
- A really-weird way of loading an FrameAnimationSet that will be refactor into JSON.

This is the current status on how it looks.  

![alt text](https://i.imgur.com/naUML43.png)

