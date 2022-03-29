#include "ObjectManager.h"

ObjectManager::ObjectManager(Window& _window) : fileName("level_config.txt"), window(_window), shoppingCounter(0), infected(0)
{
}

ObjectManager::~ObjectManager()
{
	textures.empty();
}

void ObjectManager::ResetGame()
{
	shoppingCounter = 0;
	infected = 0;

	collectors.Clear();
	InitItems(5);

	UI.Update(shoppingCounter);

	clients.Clear();
	clients.PopulateLevel(70, textures);

	player.SetPosition(1920 + 100, 900 + 100);
	if (player.GetMask())
	{
		player.ChangeMask();
	}
}

bool ObjectManager::LoadTextures()
{
	sf::Texture loadedTexture;
	bool success = true;

	if (loadedTexture.loadFromFile("0.png"))
	{
		textures.push_back(loadedTexture);
	} else
	{
		success = false;
		std::cout << "ERROR: Couldn't load '0.png' texture." << std::endl;
	}
	if (loadedTexture.loadFromFile("1.png"))
	{
		textures.push_back(loadedTexture);
	}
	else
	{
		success = false;
		std::cout << "ERROR: Couldn't load '1.png' texture." << std::endl;
	}
	if (loadedTexture.loadFromFile("2.png"))
	{
		textures.push_back(loadedTexture);
	}
	else
	{
		success = false;
		std::cout << "ERROR: Couldn't load '2.png' texture." << std::endl;
	}
	if (loadedTexture.loadFromFile("3.png"))
	{
		textures.push_back(loadedTexture);
	}
	else
	{
		success = false;
		std::cout << "ERROR: Couldn't load '3.png' texture." << std::endl;
	}
	if (loadedTexture.loadFromFile("4.png"))
	{
		textures.push_back(loadedTexture);
	}
	else
	{
		success = false;
		std::cout << "ERROR: Couldn't load '4.png' texture." << std::endl;
	}
	if (loadedTexture.loadFromFile("notes.png"))
	{
		textures.push_back(loadedTexture);
	}
	else
	{
		success = false;
		std::cout << "ERROR: Couldn't load 'notes.png' texture." << std::endl;
	}
	if (loadedTexture.loadFromFile("player.png"))
	{
		textures.push_back(loadedTexture);
	}
	else
	{
		success = false;
		std::cout << "ERROR: Couldn't load 'player.png' texture." << std::endl;
	}
	if (loadedTexture.loadFromFile("client1.png"))
	{
		textures.push_back(loadedTexture);
	}
	else
	{
		success = false;
		std::cout << "ERROR: Couldn't load 'client1.png' texture." << std::endl;
	}
	return success;
}

bool ObjectManager::LoadLevel()
{
	//load the level
	std::ifstream configFile(fileName);
	if (!configFile.is_open())
	{
		std::cout << "ERROR: Couldn't open file " << fileName << std::endl;
		return false;
	}
	std::string read;
	std::stringstream line, set;
	float offset = 100; //offset to avoid negative coordinates
	unsigned int tex = 0;
	float rot = 0;
	float row = 0;
	float col = 0;
	int size = textures[0].getSize().x;
	char delim = ',';
	while (std::getline(configFile, read))
	{
		line << read;
		read.clear();
		while (line >> read)
		{
			set << read;
			set >> tex >> delim >> rot;
			if (tex >= textures.size())
			{
				std::cout << "ERROR: Invalid level configuration. Texture ID out of bounds." << std::endl;
				return false;
			}
			std::cout << tex << " " << delim << " " << rot << std::endl;

			level.AddSprite(textures[tex], col*size + offset, row*size + offset, 1, 1, rot);
			colliders.AddCollider(level.GetCollection().back(), tex);

			set.clear();
			read.clear();
			col++;
		}
		line.clear();
		row++;
		col = 0;
	}
	configFile.close();

	return true;
}

void ObjectManager::InitItems(int amount)
{
	std::vector<int> shelves;
	std::vector<int> exits;

	for (int i = 0; i < level.GetCollection().size(); i++)
	{
		if (level[i].getTexture() == &textures[1])
		{
			shelves.push_back(i);
		}
		else if (level[i].getTexture() == &textures[4])
		{
			exits.push_back(i);
		}
	}

	std::uniform_int_distribution<int> distribution (0, shelves.size() - 1);
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	int generated = distribution(generator);
	for (int i = 0; i < amount; i++)
	{
		while (shelves[generated] == -1)
		{
			generated = distribution(generator);
		}
		collectors.AddCollector(level[shelves[generated]]);
		shelves[generated] = -1;
		shoppingCounter++;
	}

	for (auto i : exits)
	{
		collectors.AddExit(level[i]);
	}
}

bool ObjectManager::InitClients(int amount)
{
	if (!clients.ReadGraph("path_init.txt"))
		return false;
	clients.PopulateLevel(amount, textures);
	return true;
}

void ObjectManager::InitUI()
{
	UI.AddNotes(textures[5], shoppingCounter);
}

void ObjectManager::InitPlayer()
{
	float offset = 100; //offset to avoid negative coordinates

	player.SetTexture(textures[6]);
	player.SetPosition(1920 + offset, 900 + offset);
	player.SetScale(3, 3);
}

SpriteCollection & ObjectManager::GetLevel()
{
	return level;
}

ObjectNotes & ObjectManager::GetUI()
{
	return UI;
}

std::vector<sf::Sprite> & ObjectManager::GetClients()
{
	return clients.GetCollection();
}

sf::Sprite & ObjectManager::GetPlayer()
{
	return player.GetSprite();
}

sf::RectangleShape & ObjectManager::GetColliderDrawable()
{
	return player.GetColliderDrawable();
}

ColliderCollection & ObjectManager::GetColliders()
{
	return colliders;
}

CollectorCollection & ObjectManager::GetCollectors()
{
	return collectors;
}

int ObjectManager::GetInfections()
{
	return infected;
}

void ObjectManager::SolveCollisions()
{
	player.GetCollider().setOutlineColor(sf::Color::Black);

	int size = colliders.GetCollection().size();
	for (int i = 0; i < size; i++)
	{
		if (colliders[i].getGlobalBounds().intersects(player.GetCollider().getGlobalBounds()))
		{
			player.GetCollider().setOutlineColor(sf::Color::Red);

			float xCorrection = 0;
			float yCorrection = 0;

			if (yCausesCollision(colliders[i].getGlobalBounds()))
			{
				yCorrection = ((colliders[i].getGlobalBounds().height / 2) + (player.GetCollider().getGlobalBounds().height / 2)) - (std::abs(colliders[i].getPosition().y - player.GetCollider().getPosition().y));
				if (colliders[i].getPosition().y > player.GetCollider().getPosition().y)
				{
					yCorrection *= -1;
					//std::cout << "From top player Y: " << player.GetCollider().getPosition().y << " collider Y: " << colliders[i].getPosition().y << std::endl;
					//std::cout << "yCorrection = " << colliders[i].getGlobalBounds().height / 2 << " + " << player.GetCollider().getGlobalBounds().height / 2 << " - " << std::abs(colliders[i].getPosition().y - player.GetCollider().getPosition().y) << " = " << yCorrection << std::endl;
				}
				else
				{
					//std::cout << "From bottom player Y: " << player.GetCollider().getPosition().y << " collider Y: " << colliders[i].getPosition().y << std::endl;
					//std::cout << "yCorrection = " << colliders[i].getGlobalBounds().height / 2 << " + " << player.GetCollider().getGlobalBounds().height / 2 << " - " << std::abs(colliders[i].getPosition().y - player.GetCollider().getPosition().y) << " = " << yCorrection << std::endl;
				}
			}

			if (xCausesCollision(colliders[i].getGlobalBounds())) {

				xCorrection = ((colliders[i].getGlobalBounds().width / 2) + (player.GetCollider().getGlobalBounds().width / 2)) - (std::abs(colliders[i].getPosition().x - player.GetCollider().getPosition().x));
				if (colliders[i].getPosition().x > player.GetCollider().getPosition().x)
				{
					xCorrection *= -1;
					//std::cout << "From roght player X: " << player.GetCollider().getPosition().x << " collider X: " << colliders[i].getPosition().x << std::endl;
					//std::cout << "xCorrection = " << colliders[i].getGlobalBounds().width / 2 << " + " << player.GetCollider().getGlobalBounds().width / 2 << " - " << std::abs(colliders[i].getPosition().x - player.GetCollider().getPosition().x) << " = " << xCorrection << std::endl;
				}
				else
				{
					//std::cout << "From roght player X: " << player.GetCollider().getPosition().x << " collider X: " << colliders[i].getPosition().x << std::endl;
					//std::cout << "xCorrection = " << colliders[i].getGlobalBounds().width / 2 << " + " << player.GetCollider().getGlobalBounds().width / 2 << " - " << std::abs(colliders[i].getPosition().x - player.GetCollider().getPosition().x) << " = " << xCorrection << std::endl;
				}
			}
			
			player.ProbeMove(xCorrection, yCorrection);
			i = 0; //fix for corners: loops until no collisions are found
		}
	}

	
}

bool ObjectManager::ChceckCollectors()
{
	if (shoppingCounter > 0 && collectors.CheckCollectors(player))
	{
		shoppingCounter--;
		UI.Update(shoppingCounter);
		if (shoppingCounter < 1)
		{
			collectors.ActivateExit();
		}
		std::cout << "Items left: " << shoppingCounter << std::endl;
	}
	else if (shoppingCounter < 1 && collectors.CheckCollectors(player))
	{
		std::cout << "DONE! Infected: " << infected << std::endl;
		return true;
	}
	return false;
}

void ObjectManager::MoveClients(float deltaTime)
{
	clients.MoveClients(deltaTime);
}

void ObjectManager::EvaluateInfections()
{
	if (clients.EvaluateInfections(player.GetSprite().getPosition(), player.GetMask()))
	{
		infected++;
	}
}

void ObjectManager::MovePlayer(float xMove, float yMove)
{
	player.Move(xMove, yMove);
}

void ObjectManager::ChangeMask()
{
	player.ChangeMask();
}

bool ObjectManager::xCausesCollision(sf::FloatRect collider)
{
	player.ProbeMove(-player.GetxMove(), 0);
	if (collider.intersects(player.GetCollider().getGlobalBounds()))
	{
		player.ProbeMove(player.GetxMove(), 0);
		return false;
	}
	player.ProbeMove(player.GetxMove(), 0);
	return true;
}

bool ObjectManager::yCausesCollision(sf::FloatRect collider)
{
	player.ProbeMove(0, -player.GetyMove());
	if (collider.intersects(player.GetCollider().getGlobalBounds()))
	{
		player.ProbeMove(0, player.GetyMove());
		return false;
	}
	player.ProbeMove(0, player.GetyMove());
	return true;
}