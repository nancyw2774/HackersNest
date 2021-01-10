#include "GameBoard.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"

using namespace Game;

GameBoard::GameBoard()
{
	CreateBackground(GameEngine::eTexture::Menu_bg);
	Wfh();
}

GameBoard::~GameBoard()
{
}

void GameBoard::Update()
{
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.0f, 50.0f));
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent *render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

	render->SetFillColor(sf::Color::White);
	render->SetTexture(GameEngine::eTexture::Garbage); // <-- Assign the texture to this entity

	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();
}

void GameBoard::CreateBackground(GameEngine::eTexture::type texture)
{
	background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(940.f, 540.f));
	background->SetSize(sf::Vector2f(1920.f, 1080.f));

	GameEngine::SpriteRenderComponent *render = static_cast<GameEngine::SpriteRenderComponent *>(background->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetTexture(texture);
	render->SetFillColor(sf::Color::White);
	render->SetZLevel(-1);
}

void GameBoard::TransitionPage()
{
	cleanTheBox = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(cleanTheBox);
}

void GameBoard::CleanTheBox()
{
	cleanTheBox = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(cleanTheBox);
}

void GameBoard::SortGarbage()
{
	sortGarbage = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(sortGarbage);
}

GameEngine::Entity* GameBoard::CreateImage(GameEngine::eTexture::type texture, float x, float y, float size_x, float size_y)
{
	image = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(image);

	image->SetPos(sf::Vector2f(x, y));
	image->SetSize(sf::Vector2f(size_x, size_y));

	//Render
	GameEngine::SpriteRenderComponent *render = image->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(texture); // <-- Assign the texture to this entity

	//Click status
	//image->AddComponent<Game::ImageClickComponent>();
	return image;
}



void GameBoard::Wfh()
{
	wfh = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(wfh);
	CreateBackground(GameEngine::eTexture::WFH_bg);
	GameEngine::Entity* instructions_wfh = CreateImage(GameEngine::eTexture::Instructions_wfh, 940.0f, 540.0f, 1920.0f, 1080.0f);
	GameEngine::Entity* counter = CreateImage(GameEngine::eTexture::Numbers,1090.0f,120.0f,1500.0f,200.0f);

	delete instructions_wfh;
	CreateImage(GameEngine::eTexture::Window, 150.0f, 125.0f, 300.0f, 250.0f);
	//int randX = rand() % +150
	//int randY = rand() % +125
}

void GameBoard::BakingBread()
{
	bakingBread = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bakingBread);
}
void GameBoard::WashHands()
{
	washHands = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(washHands);
}

void GameBoard::PutOnMask()
{
	putOnMask = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(putOnMask);
}