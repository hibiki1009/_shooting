#pragma once

struct Location
{
	/*static*/ float x; //中心座標(x)
	/*static*/ float y; //中心座標(y)
};

class SphereCollider
{
protected:
	int radius; // 半径
	Location location;// 当たり判定

public:
	SphereCollider(); // コンストラクタ  (初期化)
	SphereCollider(int _radius);
	int GetRadius() const; // 半径の取得
	bool HitSphere(SphereCollider* spherecollider)const; // 当たり判定

	Location GetLocation(); //中心座標を取得

	//Location SetLocation(SphereCollider* spherecollider);  //相手座標を自分の座標に合わせる 


};

