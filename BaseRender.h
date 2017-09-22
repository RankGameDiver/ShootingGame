#pragma once
class CBaseRender
{
public:
	enum eRenderType
	{
		eRenderType_Unknown,
		eRenderType_Bullet, // ź��
		eRenderType_Player, // �÷��̾�
		eRenderType_Enemy, // ����
		eRenderType_BackGround // ���
	};

	enum eEnemyKind
	{
		eEnemyKind_Banana, // �ٳ���
		eEnemyKind_Owner, // ����
		eEnemyKind_Rabbit, // �䳢
		eEnemyKind_Doll, // ����
		eEnemyKind_Bean, // ��
		eEnemyKind_WalnutDoll, // ȣ�α��
		eEnemyKind_Dog, // ������
		eEnemyKind_Purple, // �����
		eEnemyKind_Pumpkin, // ȣ��
	};
	
public:
	eRenderType m_eRenderType;
	eEnemyKind m_eEnemyKind;

	int m_iTextureHandle;

	D3DXVECTOR3		m_vPos; // ��ġ
	D3DXVECTOR3		m_vScale = D3DXVECTOR3(1.0f, 1.0f, 1.0f); // ũ��
	D3DXVECTOR3		m_vOffset;
	D3DCOLOR		m_d3dColor;

	CImageInfo	m_kImageInfo;

	D3DXMATRIX mat, matS, matR, matT; // ���

public:
	CBaseRender(void);
	virtual ~CBaseRender(void);
#ifdef _UNICODE
	bool Load(const TCHAR* szURL);
#else
	bool Load(const char* szURL);
#endif
	virtual bool Initialize();
	virtual void Terminate();
	virtual bool Pulse();
	virtual void RenderSet(D3DXVECTOR3 m_vPos);
	virtual void RenderSet(D3DXVECTOR3 m_vPos, float m_vRot);
	virtual void Render();
	virtual void Render(D3DXMATRIX mat);

public:
	__inline void SetPos(D3DXVECTOR3 vPos);
	__inline void SetScale(D3DXVECTOR3 vScale);
	__inline void SetColorKey(D3DCOLOR crKey);
	__inline D3DXVECTOR3 GetPos() const;
	__inline D3DXVECTOR3 GetScale() const;
	__inline void CBaseRender::SetRenderType(CBaseRender::eRenderType type);
};

__inline void CBaseRender::SetPos(D3DXVECTOR3 vPos)
{
	m_vPos = vPos;
}

__inline void CBaseRender::SetScale(D3DXVECTOR3 vScale)
{
	m_vScale = vScale;
}

__inline D3DXVECTOR3 CBaseRender::GetPos() const
{
	return m_vPos;
}

__inline D3DXVECTOR3 CBaseRender::GetScale() const
{
	return m_vScale;
}

__inline void CBaseRender::SetColorKey(D3DCOLOR crKey)
{
	m_d3dColor = 0xff000000 | crKey;
}

__inline void CBaseRender::SetRenderType(CBaseRender::eRenderType type)
{
	m_eRenderType = type;
}

