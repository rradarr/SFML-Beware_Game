#include "SceneStateMachine.h"

SceneStateMachine::SceneStateMachine() : scenes(0), curScene(0), running(true)
{
}

SceneStateMachine::~SceneStateMachine()
{
	scenes.clear();
}

void SceneStateMachine::ProcessInput()
{
	if (curScene)
		curScene->ProcessInput();
}

void SceneStateMachine::Update(float deltaTime)
{
	if (curScene)
		curScene->Update(deltaTime);
}

void SceneStateMachine::LateUpdate(float deltaTime)
{
	if (curScene)
		curScene->LateUpdate(deltaTime);
}

void SceneStateMachine::Draw(Window & window)
{
	if (curScene)
		curScene->Draw(window);
}

bool SceneStateMachine::IsRunning() const
{
	return running;
}

void SceneStateMachine::StopRunning()
{
	running = false;
}

unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene)
{
	auto inserted = scenes.insert(std::make_pair(insertSceneID, scene));
	inserted.first->second->OnCreate();

	return insertSceneID++;
}

void SceneStateMachine::SwithTo(unsigned int id)
{
	auto it = scenes.find(id);
	if (it != scenes.end())
	{
		if (curScene)
		{
			curScene->OnDeactivate();
		}
		curScene = it->second;

		curScene->OnActivate();
	}
}

void SceneStateMachine::Remove(unsigned int id)
{
	auto it = scenes.find(id);
	if (it != scenes.end())
	{
		if (curScene == it->second)
		{
			curScene = nullptr;
		}
		it->second->OnDestroy();
		scenes.erase(it);
	}
}
