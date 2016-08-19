#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "binaryLoad.h"

Maze loadBinFile (string progName, vector<pathway>& path) 
{
  	ifstream bin_file(progName.c_str(), ios::binary | ios::in);
    /* Check validity of file, return empty maze if fails */
  	if(!bin_file.is_open())
  	{
  		cout << "Unable to open file." << endl;
        return Maze();
  	}

  	// get length of file:
    bin_file.seekg (0, bin_file.end);
    int length = bin_file.tellg();
    bin_file.seekg (0, bin_file.beg);

    /* Getting maze information from start of file */
  	unsigned width = 0, height = 0, edgeCount = 0;

  	bin_file.read((char*)&width, sizeof(width));
  	bin_file.read((char*)&height, sizeof(height));
  	bin_file.read((char*)&edgeCount, sizeof(edgeCount));

  	//DEBUGGING
  	cout << "width: " << width << endl;
  	cout << "height: " << height << endl;
  	cout << "edges: " << edgeCount << endl;

  	/* Check maze dimension validity, return empty if fail */
  	if(width == 0 || height == 0 || edgeCount == 0)
  	{
  		cout << "Width or height of maze cannot be less than 1" << endl;
          return Maze();
  	}

    /* Initialise maze */
    Maze maze(width, height, edgeCount);
    //vector<pathway> path;

    /* Getting the edge information from file */
    int edgeCounter = 0;
    while(bin_file.tellg() != length)
    {
       // edges.push_back(edge());
        /* x1 */
       // bin_file.read((char*)&edges[edgeCounter].x1, sizeof(edges[edgeCounter].x1));
        /* y1 */
       // bin_file.read((char*)&edges[edgeCounter].y1, sizeof(edges[edgeCounter].y1));
        /* x2 */
       // bin_file.read((char*)&edges[edgeCounter].x2, sizeof(edges[edgeCounter].x2));
        /* y2 */
       // bin_file.read((char*)&edges[edgeCounter].y2, sizeof(edges[edgeCounter].y2));

        int x1, x2, y1, y2;
        bin_file.read((char*)&x1, sizeof(x1));
        bin_file.read((char*)&y1, sizeof(y1));
        bin_file.read((char*)&x2, sizeof(x2));
        bin_file.read((char*)&y2, sizeof(y2));
        path.push_back(pathway());
        path[edgeCounter].cell1 = maze.getCell(x1, y1);
        path[edgeCounter].cell2 = maze.getCell(x2, y2);

        edgeCounter++;

    }
  	
    maze.setPath(path);
    //maze.setEdges(edges);

  	return maze;
}