#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

namespace yap
{
  Sprite::Sprite ()
    : BaseSprite ()
    , texture_ (nullptr)
  {
  }

  Sprite::Sprite (Texture* texture)
    : BaseSprite ()
    , texture_ (texture)
  {
  }

  Sprite::Sprite (const String& textureName)
    : BaseSprite ()
    , texture_ (new Texture (textureName))
  {
  }

  Sprite::Sprite (const String& textureName, const sf::IntRect& textureRect)
    : BaseSprite ()
    , texture_ (new Texture (textureName, textureRect))
  {
  }

  Sprite::~Sprite ()
  {
    delete texture_;
    texture_ = nullptr;
  }

  void Sprite::SetTexture (Texture* texture)
  {
    texture_ = texture;
  }

  void Sprite::HandleMove (const Vector2& offset)
  {
    texture_->Move (offset);
  }

  void Sprite::HandleScale (const Vector2& factor)
  {
    texture_->Scale (factor);
  }

  void Sprite::HandleDraw (IDrawingContext& context)
  {
    texture_->Draw (context);
  }

  void Sprite::HandleShow (bool isVisible)
  {
  }

  void Sprite::HandleChangeColor (const sf::Color& color)
  {
    texture_->ChangeColor (color);
  }

  void Sprite::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap