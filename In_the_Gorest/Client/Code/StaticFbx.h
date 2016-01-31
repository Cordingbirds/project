//class MyMesh : public CMesh{
//public:
//	MyMesh(ID3D11Device *pd3dDevice, char* pFileName);
//	//std::vector<MyVertex>* pOutVertexVector;
//	virtual ~MyMesh();
//	void Initialize(char* pFileName);
//
//	virtual void Render(ID3D11DeviceContext *pd3dDeviceContext);
//	virtual void CreateRasterizerState(ID3D11Device *pd3dDevice);
//
//private:
//	FbxManager* mFBXManager;
//	FbxScene* mFBXScene;
//	char* mInputFilePath;
//	FbxLongLong mAnimationLength;
//	std::string mAnimationName;
//	LARGE_INTEGER mCPUFreq;
//	D3DXVECTOR3 m_d3dxvScale;
//};