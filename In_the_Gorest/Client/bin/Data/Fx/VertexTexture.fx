

cbuffer cbViewMatrix : register(b0)
{
	matrix gMatView : packoffset(c0);
}

cbuffer cbProjMatrix : register(b1)
{
	matrix gMatProj : packoffset(c0);
}

cbuffer cbWorldMatrix : register(b2)
{
	matrix gMatWorld : packoffset(c0);
}

struct Vertex_In
{
	float4 pos : POSITION;
	float4 normal : NORMAL;
	float2 uv : UV;
};

struct Vertex_Out
{
	float4 pos : SV_POSITION;
	float4 normal : NORMAL;
	float2 uv : UV;
};

Vertex_Out VS(Vertex_In input)
{
	Vertex_Out output = (Vertex_Out)0;

	matrix matAll = mul(gMatWorld, gMatView);
	matAll = mul(matAll, gMatProj);

	output.pos = mul(input.pos, matAll);
	output.normal = input.normal;
	output.uv = input.uv;

	return output;
}

Texture2D gtxtTexture : register(t0);
SamplerState gSamplerState : register(s0);

float4 PS(Vertex_Out input) : SV_Target
{
	float4 cColor = gtxtTexture.Sample(gSamplerState, input.uv);
	return cColor;
}