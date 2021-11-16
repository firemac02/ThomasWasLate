#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map> // <- part of the Standard Template Library (STL)

class TextureHolder
{
private:
	// a map container that holds a related pair of String and Texture
	std::map<std::string, sf::Texture> m_Textures;

	// a pointer of the same type as the class itself
	static TextureHolder* m_Instance;

public:
	TextureHolder();
	static sf::Texture& GetTexture(std::string const& filename);
};


#endif TEXTURE_HOLDER_H
