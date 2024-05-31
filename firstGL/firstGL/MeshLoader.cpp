#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}



	}

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.ColourCount;

		if (mesh.ColourCount > 0)
		{
			mesh.Colours = new Colour[mesh.ColourCount];

			for (int i = 0; i < mesh.ColourCount; i++)
			{
				inFile >> mesh.Colours[i].r;
				inFile >> mesh.Colours[i].g;
				inFile >> mesh.Colours[i].b;
			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.IndexCount;

		for (mesh.IndexCount > 0) {
			mesh.Indices = new GLushort[mesh.IndexCount];

			for (int i = 0; i < mesh.IndexCount; i++) {
				inFile >> mesh.Indices;
			}


		}
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		//LOAD DATA USING METHODS ABOVE

		return mesh;
	}
}