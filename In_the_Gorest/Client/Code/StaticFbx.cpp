#include "stdafx.h"


//MyMesh::MyMesh(ID3D11Device *pd3dDevice, char* pFileName) :CMesh(pd3dDevice){
//
//	mInputFilePath = pFileName;
//	Initialize(pFileName);
//	vector<D3DXVECTOR3*> pVertices;
//	FbxGeometryConverter clsConverter(mFBXManager);
//	clsConverter.Triangulate(mFBXScene, false);
//
//	FbxNode* pFbxRootNode = mFBXScene->GetRootNode();
//
//z
//	if (pFbxRootNode)
//	{
//		for (int i = 0; i < pFbxRootNode->GetChildCount(); i++)
//		{
//			FbxNode* pFbxChildNode = pFbxRootNode->GetChild(i);
//
//			if (pFbxChildNode->GetNodeAttribute() == NULL)
//				continue;
//
//			FbxNodeAttribute::EType AttributeType = pFbxChildNode->GetNodeAttribute()->GetAttributeType();
//
//			if (AttributeType != FbxNodeAttribute::eMesh)
//				continue;
//
//
//			FbxMesh* pMesh = (FbxMesh*)pFbxChildNode->GetNodeAttribute();
//			D3DXVECTOR3 m_pos;
//			FbxVector4* mControlPoints = pMesh->GetControlPoints();
//			int vertexCounter = 0;
//
//			//FbxVector4* pVertices = pMesh->GetControlPoints();
//
//			for (int j = 0; j < pMesh->GetPolygonCount(); j++)
//			{
//				int iNumVertices = pMesh->GetPolygonSize(j);
//				assert(iNumVertices == 3);
//				FbxGeometryElementUV* vertexUV = pMesh->GetElementUV(0);
//				FbxGeometryElementNormal* vertexNormal = pMesh->GetElementNormal(0);
//
//				for (int k = 0; k < iNumVertices; k++)
//				{
//					//정점데이터 얻어오기
//					int iControlPointIndex = pMesh->GetPolygonVertex(j, k);
//					int inTextureUVIndex = pMesh->GetTextureUVIndex(j, k);
//					++vertexCounter;
//					//pMesh->GetPolygonVertexNormal(j,k,);
//					m_pos.x = (float)mControlPoints[iControlPointIndex].mData[0];
//					m_pos.y = (float)mControlPoints[iControlPointIndex].mData[1];
//					m_pos.z = (float)mControlPoints[iControlPointIndex].mData[2];
//
//					D3DXVECTOR3*  m_Ver = new D3DXVECTOR3(m_pos.x, m_pos.z, -m_pos.y);
//					pVertices.push_back(m_Ver);
//
//					printf("%f, %f, %f\n", m_pos.x, m_pos.z, -m_pos.y);
//				}
//			}
//		}
//	}
//
//
//	int n = pVertices.size();
//	D3DXVECTOR3* ppVertices = new D3DXVECTOR3[n];
//	for (int i = 0; i < pVertices.size(); ++i)
//	{
//		ppVertices[i] = *pVertices.at(i);
//	}
//
//	m_nVertices = pVertices.size();
//	D3D11_BUFFER_DESC d3dBufferDesc;
//	m_d3dPrimitiveTopology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
//	ZeroMemory(&d3dBufferDesc, sizeof(D3D11_BUFFER_DESC));
//	d3dBufferDesc.Usage = D3D11_USAGE_DEFAULT;
//	d3dBufferDesc.ByteWidth = m_nStride * m_nVertices;
//	d3dBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//	d3dBufferDesc.CPUAccessFlags = 0;
//	D3D11_SUBRESOURCE_DATA d3dBufferData;
//	ZeroMemory(&d3dBufferData, sizeof(D3D11_SUBRESOURCE_DATA));
//	d3dBufferData.pSysMem = ppVertices;
//	pd3dDevice->CreateBuffer(&d3dBufferDesc, &d3dBufferData, &m_pd3dVertexBuffer);
//
//	CreateRasterizerState(pd3dDevice);
//}
//
//void MyMesh::Initialize(char* pFileName)
//{
//
//	mFBXManager = FbxManager::Create();
//	FbxIOSettings* pIOsettings = FbxIOSettings::Create(mFBXManager, IOSROOT);
//	mFBXManager->SetIOSettings(pIOsettings);
//	mFBXScene = FbxScene::Create(mFBXManager, "");
//
//	FbxImporter* pImporter = FbxImporter::Create(mFBXManager, "");
//	bool bSuccess = pImporter->Initialize(pFileName, -1, mFBXManager->GetIOSettings());
//	int a = 0;
//	if (!bSuccess) a = 1;
//	bSuccess = pImporter->Import(mFBXScene);
//	if (!bSuccess)  a = 1;
//
//	pImporter->Destroy();
//}
//
//MyMesh::~MyMesh(){
//
//}
//
//void MyMesh::CreateRasterizerState(ID3D11Device *pd3dDevice)
//{
//	D3D11_RASTERIZER_DESC d3dRasterizerDesc;
//	ZeroMemory(&d3dRasterizerDesc, sizeof(D3D11_RASTERIZER_DESC));
//	d3dRasterizerDesc.CullMode = D3D11_CULL_BACK;
//	d3dRasterizerDesc.FillMode = D3D11_FILL_SOLID;
//	pd3dDevice->CreateRasterizerState(&d3dRasterizerDesc, &m_pd3dRasterizerState);
//}
//
//void MyMesh::Render(ID3D11DeviceContext *pd3dDeviceContext)
//{
//	CMesh::Render(pd3dDeviceContext);
//}