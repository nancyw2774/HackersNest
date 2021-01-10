#include "PlayerMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

using namespace Game;

// PlayerMovementComponent::PlayerMovementComponent()
//     //: m_lastNumIndex(0)
// {
// }
void PlayerMovementComponent::Update()
{
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    //By default the displacement is 0,0
    sf::Vector2f displacement{0.0f, 0.0f};

    //The amount of speed that we will apply when input is received
    const float inputAmount = 100.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        displacement.x -= inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        displacement.x += inputAmount * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        displacement.y += inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        displacement.y -= inputAmount * dt;
    }

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);

    // if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    // {
    //     m_count = true;
    // }
    // else
    // {
    //     if (m_count)
    //     {
    //         GameEngine::AnimationComponent *animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
    //         if (render)
    //         {
    //             render-> SetTileIndex(sf::Vector2i(m_count,0));
    //         }
    //     }
    //     m_count = false;
    // }
}

void PlayerMovementComponent::OnAddToWorld() {}