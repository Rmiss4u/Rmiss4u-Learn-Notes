#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"
UCLASS()//APawn�Ѿ����긽�� ������Բ�������
class CPP3DP_API AMyPawn : public APawn
{
	GENERATED_BODY()
public:
	AMyPawn();

	UPROPERTY(VisibleAnywhere, Category = "My Pawn Components")//�ɼ� ���ɸ�
	class UStaticMeshComponent* MyStaticMesh;//����һ��ָ�� ע��:ָ������ǧ��Ҫ��ΪEditAnywhere
		//���clssǰ׺Ϊ��ܲ���Ҫ���鷳

	UPROPERTY(VisibleAnywhere, Category = "My Pawn Components")//�ɼ� ���ɸ�
	class USpringArmComponent* MySpringArm;

	UPROPERTY(VisibleAnywhere, Category = "My Pawn Components")//�ɼ� ���ɸ�
	class UCameraComponent* MyCamera;

	UPROPERTY(EditAnywhere, Category = "My Pawn Movement")//�ɼ� �ɸ�
	float MaxSpeed;//�����ٶ�

	FORCEINLINE UStaticMeshComponent* GetUStaticMeshComponent() { return MyStaticMesh; }
	FORCEINLINE USpringArmComponent* GetUSpringArmComponent() { return MySpringArm; }

protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	FVector Velocity;//�ٶ�

	void LookUp(float Value);
	void LookRight(float Value);
	FVector MouseInput;//����ٶ�
};
