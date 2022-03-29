#include "Game.h"

Game::Game(): window("Beware"), objManager(window)
{
	std::shared_ptr<SceneMenu> menuScene = std::make_shared<SceneMenu>(window, sceneStateMachine);
	unsigned int menuSceneID = sceneStateMachine.Add(menuScene);

	std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>(window, sceneStateMachine, objManager);
	unsigned int gameSceneID = sceneStateMachine.Add(gameScene);

	std::shared_ptr<SceneMenuPause> pauseScene = std::make_shared<SceneMenuPause>(window, sceneStateMachine, objManager);
	unsigned int pauseSceneID = sceneStateMachine.Add(pauseScene);

	std::shared_ptr<SceneMenuStats> statsScene = std::make_shared<SceneMenuStats>(window, sceneStateMachine, objManager);
	unsigned int statsSceneID = sceneStateMachine.Add(statsScene);

	menuScene->SetNextScene(gameSceneID);
	gameScene->SetNextScene(statsSceneID);
	gameScene->SetPauseScene(pauseSceneID);
	pauseScene->SetNextScene(gameSceneID);
	statsScene->SetNextScene(gameSceneID);
	sceneStateMachine.SwithTo(menuSceneID);
	
	deltaTime = clock.restart().asSeconds();
}

Game::~Game()
{
}

void Game::ProcessInput()
{
	sceneStateMachine.ProcessInput();
}

void Game::Update()
{
	window.Update();

	sceneStateMachine.Update(deltaTime);
}

void Game::LateUpdate()
{
	sceneStateMachine.LateUpdate(deltaTime);
}

void Game::Draw()
{
	window.BeginDraw();

	sceneStateMachine.Draw(window);

	window.EndDraw();
}

bool Game::IsRunning() const
{
	return window.IsOpen() && sceneStateMachine.IsRunning();
}

void Game::GetDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}
