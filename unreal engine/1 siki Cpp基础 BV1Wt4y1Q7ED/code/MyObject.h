#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"
UCLASS(Blueprintable)//������� ��Ӻ� ���Դ�������...����ͼ��
class CPP3DP_API UMyObject : public UObject
{
	GENERATED_BODY()
public:
	UMyObject();
	//UPROPERTY(BlueprintReadWrite)//��ͼϵͳ�ɶ�д 
	UPROPERTY(BlueprintReadOnly, Category = "My Variables")//��ͼϵͳ�ɶ�д 
	float MyFloat;
	//UFUNCTION(BlueprintCallable)
	UFUNCTION(BlueprintCallable, Category = "My Functions")
	void MyFunction();
};
