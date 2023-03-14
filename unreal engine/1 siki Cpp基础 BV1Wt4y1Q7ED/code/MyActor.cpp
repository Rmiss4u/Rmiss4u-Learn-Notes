#include "MyActor.h"
#include "Components/StaticMeshComponent.h"
AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;//�����true��ÿ֡����Tick �����false��������

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));//���������̬������

	InitLocation = FVector(0.0f);//��ʼ��λ��
	PlacedLocation = FVector(0.0f);//��ʼ����ʼλ�õĴ洢����
	bGotoInitLocation = false;//Ĭ�ϲ�ȥ ��ԭ��λ��
	WorldOrigin == FVector(0.0f);//��������ο�����
	TickLocationOffset = FVector(0.0f);//Ĭ��ÿ֡ƫ����0f
	bShouldMove = false;//�Ǳ����ƶ�

	InitForce = FVector(0.0f);
	InitTorque = FVector(0.0f);
	bAccelChange = false;
}
void AMyActor::BeginPlay()
{
	Super::BeginPlay();//��֤������InitLocation
	PlacedLocation = GetActorLocation();//��ȡ��ʼλ��
	if (bGotoInitLocation)//������ƶ� ������ת��ָ��λ��
	{
		SetActorLocation(InitLocation);//����actorλ��
						//����һ��ֵ ��xyz����ɴ���ֵ
						//��������ֵ �ֱ�ֵxyz
	}
	//����unreal doc ��UStaticMeshComponentָ������c++ API ��һ�� ���Ѱ�ҵ�����Header
	//�ҵ�Runtime/Engine/Classes/Components/StaticMeshComponent.h
	//��Classes����ĸ��Ƽӵ�ͷ�ļ�
	//StaticMesh->AddForce(InitForce,"NAME_None",bAccelChange);//ģ������
	//StaticMesh->AddTorque(InitTorque, "NAME_None", bAccelChange);
}
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bShouldMove) {//Ӧ�ý����ƶ�
		FHitResult HitResult;//�������ڼ��
		AddActorLocalOffset(TickLocationOffset* DeltaTime,true,&HitResult);//ƫ���� ÿһ֡,����ɨ��
											//����DeltaTime���ɲ��ᱻ֡����Ӱ��
		UE_LOG(LogTemp, Warning, TEXT("X:%f , Y:%f , Z:%f"), 
			HitResult.Location.X, HitResult.Location.Y, HitResult.Location.Z);//��������Ӵ��� ���������Ϣ

	}
}

