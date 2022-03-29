#include "CollectorCollection.h"

CollectorCollection::CollectorCollection()
{
}

CollectorCollection::~CollectorCollection()
{
	collectors.clear();
}

void CollectorCollection::Clear()
{
	collectors.clear();
}

void CollectorCollection::AddCollector(sf::Sprite & parent)
{
	ObjectCollector newCollector(parent);

	collectors.push_back(newCollector);
}

void CollectorCollection::AddExit(sf::Sprite & parent)
{
	ObjectCollector newExit(parent, true);

	collectors.push_back(newExit);
}

void CollectorCollection::ActivateExit()
{
	for (auto & collector : collectors)
	{
		if (collector.IsExit())
		{
			collector.ActivateExit();
		}

	}
}

bool CollectorCollection::CheckCollectors(ObjectPlayer & player)
{
	for (auto & collector : collectors)
	{
		if (collector.GetActive())
		{
			if (collector.Intersects(player.GetCollider()))
			{
				return true;
			}
		}
		
	}
	return false;
}

std::vector<ObjectCollector>& CollectorCollection::GetCollection()
{
	return collectors;
}
