#pragma once

struct Location
{
	/*static*/ float x; //���S���W(x)
	/*static*/ float y; //���S���W(y)
};

class SphereCollider
{
protected:
	int radius; // ���a
	Location location;// �����蔻��

public:
	SphereCollider(); // �R���X�g���N�^  (������)
	SphereCollider(int _radius);
	int GetRadius() const; // ���a�̎擾
	bool HitSphere(SphereCollider* spherecollider)const; // �����蔻��

	Location GetLocation(); //���S���W���擾

	//Location SetLocation(SphereCollider* spherecollider);  //������W�������̍��W�ɍ��킹�� 


};

