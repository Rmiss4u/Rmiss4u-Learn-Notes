#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MyActor.generated.h"
UCLASS()
class CPP3DP_API AMyActor : public AActor
{
	GENERATED_BODY()
public:	
	AMyActor();//Ĭ�ϵĹ��캯�� ������������Ĭ��ֵ

	UPROPERTY(VisibleAnywhere,Category="My Actor Properties")//�ɼ� �ٷ���
	UStaticMeshComponent* StaticMesh;//����һ��ָ�� ע��:ָ������ǧ��Ҫ��ΪEditAnywhere

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Vector")//ֻ������ʾ���ϱ༭ �ٷ���
	FVector InitLocation;//��ʼ��λ��

	UPROPERTY(VisibleInstanceOnly, Category = "My Actor Properties | Vector")//ֻ������ʾ�ڱ༭���� �ٷ���
	FVector PlacedLocation;//��¼��ʼλ��

	UPROPERTY(EditDefaultsOnly, Category = "My Actor Properties | Vector")//ֻ������ģ���ϱ༭ �༭���Ͽ����� �ٷ���
	bool bGotoInitLocation;//����Ҫb��ͷ��������

	UPROPERTY(VisibleDefaultsOnly, Category = "My Actor Properties | Vector")//���ɱ��޸� �ٷ���
	FVector WorldOrigin;//�ο���������

	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Vector",//�ɼ��洦�ɸ� �ٷ���
		meta = (ClampMin = -5.0f, ClampMax = 5.0f, UIMin = -5.0f, UIMax = 5.0f))//�޶���Χ
	FVector TickLocationOffset;//ÿһ֡ƫ����

	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Physics")//�ɼ��洦�ɸ� �ٷ���
	bool bShouldMove;//����b��ͷ �����ƶ�

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Physics")//ֻ������ʾ���ϱ༭ �ٷ���
	FVector InitForce;//��ʼ��

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Physics")//ֻ������ʾ���ϱ༭ �ٷ���
	FVector InitTorque;//��ʼ����

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Physics")//ֻ������ʾ���ϱ༭ �ٷ���
	bool bAccelChange;//�Ƿ��������

protected:
	virtual void BeginPlay() override;//��д���麯�� ����ʱ���õĺ���
public:	
	virtual void Tick(float DeltaTime) override;//ÿ֡���õĺ��� DeltaTime֡����
};
