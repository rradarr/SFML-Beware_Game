#include "SceneGame.h"

SceneGame::SceneGame(Window& _window, SceneStateMachine& _sceneMachine, ObjectManager& _objManager) : window(_window), sceneMachine(_sceneMachine), objManager(_objManager)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::OnCreate()
{
	if (!objManager.LoadTextures())
	{
		sceneMachine.StopRunning();
	}

	if (!objManager.LoadLevel())
	{
		sceneMachine.StopRunning();
	}

	objManager.InitItems(5);

	objManager.InitUI();

	if (!objManager.InitClients(70))
	{
		sceneMachine.StopRunning();
	}
	
	objManager.InitPlayer();
}

void SceneGame::OnDestroy()
{
}

void SceneGame::OnDeactivate()
{
}

void SceneGame::SetPauseScene(unsigned int _id)
{
	pauseScene = _id;
}

void SceneGame::SetNextScene(unsigned int _id)
{
	nextScene = _id;
}


void SceneGame::ProcessInput()
{
	input.Update();
}

void SceneGame::Update(float deltaTime)
{
	const int moveSpeed = 100;
	int xMovement = 0;
	int yMovement = 0;

	if (input.IsKeyHeld(Input::Key::Esc))
	{
		sceneMachine.SwithTo(pauseScene);
	}
	if (input.IsKeyHeld(Input::Key::Right))
	{
		xMovement = moveSpeed;
	}
	else if (input.IsKeyHeld(Input::Key::Left))
	{
		xMovement = -moveSpeed;
	}

	if (input.IsKeyHeld(Input::Key::Up))
	{
		yMovement = -moveSpeed;
	}
	else if (input.IsKeyHeld(Input::Key::Down))
	{
		yMovement = moveSpeed;
	}

	if (input.IsKeyDown(Input::Key::E))
	{
		if (objManager.ChceckCollectors())
		{
			sceneMachine.SwithTo(nextScene);
		}
	}

	if (input.IsKeyDown(Input::Key::M))
	{
		objManager.ChangeMask();
	}

	float xFrameMovement = xMovement * deltaTime;
	float yFrameMovement = yMovement * deltaTime;
	objManager.MovePlayer(xFrameMovement, yFrameMovement);

	objManager.MoveClients(deltaTime);
}

void SceneGame::LateUpdate(float deltaTime)
{
	objManager.SolveCollisions();

	objManager.EvaluateInfections();

	auto player = objManager.GetPlayer();
	sf::View view = window.getView();
	view.setCenter(player.getPosition());
	view.setSize(600, 400);
	window.setView(view);
}

void SceneGame::Draw(Window & window)
{
	for (auto & tile : objManager.GetLevel().GetCollection()) {
		window.Draw(tile);
	}

	for (auto & collectorOverlay : objManager.GetCollectors().GetCollection())
	{
		window.Draw(collectorOverlay.GetOverlay());
		//window.Draw(collectorOverlay.GetCollector());
	}
	
	for (auto & client : objManager.GetClients()) {
		window.Draw(client);
	}
	
	
	//debug
	/*for (auto & collider : objManager.GetColliders().GetCollection())
	{
		window.Draw(collider);
	}
	window.Draw(objManager.GetColliderDrawable());*/
	//debug

	window.Draw(objManager.GetPlayer());
	
	//UI elements
	sf::View view = window.getView();
	window.setView(window.getDefaultView());

	window.Draw(objManager.GetUI().GetSprite());
	for (auto & elem : objManager.GetUI().GetText())
	{
		window.Draw(elem);
	}
	window.setView(view);
}
