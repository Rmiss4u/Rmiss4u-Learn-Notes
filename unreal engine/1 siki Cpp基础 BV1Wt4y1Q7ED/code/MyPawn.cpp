#include "MyPawn.h"
#include "Components/StaticMeshComponent.h"//ע��Ҫ������֮�����ͷ�ļ�
#include "Camera/CameraComponent.h"//Camera������
#include "Components/InputComponent.h"//����ӳ���
#include "GameFramework/SpringArmComponent.h"//SpringArmͷ�ļ�
#include "UObject/ConstructorHelpers.h"//�������������� ��̬��
AMyPawn::AMyPawn()//���캯��
{
	PrimaryActorTick.bCanEverTick = true;

	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));//����Ĭ�ϸ����
	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));//���������̬������
	RootComponent = MyStaticMesh;//��Ϊ�˸���� �ֱ����˿ɱ༭�����
	//MyStaticMesh->SetupAttachment(GetRootComponent());//����ĸ���

	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));//���ڲ���

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset=
		(TEXT("Material'/Game/Models/Materials/NewMaterial.NewMaterial'"));//������̬����
	//��static mesh�����Ҽ� �������� ����·��Ѱ�ҳ�(���ڱ�������û�� ������زĴ���

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MateriaAsset =
		(TEXT("Material'/Game/Models/Materials/NewMaterial.NewMaterial'"));
	//������
	if (StaticMeshAsset.Succeeded() && MateriaAsset.Succeeded()) {//�������ɹ�
		//����ģ�ͺͲ���
		MyStaticMesh->SetStaticMesh(StaticMeshAsset.Object);
		MyStaticMesh->SetMaterial(0, MateriaAsset.Object);
		MyStaticMesh->SetWorldScale3D(FVector(0.5f));//��С0.5
	}

	MySpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MySpringArm"));
	//MySpringArm->SetupAttachment(MyStaticMesh);
	MySpringArm->SetupAttachment(GetUStaticMeshComponent());
	//MySpringArm->RelativeRotation = FRotator(FRotator(-45.0f, 0.0f, 0.0f));//˽���޷��޸� ��Ƶbug
	MySpringArm->TargetArmLength = 400.0f;
	MySpringArm->bEnableCameraLag = true;
	MySpringArm->CameraLagSpeed = 3.0f;


	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
	//MyCamera->SetupAttachment(GetRootComponent());
	//MyCamera->SetupAttachment(MySpringArm);
	MyCamera->SetupAttachment(GetUSpringArmComponent());

	//MyCamera->SetRelativeLocation(FVector(-300.0f,0.0f,300.0f));//�趨����ͷԤ������
	//MyCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));//�趨����ͷԤ������

	AutoPossessPlayer = EAutoReceiveInput::Player0;//��Ϊ0�����
	bUseControllerRotationYaw = true;//����ѡ��
	MaxSpeed = 100.0f;
	Velocity = FVector::ZeroVector;
}
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
}
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(Velocity * DeltaTime, true);//����

	//���������ת����
	FRotator NewSpringArmRotation = MySpringArm->GetComponentRotation();//����
	//x,y,z -> row ,pitch ,yaw
	NewSpringArmRotation.Pitch = FMath::Clamp(NewSpringArmRotation.Pitch += MouseInput.Y, -80.0f, 0.0f);//�ۼ�
	MySpringArm->SetWorldRotation(NewSpringArmRotation);//�޸�rotation

	//���������ת Ҫ�ǵ�controller�ļ̳�
	AddControllerYawInput(MouseInput.X);//bUseControllerRotationYaw = true;//����ѡ��
}
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//�ǵ��������� ���� �������޸�ӳ��
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPawn::MoveForward);//����ӳ�������¼��� ���ݺ�������
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPawn::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyPawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AMyPawn::LookRight);
}

void AMyPawn::MoveForward(float Value)
{
	Velocity.X = FMath::Clamp(Value,-1.0f,1.0f) * MaxSpeed;//������-1~1֮��
}

void AMyPawn::MoveRight(float Value)
{
	Velocity.Y = FMath::Clamp(Value, -1.0f, 1.0f) * MaxSpeed;//������-1~1֮��
}

void AMyPawn::LookUp(float Value)
{
	MouseInput.Y = FMath::Clamp(Value, -1.0f, 1.0f);//������-1~1֮��
}

void AMyPawn::LookRight(float Value)
{
	MouseInput.X = FMath::Clamp(Value, -1.0f, 1.0f);//������-1~1֮��
}

