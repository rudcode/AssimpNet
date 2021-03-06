#pragma once

#include <vector>

namespace AssimpNet {

public ref class AssimpMesh : IDisposable
{
public:
	AssimpMesh(void);
	~AssimpMesh(void);
	property int MaterialIndex { int get(); }

	property int VerticesCount { int get(); }
	property int MaxBonePerVertex { int get(); }

	property bool HasNormals { bool get(); }
	property int UvChannelCount { int get(); }
	property int ColorChannelCount { int get(); }

	//Pointer access to channels
	property System::IntPtr PositionPointer { System::IntPtr get(); }
	property System::IntPtr NormalsPointer { System::IntPtr get(); }

	System::IntPtr GetUvPointer(int idx);

	property List<int>^ Indices { List<int>^ get(); }
	property List<String^>^ BoneNames { List<String^>^ get(); }
	property List<Matrix>^ BoneMatrices { List<Matrix>^ get(); }

	property DataStream^ Vertices { DataStream^ get(); }
	property SlimDX::BoundingBox BoundingBox { SlimDX::BoundingBox get(); }

	property String^ Name { String^ get() { return m_name; } }

	void Write(DataStream^ vertices);

	List<SlimDX::Direct3D11::InputElement>^ GetInputElements();
	int CalculateVertexSize();
	void Initialize();
internal:
	AssimpMesh(const aiScene* scene, aiMesh* mesh);

protected:
	aiMesh* m_pMesh;

private:
	

	void LoadIndices();
	void LoadVertices();

	//Cached Data
	List<int>^ m_indices;
	List<String^>^ m_bonenames;
	List<Matrix>^ m_bonemats;
	DataStream^ m_vertices;
	SlimDX::BoundingBox m_bb;
	int m_maxBonePerVertex;
	String^ m_name;

	Matrix GetTransform(aiMatrix4x4 tr);
	aiNode* FindNodeRecursivelyByName(aiNode* root,const aiString name);

	
};

}