// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight():IsMoveRight(true), LocX(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Scene : �����ؼ� ���� ����
	// = : ���� ������(�����ʿ� �ִ°� ���ʿ� �ִ´�.)
	// CreateDefaultSubobject : ���� ����
	// USceneComponent : ������ Ŭ���� ����
	// TEXT("Scene") : �������Ʈ���� ������ �̸�
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	SetRootComponent(Scene); // Scene�� Root Component�� �����.
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform); // StaticMesh�� ��� ��ǥ�� �������� Scene�� ���δ�.
	StaticMesh->SetRelativeTransform(FTransform::Identity); // StaticMesh�� RelativeTransform(������ġ)�� �⺻������ �����Ѵ�.
}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsMoveRight)
	{
		//True
		LocX = LocX + 1; // LocX += 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
		FVector location = StaticMesh->GetRelativeLocation();
		if (location.X > 200) 
		{
			IsMoveRight = false;
		}
	}
	else
	{
		//False
		LocX = LocX - 1; // LocX -= 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
		FVector location = StaticMesh->GetRelativeLocation();
		if (location.X < 0)
		{
			IsMoveRight = true;
		}
	}
}

