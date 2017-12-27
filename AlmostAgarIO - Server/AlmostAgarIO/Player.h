#pragma once

#include <string>
#include <SFML/Network.hpp>
#include <memory>
#include <utility>
#include <unordered_set>
#include <SFML/Graphics.hpp>

namespace std {
	template<>
	struct hash<sf::Vector2f> {
		size_t operator()(const sf::Vector2f & p) const {
			size_t seed = 0;
			hash<int> h;
			seed ^= h(p.x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			seed ^= h(p.y) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			return seed;
		}
	};
}

class Player
{
	unsigned int id;
	std::string name;
	sf::TcpSocket* tcpSocket;
	sf::UdpSocket* udpSocket;
	sf::IpAddress playerIp;
	unsigned int port;
	sf::Vector2f position;  //player position, in world coordinates (absolute coordinates)
	sf::Vector2f speed;     //player speed
	sf::Vector2f velocity;  //player velocity
	float radius;    //player's circle's radius
	int points;				//player's points
	sf::Vector2f mapSize;   //player's map size
	sf::Vector2f mapPosition;//player's map's location relative to world coordinates
	sf::Vector2f windowSize;//player's window size
	sf::Vector2f mousePosition;
	sf::Color color; //player's color

public:
	Player(int id, sf::Vector2f _position, sf::TcpSocket *tcpSocket);
	~Player();

	sf::TcpSocket* getTcpSocket() const;
	sf::UdpSocket* getUdpSocket() const;

	unsigned int getId() const;

	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f _position);

	sf::Vector2f getMapSize();
	void setMapSize(sf::Vector2f _mapSize);

	sf::Vector2f getMapPosition();
	void setMapPosition(sf::Vector2f _mapPosition);

	sf::Vector2f getWindowSize();
	void setWindowSize(sf::Vector2f _windowSize);

	float getRadius();
	void setRadius(float _radius);

	sf::IpAddress getPlayerIp();
	void setPlayerIp(sf::IpAddress _playerIp);

	sf::Vector2f getMousePosition();
	void setMousePosition(sf::Vector2f _mousePosition);

	void initPosition();

	sf::Color getColor();
	void setColor(sf::Color _color);

	//void init(std::vector<sf::Vector2f>& _food);
	//void updateFood(int index, sf::Vector2f newPosition);
	//void movePlayer()
};

