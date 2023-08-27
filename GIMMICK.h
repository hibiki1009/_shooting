#pragma once
#include"DxLib.h"
#include"SphereCollider.h"

// memo
// �G�̔ԍ��@�v���C���[�̍��W�EHP�@

// �{�X��ŃT�[�N�����o���A�J�E���g�_�E�����n�܂�A
// 0�̎��v���C���[���~�ɓ����Ă�����m��L��

// �~�͓��ށ@�v���C���[��ǔ����A���Ԃ��������́i20�b�ő傫���j
// �v���C���[�̒ǔ����Ȃ����Ԃ��Z������(5�b��������)
class GIMMICK :public SphereCollider
{
public:
	// �R���X�g���N�^
	GIMMICK(int e_num);
	// �f�X�g���N�^
	~GIMMICK();
	void KillCircle_Update();
	void KillCircle_Draw();

	void Set_P_Location(float _x,float _y);
	void Set_P_Hp(int _hp);
	int Get_Damage();
	float Get_Circle_time();
	bool Get_CircleKill();
private:
	int E_num;
	int waitTime;
	float circle_time;	//�@�T�[�N���̎��Ԃ��Ǘ�����
	int Spown_circle_time;	// �T�[�N���̃��X�|�[�������p
	float Px, Py;
	int P_hp;
	int Damage;
	bool kill;
};

