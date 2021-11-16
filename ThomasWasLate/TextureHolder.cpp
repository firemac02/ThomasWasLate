#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_Instance = nullptr;

TextureHolder::TextureHolder()
{
    assert(m_Instance == nullptr);
    m_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
    // Get a reference to the m_Textures map
    auto& m = m_Instance->m_Textures;
    // std::map<std::string, sf::Texture>

    // Create an iterator to hold a key-pair
    auto keyValuePair = m.find(filename);

    if (keyValuePair != m.end())
    {
        return keyValuePair->second;
    }
    else
    {
        // File not found
        // Create a new value pair using the filename
        auto& texture = m[filename];
        texture.loadFromFile(filename);

        return texture;
    }
    
}
