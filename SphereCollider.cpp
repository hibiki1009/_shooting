#include "SphereCollider.h"
#include<math.h>
//#include "BoxCollider.h"


SphereCollider::SphereCollider()
{
    radius = 5;
}

SphereCollider::SphereCollider(int _radius)
{
    radius = _radius;// 自分の半径
}


bool SphereCollider::HitSphere(SphereCollider* spherecollider)const
{
   

    bool ret = false;//返り値

    float distance;	//中心座標の距離

    //中心座標の距離の計算    関数取得値→相手側  location →　自分側
    distance = sqrtf(powf(spherecollider->GetLocation().x - location.x, 2) + powf(spherecollider->GetLocation().y - location.y, 2));

    if (distance < radius + spherecollider->GetRadius()) //当たり判定
    {
        ret = true;// Hit
    }

    return ret;
}

int SphereCollider::GetRadius()const
{
    return radius;
}

Location SphereCollider::GetLocation()
{
    return location;
}

// ここまで

//SphereCollider::SphereCollider()
//{
//}
//
//SphereCollider::~SphereCollider()
//{
//}
//// プレイヤー、敵用
//int SphereCollider::GetSphere(int& _x, int& _y, float& _r)
//{
//    /*_x = sphere.locationX;
//    _y = sphere.locationY;
//    _r = sphere.radius;*/
//
//    /*printfDx("%d", sphere.locationX);*/
//    return 0;
//}
//
// //弾丸用
//int SphereCollider::GetBulletSphere(int& _x, int& _y, float& _r)
//{
//     Bullet_sphere.locationX = _x;
//     Bullet_sphere.locationY = _y;
//     Bullet_sphere.radius = _r;
//
//     return 0;
//}
//
//
//int SphereCollider::CheckCollision(SphereCollider sphereCollider) const {
//    Sphere other;// player
//    sphereCollider.GetSphere(other.locationX, other.locationY, other.radius);// Bullet
//        if (sphere.locationX <= other.locationX) {
//            return TRUE;
//        }
//        ///*printfDx("%d", sphere.locationX);*/
//        ///*GetSphere(sphere.locationX, other.locationY, other.radius);*/
//        //// 2点の距離を計算する
//        //cos = pow((sphere.locationX - Bullet_sphere.locationX),2);
//        //sin = pow((sphere.locationY - Bullet_sphere.locationY),2);
//    
//        //// 2つの円の中心の距離を出す
//        //tan = sqrt((cos+sin));
//    
//        //// 半径を比較 斜辺より大きい（重なっている）ならTRUE
//        //// 相手と自身が重なっているならヒット判定
//        //if (tan <= sphere.radius + Bullet_sphere.radius) {
//        //    return TRUE;
//        //}
//    
//        return FALSE;
//}
