#include "GraphicsManager.h"


using std::cout;
using std::endl;

namespace Graphics
{
	CGraphicsManager::CGraphicsManager()
	{
		cout << "[GraphicsManager] CGraphicsManager init" << endl;
		_InitializeSDL();
	}

	void CGraphicsManager::Setup(int height, int width)
	{
		//Setup window
		SetupSDLWindow(height, width);

		//Setup renderer
		SetupSDLRenderer();

		//Setup Logical Size for the screen
		SetRendererLogicalSize(height, width);
	}

	CGraphicsManager::~CGraphicsManager()
	{
		if (_renderer)
			cleanup(_renderer);
		if (_window)
			cleanup(_window);
	
		_window = NULL;
		_renderer = NULL;		
	}

	void CGraphicsManager::_InitializeSDL()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			cout << "[GraphicsManager] SDL init error" << endl;
		}
	}

	void CGraphicsManager::SetupSDLWindow(int height, int width)
	{
		_window = SDL_CreateWindow("RocketS Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, SDL_WINDOW_SHOWN); //SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN
		if (_window == nullptr)
		{
			SDL_Quit();
			cout << "[GraphicsManager] SDL Window create error." << endl;
		}
	}

	void CGraphicsManager::SetupSDLRenderer()
	{
		_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (_renderer == nullptr){
			cleanup(_window);
			SDL_Quit();
			cout << "[GraphicsManager] SDL Renderer create error" << endl;
		}
	}

	void CGraphicsManager::SetRendererLogicalSize(int height, int width)
	{
		SDL_RenderSetLogicalSize(_renderer, height, width);
	}

	void CGraphicsManager::cleanup(SDL_Window *win){
		if (!win){
			return;
		}
		SDL_DestroyWindow(win);
	}

	void CGraphicsManager::cleanup(SDL_Renderer *ren){
		if (!ren){
			return;
		}
		SDL_DestroyRenderer(ren);
	}

	void CGraphicsManager::cleanup(SDL_Texture *tex){
		if (!tex){
			return;
		}
		SDL_DestroyTexture(tex);
	}

	void CGraphicsManager::cleanup(SDL_Surface *surf){
		if (!surf){
			return;
		}
		SDL_FreeSurface(surf);
	}

	SDL_Texture* CGraphicsManager::loadTexture(std::string res)
	{
		SDL_Texture* texture = IMG_LoadTexture(_renderer, res.c_str());
		if (texture == nullptr)
		{
			cout << "[GraphicsManager] SDL reported an error trying to load the resource: " << res.c_str() << endl;
		}

		return texture;
	}

	void CGraphicsManager::renderTexture(SDL_Texture *tex, SDL_Rect *dst, SDL_Rect *clip)
	{
		SDL_RenderCopy(_renderer, tex, clip, dst);
	}

	void CGraphicsManager::renderTexture(SDL_Texture *tex, SDL_Rect *dst, SDL_Rect *clip, const SDL_RendererFlip flip)
	{
		SDL_RenderCopyEx(_renderer, tex, clip, dst, 0.0f, nullptr, flip);
	}

	void CGraphicsManager::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int scale, bool flip, SDL_Rect *clip)
	{
		SDL_Rect dst;
		dst.x = x;
		dst.y = y;
		if (clip != nullptr)
		{
			dst.w = clip->w * scale;
			dst.h = clip->h * scale;
		}
		else 
		{
			SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
		}

		if (flip)
		{
			renderTexture(tex, &dst, clip, SDL_FLIP_HORIZONTAL);
		}
		else
		{
			renderTexture(tex, &dst, clip);
		}
	}

	void CGraphicsManager::UpdateScreen()
	{
		SDL_RenderPresent(_renderer);
	}

	void CGraphicsManager::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst, SDL_Rect *clip)
	{
		SDL_RenderCopy(ren, tex, clip, &dst);
	}

	SDL_Texture* CGraphicsManager::renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize)
	{
		//Open the font
		TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
		if (font == nullptr){
			cout << "TTF_OpenFont error" << endl;
			return nullptr;
		}
		//We need to first render to a surface as that's what TTF_RenderText
		//returns, then load that surface into a texture
		SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
		if (surf == nullptr){
			TTF_CloseFont(font);
			cout << "TTF_RenderText error" << endl;
			return nullptr;
		}
		SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surf);
		if (texture == nullptr){
			cout << "CreateTexture" << endl;
		}
		//Clean up the surface and font
		SDL_FreeSurface(surf);
		TTF_CloseFont(font);
		return texture;
	}

	SDL_Texture* CGraphicsManager::renderText(const std::string &message, TTF_Font *font, SDL_Color color)
	{
		if (font == nullptr){
			cout << "TTF_OpenFont" << endl;
			return nullptr;
		}
		//We need to first render to a surface as that's what TTF_RenderText
		//returns, then load that surface into a texture
		SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
		if (surf == nullptr){
			cout << "TTF_RenderText" << endl;
			return nullptr;
		}
		SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surf);
		if (texture == nullptr){
			cout << "CreateTexture" << endl;
		}
		//Clean up the surface and font
		SDL_FreeSurface(surf);
		//	TTF_CloseFont(font);
		return texture;
	}

	SDL_Surface* CGraphicsManager::loadSurface(const std::string &file){
		SDL_Surface *surface = IMG_Load(file.c_str());
		if (surface == nullptr)
		{
			cout << "[GraphicsManager] SDL reported an error trying to load the surface: " << file.c_str() << endl;
		}
		return surface;
	}

	SDL_Texture* CGraphicsManager::convertSurfaceToTexture(SDL_Surface* surface, bool cleanSurfaceAfter)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
		if (cleanSurfaceAfter)
			cleanup(surface);

		return texture;
	}

}