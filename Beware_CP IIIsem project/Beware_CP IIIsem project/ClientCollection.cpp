#include "ClientCollection.h"

ClientCollection::ClientCollection()
{
	distribution = std::uniform_int_distribution<int>(7, 13);
	seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator = std::default_random_engine(seed);
}

ClientCollection::~ClientCollection()
{
	clients.clear();
	clientSprites.clear();
}

void ClientCollection::Clear()
{
	clients.clear();
	clientSprites.clear();
}

bool ClientCollection::ReadGraph(std::string fileName)
{
	std::ifstream graphFile(fileName);

	if (graphFile.is_open())
	{
		std::string read;
		std::stringstream ss;
		int id;
		int edge;
		float x, y;

		std::getline(graphFile, read);
		ss << read;
		ss >> id;
		paths.InitializeGraph(id);
		ss.clear();

		while (std::getline(graphFile, read, ';'))
		{
			ss << read;
			ss >> id;
			std::vector<int> edges;
			while (ss >> edge)
			{
				edges.push_back(edge);
			}
			graphFile >> x >> y;
			paths.AddVertex(id, edges, x, y);
			ss.clear();
		}
	}
	else
	{
		std::cout << "ERROR: Couldn't open file " << fileName << std::endl;
		return false;
	}
	return true;
}

void ClientCollection::PopulateLevel(int clientsAmount, const std::vector<sf::Texture>& _textures)
{
	clients = std::vector<ObjectClient>(clientsAmount);
	clientSprites = std::vector<sf::Sprite>(clientsAmount);

	std::uniform_int_distribution<int> distributionSpeed(30, 70);
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generatorSpeed(seed);

	for (int i = 0; i < clientsAmount; i++)
	{
		ObjectClient client;
		sf::Sprite clientSprite;

		clientSprite.setTexture(_textures[7]);
		clientSprite.setOrigin(clientSprite.getGlobalBounds().width / 2, clientSprite.getGlobalBounds().height / 2);
		clientSprite.setScale(3, 3);

		int startingVertex = paths.GetRandomVertexID();

		clientSprite.setPosition(paths[startingVertex]);
		client.SetTargetVertex(startingVertex);
		client.SetSpeed((distributionSpeed(generatorSpeed) / 100.f) * 100.f);
		
		clientSprites[i] = clientSprite;
		client.AppendSprite(clientSprites[i]);
		
		clients[i] = client;
	}
}

void ClientCollection::MoveClients(float deltaTime)
{
	for (unsigned int i = 0; i < clients.size(); i++)
	{
		clients[i].MoveClient(paths, deltaTime);
	}
}

bool ClientCollection::EvaluateInfections(sf::Vector2f _playerPos, bool _mask)
{
	for (auto & client : clients)
	{
		if (!client.GetInfected())
		{
			sf::Vector2f clientPos = client.GetPosition();
			float distance = sqrt(powf((clientPos.x - _playerPos.x), 2) + powf((clientPos.y - _playerPos.y), 2));

			if (distance < 100)
			{
				if (_mask)
				{
					float chance = (distribution(generator) / 10.f) * distance;
					if (chance < 20)
					{
						client.SetInfected();
						//std::cout << "Infected with mask!" << std::endl;
						return true;
					}
				}
				else
				{
					float chance = (distribution(generator) / 10.f) * distance;
					if (chance < 40)
					{
						client.SetInfected();
						//std::cout << "Infected without mask!" << std::endl;
						return true;
					}
				}
			}
		}
	}
	return false;
}

std::vector<sf::Sprite>& ClientCollection::GetCollection()
{
	return clientSprites;
}
