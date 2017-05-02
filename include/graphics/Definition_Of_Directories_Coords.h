struct Vertex
{
	float _x, _y, _z;
};

struct Graph
{
	Graph* _subDirs;
	Vertex* _files;
	Vertex _own;
	uint32_t countDirs;
	uint32_t countFiles;
};

Vertex* Definition_Of_Files_Coord(uint32_t count, Vertex center)
{
	uint32_t	border1 = 3, border2 = 5, border3 = 7,
		borderShift = 10,
		initialValue = 0.1,
		sizeSquare = 3;
	const uint32_t shiftCoord = 1;

	while (count > sizeSquare*sizeSquare - 1)
	{
		sizeSquare += 2;
	}
	Vertex* files = new Vertex[count];
	files[0]._x = center._x + 1;
	files[0]._y = center._y + 1;
	files[0]._z = center._z;
	for (uint32_t j = 3; j <= sizeSquare; j += 2)
	{
		for (uint32_t i = initialValue; i < count; i++)
		{
			if (i < border1)
			{
				files[i]._x = files[i - 1]._x - shiftCoord;
				files[i]._y = files[i - 1]._y;
			}

			if (i > border1 - 1 && i < border2)
			{
				files[i]._x = files[i - 1]._x;
				files[i]._y = files[i - 1]._y - shiftCoord;
			}

			if (i > border2 - 1 && i < border3)
			{
				files[i]._x = files[i - 1]._x + shiftCoord;
				files[i]._y = files[i - 1]._y;

			}

			if (i > border3 - 1 && i < j*j - 1)
			{
				files[i]._x = files[i - 1]._x;
				files[i]._y = files[i - 1]._y + shiftCoord;
			}

			files[i]._z = 0.0;

			if (i == (j*j - 2))
			{
				files[j*j - 1]._x = files[initialValue - 1]._x + 1;
				files[j*j - 1]._y = files[initialValue - 1]._y + 1;
				files[j*j - 1]._z = 0.0;
				initialValue = j*j;
				border1 += borderShift;
				border2 += borderShift + 2;
				border3 += borderShift + 4;
				borderShift += 8;
				break;
			}
		}
	}
	return files;
}

float		X = 0.0,
			Y = 0.0,
			Z = 0.0;
uint32_t	counter = 0,
			border1 = 3,	
			border2 = 5, 
			border3 = 7,
			borderShift = 10, 
			j = 3;

void Definition_of_directories_coords(Graph tree)
{
	
	tree._own._x = X;
	tree._own._y = Y;
	tree._own._z = Z;
	Definition_Of_Files_Coord(tree.countFiles, tree._own);
	++counter;
	if (counter == 1)
	{
		++X;
		++Y;
	}
	if (counter > 1 && counter < border1)
	{
		--X;
	}
	if (counter > border1 - 1 && counter < border2)
	{
		--Y;
	}

	if (counter > border2 - 1 && counter < border3)
	{
		++X;
	}

	if (counter > border3 - 1 && counter < j*j - 1)
	{
		++Y;
	}
	if (counter == j*j - 2)
	{
		++X;
		++Y;
		border1 += borderShift;
		border2 += borderShift + 2;
		border3 += borderShift + 4;
		borderShift += 8;
		j += 2;
	}

	for (uint32_t i = 0; i < tree.countDirs; ++i)
	{
		Definition_of_directories_coords(tree._subDirs[i]);
	}
}