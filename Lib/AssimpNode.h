#pragma once

namespace AssimpNet {

public ref class AssimpNode
{
public:
	property String^ Name { String^ get() { return m_name; } }
	property int MeshCount { int get(); }
	property List<int>^ MeshIndices { List<int>^ get(); }
	property Matrix LocalTransform { Matrix get(); }
	property Matrix RelativeTransform { Matrix get(); }
	property List<AssimpNode^>^ Children { List<AssimpNode^>^ get(); }
internal:
		AssimpNode(AssimpNode^ parent, aiNode* node);
private:
	Matrix GetTransform(aiMatrix4x4 tr);
	AssimpNode^ m_parent;
	List<AssimpNode^>^ m_children;

	aiNode* m_pNode;

	Matrix localtr;
	Matrix relativetr;

	String^ m_name;
};

}