#pragma once

namespace AssimpNet {

public ref class AssimpCamera
{
public:
	AssimpCamera(void);

	property String^ Name { String^ get() { return m_name; } }
	property Vector3 Position { Vector3 get(); }
	property Vector3 UpVector { Vector3 get(); }
	property Vector3 LookAt { Vector3 get(); }

	property float HFOV { float get(); }
	property float NearPlane { float get(); }
	property float FarPlane { float get(); }
	property float AspectRatio { float get(); }
internal:
	AssimpCamera(aiCamera* cam);
private:
	aiCamera* m_pCam;
	String^ m_name;
};

}
