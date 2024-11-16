#ifndef __TILE_H__
#define __TILE_H__

class Tile
{
public:
	Tile();

	~Tile();

	bool IsOccupied() const;

	void SetOccupied(bool occupied);

	void SetIndex(int x, int y);

	int GetX() const;

	int GetY() const;

private:
	bool m_occupied;

	int m_x;
	int m_y;
};

#endif
