#include <iostream>
#include <fstream>
#include <vector>

#include "binarySave.h"

using namespace std;

bool saveBinFile(string fileName, Maze& maze)
{
    ofstream out(fileName.c_str(), ios::binary);

    /* Writing file header data */
    int width = maze.getWidth();
    int height = maze.getHeight();
    int edgeCount = maze.getEdgeCount();

    out.write((char*)&width, sizeof(width));
    out.write((char*)&height, sizeof(height));
    out.write((char*)&edgeCount, sizeof(edgeCount));

    /* Writing edge data to file */
    vector<pathway> paths = maze.getPaths();
    for(vector<pathway>::iterator it = paths.begin(); it != paths.end(); ++it)
    {
        int x1, y1, x2, y2;

        x1 = it->cell1->getCell().xPos;
        y1 = it->cell1->getCell().yPos;
        x2 = it->cell2->getCell().xPos;
        y2 = it->cell2->getCell().yPos;

        out.write((char*)&x1, sizeof(x1));
        out.write((char*)&y1, sizeof(y1));
        out.write((char*)&x2, sizeof(x2));
        out.write((char*)&y2, sizeof(y2));
    }

    /* Close and return */ 
    out.close();
    return true;
}