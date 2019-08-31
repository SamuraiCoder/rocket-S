#ifndef GRAPHICS_MANAGER
#define GRAPHICS_MANAGER

/*
* Graphics Manager
* May 2018.
* Class to manage renderer, windows and graphics.
*/

#include <iostream>
#include <assert.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "GameUtils\FileUtils.h"


namespace Graphics
{
	class CGraphicsManager
	{
	public:
		void Setup(int height, int width);

		SDL_Renderer *GetSDLRenderer(){ return _renderer; }

		static CGraphicsManager &Instance()
		{
			static CGraphicsManager _instance;
			return _instance;
		}

		//Member functions
		void SetupSDLWindow(int height, int width);
		void SetupSDLRenderer();
		void SetRendererLogicalSize(int height, int width);
		void CGraphicsManager::UpdateScreen();

		//CleanUp window, renderer, texture or surface.
		void cleanup(SDL_Window *win);
		void cleanup(SDL_Renderer *ren);
		void cleanup(SDL_Texture *tex);
		void cleanup(SDL_Surface *surf);

		/**
		* Loads an image into a texture on the rendering device
		* It support a lot of libraries and it's autodetected by SDL
		* Examples supported: PNG, BMP, TIFF, WEBP...
		* @param file The image file to load
		* @param ren The renderer to load the texture onto
		* @return the loaded texture, or nullptr if something went wrong.
		*/
		SDL_Texture* loadTexture(std::string res);

		/**
		* Draw an SDL_Texture to an SDL_Renderer at some destination rect
		* Send it to the renderer and
		* taking a clip of the texture if desired
		* @param tex The source texture we want to draw
		* @param ren The renderer we want to draw to
		* @param dst The destination rectangle to render the texture to
				default of nullptr draws the entire texture
		* @param clip The sub-section of the texture to draw (clipping rect)
		*		default of nullptr draws the entire texture
		*/
		void renderTexture(SDL_Texture *tex, SDL_Rect *dst = nullptr, SDL_Rect *clip = nullptr);

		/**
		* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
		* the texture's width and height and taking a clip of the texture if desired
		* If a clip is passed, the clip's width and height will be used instead of
		*	the texture's
		* @param tex The source texture we want to draw
		* @param ren The renderer we want to draw to
		* @param x The x coordinate to draw to
		* @param y The y coordinate to draw to
		* @param scale Scale for this sprite
		* @param clip The sub-section of the texture to draw (clipping rect)
		*		default of nullptr draws the entire texture
		*/
		void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int scale,  SDL_Rect *clip = nullptr);

		/**
		* Draw an SDL_Texture to an SDL_Renderer at some destination rect
		* taking a clip of the texture if desired
		* @param tex The source texture we want to draw
		* @param ren The renderer we want to draw to
		* @param dst The destination rectangle to render the texture to
		* @param clip The sub-section of the texture to draw (clipping rect)
		*		default of nullptr draws the entire texture
		*/
		void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst, SDL_Rect *clip);
		
		/**
		* Render the message we want to display to a texture for drawing
		* @param message The message we want to display
		* @param fontFile The font we want to use to render the text
		* @param color The color we want the text to be
		* @param fontSize The size we want the font to be
		* @param renderer The renderer to load the texture in
		* @return An SDL_Texture containing the rendered message, or nullptr if something went wrong
		*/
		SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize);

		/**
		* Render the message we want to display to a texture for drawing
		* @param message The message we want to display
		* @param font The font we want to use to render the text
		* @param color The color we want the text to be
		* @param fontSize The size we want the font to be
		* @param renderer The renderer to load the texture in
		* @return An SDL_Texture containing the rendered message, or nullptr if something went wrong
		*/
		SDL_Texture* renderText(const std::string &message, TTF_Font*font, SDL_Color color);

		/**
		*Loads an image up as a surface. 
		*/
		SDL_Surface* loadSurface(const std::string &file);

		/**
		*Converts a surface to a texture and optionally deletes the surface
		*/
		SDL_Texture *convertSurfaceToTexture(SDL_Surface* surface, bool cleanSurfaceAfter = false);
	protected:
		CGraphicsManager();
		CGraphicsManager(const CGraphicsManager&);
		CGraphicsManager& operator=(const CGraphicsManager&);
		~CGraphicsManager();

	private:
		//Class instance
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		
		void _InitializeSDL();

	};
}





#endif